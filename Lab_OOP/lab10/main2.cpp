#include <QApplication>
#include <QMainWindow>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <fstream>
#include <vector>
#include <cmath>
#include <QPen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Створення головного вікна
    QMainWindow window;
    window.setWindowTitle("Qwt Plot Example");

    // Створення об'єкту графіка QwtPlot
    QwtPlot *plot = new QwtPlot(&window);
    plot->setTitle("Теплове розширення Цинку");
    plot->setCanvasBackground(Qt::white);

    // Завантаження експериментальних даних у вектори
    std::vector<double> temp = { 5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 };
    std::vector<double> Zn = {17.891, 19.291, 21.181, 21.295, 24.440, 28.714, 31.269, 33.270, 36.362, 40.607, 43.405, 45.434, 49.713, 52.189, 54.280, 58.574, 60.725 };

    // Використання методу найменших квадратів для знаходження коефіцієнтів a0 і a1
    double N = temp.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < N; i++) {
        sumX += temp[i];
        sumY += Zn[i];
        sumXY += temp[i] * Zn[i];
        sumX2 += temp[i] * temp[i];
    }
    double a1 = (N * sumXY - sumX * sumY) / (N * sumX2 - sumX * sumX);
    double a0 = (sumY - a1 * sumX) / N;

    // Табулювання значень апроксимуючого виразу для вказаного діапазону температур
    std::vector<double> Zn_approx;
    for (int i = 0; i < temp.size(); i++) {
        double t = temp[i];
        double l = a0 + a1 * t;
        Zn_approx.push_back(l);
    }

    // Створення кривої графіка для експериментальних даних
    QwtPlotCurve *curveData = new QwtPlotCurve();
    curveData->setTitle("Experimental Data");
    curveData->setPen(QPen(Qt::blue));
    curveData->setSamples(temp.data(), Zn.data(), temp.size());
    curveData->attach(plot);

    // Створення кривої графіка для апроксимованої лінії
    QwtPlotCurve *curveApprox = new QwtPlotCurve();
    curveApprox->setTitle("Approximation");
    curveApprox->setPen(QPen(Qt::red));
    curveApprox->setSamples(temp.data(), Zn_approx.data(), temp.size());
    curveApprox->attach(plot);

    // Налаштування вісей графіка
    plot->setAxisTitle(QwtPlot::xBottom, "Температура (°C)");
    plot->setAxisTitle(QwtPlot::yLeft, "Роширення "); //Роширення (10^-6/K)

    // Відображення графіка
    plot->replot();

    // Відображення головного вікна
    window.setCentralWidget(plot);
    window.resize(800, 600);
    window.show();

    return a.exec();
}