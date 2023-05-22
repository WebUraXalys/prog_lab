#include <iostream>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <cmath>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QPen>

#define pi 3.141592

struct dataN
{
   int N ;
   float T ;
   float h ;
   double w ;
};

double s(float t)
{
    float T = 0.02;


    if (t == 0){
        return 0;
    }
    if ((t > 0) && (t <= 0.8 * T)){
        return 7 * t / (0.8 * T);
    }
    if ((t > 0.8 * T) && (t <= T))
        return 7 - 28 * (t - 0.8 * T) / (0.8 * T);
    if (t == T)
        return 0;

    return 0;
}

double ak(int k) {
    double T = 0.02;
    double w = 2 * pi / T;
    double h = 0.02 / 200;
    double sum = 0;
    for (int i = 0; i <= 200; i++) {
        double t = i * h;
        double l = s(t);
        sum += l * cos(k * w * t) * h;
    }
    return 2.0 / T * sum;
}

double bk(int k) {
    double T = 0.02;
    double w = 2 * pi / T;
    double h = 0.02 / 200;
    double sum = 0;
    for (int i = 0; i <= 200; i++) {
        double t = i * h;
        double l = s(t);
        sum += l * sin(k * w * t) * h;
    }
    return 2.0 / T * sum;
}

double a0() {
    double T = 0.02;
    double h = T / 1000.0;
    double a = 0.0;
    for (int j = 0; j <= 1000; j++) {
        double t = j * h;
        a += s(t) * h;
    }
    return 2.0 / T * a;
}

void tab() {
    QFile file("result.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    int N = 200;
    double h = 0.02 / N;
    for (int i = 0; i <= N; i++) {
        double t = i * h;
        double l = s(i * h);
        out << t << " " << l << "\n";
    }
    file.close();
}

void signal() {
    QFile file("file.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    int N = 5;
    double k = 1.10;
    double T = 0.02;
    double w = 2 * pi / T;
    for (int i = 0; i <= N; i++) {
        double ak_val = ak(i);
        double bk_val = bk(i);
        double a0_val = a0();
        double c_k = sqrt(pow(ak_val, 2) + pow(bk_val, 2));
        if (i == k / w) {
            ak_val = 0.0;
            bk_val = 2.5;
            c_k = bk_val;
        }
        out << i << " " << ak_val << " " << bk_val << " " << c_k << "\n";
    }
    file.close();
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QwtPlot *plot = new QwtPlot;
    plot->setTitle("Signal");
    plot->setAxisTitle(QwtPlot::xBottom, "t");
    plot->setAxisTitle(QwtPlot::yLeft, "s(t)");
    plot->setCanvasBackground(Qt::white);
    QwtPlotCurve *curve = new QwtPlotCurve;
    curve->setTitle("s(t)");
    curve->setPen(QPen(Qt::red));
    QVector<QPointF> points;
    int N = 200;
    double h = 0.02 / N;
    for (int i = 0; i <= N; i++) {
        double t = i * h;
        double sum = a0() / 2;
        for (int j = 1; j <= 5; j++) {
            double ak_val = ak(j);
            double bk_val = bk(j);
            double w = 2 * pi / 0.02;
            double term = ak_val * cos(j * w * t) + bk_val * sin(j * w * t);
            sum += term;
        }
        points.append(QPointF(t, sum));
    }
    curve->setSamples(points);

    curve->attach(plot);
    plot->replot();
    plot->show();
    signal();
    return app.exec();
}