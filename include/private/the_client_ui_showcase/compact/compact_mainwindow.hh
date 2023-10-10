#pragma once

#include <QtWidgets/QMdiArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

class CompactMainWindow : public QWidget {
  Q_OBJECT

 public:
  CompactMainWindow(QWidget* const parent = nullptr);

 private:
  void generateView();
  void generateLayout();
  void generateSplitter();
  void generateTreeWidget();
  void generateMainView();

  void configureSamples();
  void configureTreeWidgetSamples();

  QSplitter* splitter_ = nullptr;
  QTreeWidget* tree_widget_ = nullptr;
  QMdiArea* main_view_ = nullptr;
};