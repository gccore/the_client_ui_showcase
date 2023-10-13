#pragma once

#include <QtWidgets/QMdiArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QWidget>

class CompactMainWindow : public QWidget {
  Q_OBJECT

 public:
  CompactMainWindow(QWidget* const parent = nullptr);

 private:
  enum RoleKinds {
    RK_Available = Qt::UserRole + 1,
  };
  enum ColumnKinds {
    CK_First = 0,
  };

  void generateView();
  void generateLayout();
  void generateSplitter();
  void generateTreeWidget();
  void generateMainView();

  void configureSamples();
  void configureTreeWidgetSamples();

  Q_SLOT void onItemDoubleClicked(QTreeWidgetItem* item, int column);

  QSplitter* splitter_ = nullptr;
  QTreeWidget* tree_widget_ = nullptr;
  QMdiArea* main_view_ = nullptr;
};