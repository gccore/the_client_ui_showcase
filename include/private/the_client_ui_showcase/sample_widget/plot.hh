#pragma once

#include <qcustomplot.h>
//
#include <QtCore/QObject>
#include <QtCore/QSharedPointer>
#include <QtCore/QTimer>
#include <QtWidgets/QWidget>

class Plot : public QCustomPlot {
  Q_OBJECT

 public:
  Plot(QWidget* const parent = nullptr);

 private:
  void generateView();
  void generatePlot();
  void generateGraph();
  void generateTimeTicker();
  void generateCustomPlot();

  Q_SLOT void dataGenerator();

  QCPGraph* graph_1_ = nullptr;
  QCPGraph* graph_2_ = nullptr;
  QSharedPointer<QCPAxisTickerTime> time_ticker_;
  QTimer updater_;
  double last_point_key_ = 0;
};