#include <iostream>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <cmath>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QPen>

class Myclass
{
public:
    double y, xMin, xMax;
    void func(QwtPlot *plot)
    {
        QwtPlotCurve *curve = new QwtPlotCurve();
        curve->setPen(QPen(Qt::blue));

        QVector<double> xValues, yValues;

        for (double x = xMin; x <= xMax; x += 0.1)
        {
            if (x >= -3 && x < -1.5)
            {
                y = 2;
            }
            else if (x >= -1.5 && x <= 1.5)
            {
               y = 4 - (x*x);
            }
            else if (x > 1.5 && x <= 3)
            {
                y = 2;
            }

            xValues.append(x);
            yValues.append(y);
        }

        curve->setSamples(xValues, yValues);
        curve->attach(plot);
    }
};
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QwtPlot *plot = new QwtPlot();
    plot->setTitle("My Plot");
    plot->setCanvasBackground(Qt::white);
    plot->setAxisTitle(QwtPlot::xBottom, "X Axis");
    plot->setAxisTitle(QwtPlot::yLeft, "Y Axis");
    plot->setAxisScale(QwtPlot::xBottom, -4, 4);

    Myclass obj;
    obj.xMin = -4;
    obj.xMax = 4;
    obj.func(plot);

    plot->resize(600, 400);
    plot->show();

    return app.exec();
}