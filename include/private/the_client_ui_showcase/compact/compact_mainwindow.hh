#pragma once

#include <QtCore/QPointer>
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

  QPointer<QSplitter> splitter_ = nullptr;
  QPointer<QTreeWidget> tree_widget_ = nullptr;
  QPointer<QTreeWidget> main_view_ = nullptr;
};