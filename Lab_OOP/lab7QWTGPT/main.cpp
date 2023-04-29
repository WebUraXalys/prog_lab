// #include <QApplication>
// #include <QWidget>
// #include <qwt_plot.h>
// #include <qwt_plot_curve.h>
// #include <qwt_legend.h>
// #include <qwt_plot_grid.h>
// #include <qwt_symbol.h>
// #include <cmath>

// using namespace std;

// class Graph : public QWidget
// {
// public:
//    Graph(QWidget *parent = nullptr) : QWidget(parent)
//    {
//       setGeometry(100, 100, 500, 400);

//       // Create plot object
//       plot = new QwtPlot(this);
//       plot->setTitle("Plot of x and y values");
//       plot->setCanvasBackground(Qt::white);

//       // Create grid
//       QwtPlotGrid *grid = new QwtPlotGrid();
//       grid->attach(plot);

//       // Create curve
//       curve = new QwtPlotCurve();
//       curve->setTitle("Data");
//       curve->setPen(QPen(Qt::red));
//       curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);

//       // Create symbol
//       QwtSymbol *symbol = new QwtSymbol(QwtSymbol::Ellipse,
//                                         QBrush(Qt::white),
//                                         QPen(Qt::black),
//                                         QSize(8, 8));
//       curve->setSymbol(symbol);

//       // Add data to curve
//       curve->setSamples(x, y, 61);

//       // Add legend
//       QwtLegend *legend = new QwtLegend();
//       plot->insertLegend(legend, QwtPlot::BottomLegend);

//       // Display plot
//       plot->replot();
//    }

// private:
//    QwtPlot *plot;
//    QwtPlotCurve *curve;
//    float x[61], y[61];

// public:
//    void plot_data()
//    {
//       int count = 0;
//       for (float i = -3; i <= 3; i += 0.1)
//       {
//          if(i >= -3 && i < -1.5){
//             y[count] = 2;
//          } else if (i >= -1.5 && i <= 1.5)
//          {
//             y[count] = 4 - (i*i);
//          } else if (i > 1.5 && i <= 3)
//          {
//             y[count] = 2;
//          }
//          x[count] = i;
//          count++;
//       };

//       curve->setSamples(x, y, 61);
//       plot->replot();
//    }
// };

// int main(int argc, char *argv[])
// {
//    QApplication a(argc, argv);

//    // Create graph object
//    Graph graph;

//    // Plot data
//    graph.plot_data();

//    // Show graph
//    graph.show();

//    return a.exec();
// }
