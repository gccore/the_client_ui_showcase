#include <the_client_ui_showcase/sample_widget/plot.hh>
//
#include <QtCore/QRandomGenerator>
#include <QtGui/QColor>
#include <QtGui/QPen>
//
#include <cassert>

namespace details {
QColor GenerateRandColor() {
  QRandomGenerator* const random = QRandomGenerator::global();
  return QColor(Qt::GlobalColor(random->bounded(Qt::black, Qt::darkYellow)));
}
}  // namespace details

Plot::Plot(QWidget* const parent) : QCustomPlot(parent) { generateView(); }

void Plot::generateView() {
  generatePlot();
  generateGraph();
  generateTimeTicker();
  generateCustomPlot();
}
void Plot::generatePlot() {
  graph_1_ = this->QCustomPlot::addGraph();
  graph_2_ = this->QCustomPlot::addGraph();
}
void Plot::generateGraph() {
  assert(graph_1_ != nullptr && graph_2_ != nullptr);

  graph_1_->setPen(details::GenerateRandColor());
  graph_2_->setPen(details::GenerateRandColor());
}
void Plot::generateTimeTicker() {
  time_ticker_.reset(new QCPAxisTickerTime);
  time_ticker_->setTimeFormat("%h:%m:%s");
}
void Plot::generateCustomPlot() {
  assert(time_ticker_ != nullptr);

  this->QCustomPlot::xAxis->setTicker(time_ticker_);
  this->QCustomPlot::axisRect()->setupFullAxesBox();
  this->QCustomPlot::yAxis->setRange(-1.2, 1.2);

  QObject::connect(this->QCustomPlot::xAxis,
                   QOverload<QCPRange const&>::of(&QCPAxis::rangeChanged),
                   this->QCustomPlot::xAxis2,
                   QOverload<QCPRange const&>::of(&QCPAxis::setRange));
  QObject::connect(this->QCustomPlot::yAxis,
                   QOverload<QCPRange const&>::of(&QCPAxis::rangeChanged),
                   this->QCustomPlot::yAxis2,
                   QOverload<QCPRange const&>::of(&QCPAxis::setRange));

  QObject::connect(&updater_, &QTimer::timeout, this, &Plot::dataGenerator);
  updater_.start(0);
}

void Plot::dataGenerator() {
  static QTime const time_start = QTime::currentTime();
  double key = time_start.msecsTo(QTime::currentTime()) / 1000.0;

  if (key - last_point_key_ > 0.002) {
    graph_1_->addData(key, qSin(key) + std::rand() / (double)RAND_MAX * 1 *
                                           qSin(key / 0.3843));
    graph_2_->addData(key, qCos(key) + std::rand() / (double)RAND_MAX * 0.5 *
                                           qSin(key / 0.4364));
    last_point_key_ = key;
  }

  this->QCustomPlot::xAxis->setRange(key, 8, Qt::AlignRight);
  this->QCustomPlot::replot();
}
