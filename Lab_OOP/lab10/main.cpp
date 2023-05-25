#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCore/QVector>
#include <math.h>

QT_USE_NAMESPACE

    int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a new QMainWindow
    QMainWindow mainWindow;

    // Add a new QChartView widget to the central widget
    QChartView *chartView = new QChartView(&mainWindow);
    mainWindow.setCentralWidget(chartView);

    // Load the experimental data into two QVectors
    QVector<double> temp = { 5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 };
    QVector<double>Pb = {19.254, 21.098, 21.733, 24.346, 27.244, 28.863, 32.637, 34.428, 37.596, 41.723, 44.593, 46.092, 49.966, 53.036, 56.051, 58.531, 62.009 };

    // Use the least-squares method to find the coefficients a0 and a1
    double N = temp.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < N; i++) {
        sumX += temp[i];
        sumY += Pb[i];
        sumXY += temp[i] * Pb[i];
        sumX2 += temp[i] * temp[i];
    }
    double a1 = (N * sumXY - sumX * sumY) / (N * sumX2 - sumX * sumX);
    double a0 = (sumY - a1 * sumX) / N;

    // Tabulate the values of the approximating expression for the specified temperature range
    QVector<double> Pb_approx;
    for (int i = 0; i < temp.size(); i++) {
        double t = temp[i];
        double l = a0 + a1 * t;
        Pb_approx.append(l);
    }

    // Create a new QLineSeries to hold the experimental data
    QLineSeries *seriesData = new QLineSeries();
    for (int i = 0; i < temp.size(); i++) {
        *seriesData << QPointF(temp[i], Pb[i]);
    }

    // Create a new QLineSeries to hold the approximating line
    QLineSeries *seriesApprox = new QLineSeries();
    for (int i = 0; i < temp.size(); i++) {
        *seriesApprox << QPointF(temp[i], Pb_approx[i]);
    }

    // Create a new QScatterSeries to hold the black points
    QScatterSeries *seriesPoints = new QScatterSeries();
    seriesPoints->setMarkerSize(10); // Set the size of the markers
    seriesPoints->setColor(Qt::black); // Set the color of the markers
    for (int i = 0; i < Pb.size(); i++) {
        QScatterSeries *point = new QScatterSeries();
        point->append(temp[i], Pb[i]);
        seriesPoints->append(point->points());
    }


            // Create a new QChart object
            QChart *chart = new QChart();

    // Add the data series to the chart
    chart->addSeries(seriesData);
    chart->addSeries(seriesApprox);
    chart->addSeries(seriesPoints);

    // Set the title and axis labels
    chart->setTitle("Plumbium Thermal Expansion");
    chart->setTitleFont(QFont("Arial", 16));
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->createDefaultAxes();
    chart->axisX()->setTitleText("Temperature (°C)");
    chart->axisY()->setTitleText("Expansion (10^-6/K)");

    // Set the chartview to display the chart
    chartView->setChart(chart);

    // Show the main window
    mainWindow.show();

    return a.exec();
}