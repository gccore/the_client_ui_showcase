#pragma once

#include <QtWidgets/QAction>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QWidget>

class CompactMainWindow : public QWidget {
  Q_OBJECT

 public:
  enum ModeKinds {
    MK_Admin,
    MK_Regular,
  };

  CompactMainWindow(ModeKinds const mode, QWidget* const parent = nullptr);

  ModeKinds mode() const;

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
  void generateMenuBar();
  void generateUserManagerMenu();

  void configureSamples();
  void configureTreeWidgetSamples();

  Q_SLOT void onItemDoubleClicked(QTreeWidgetItem* item, int column);
  Q_SLOT void onUserManagerAddClicked(bool const checked);
  Q_SLOT void onUserManagerEditClicked(bool const checked);
  Q_SLOT void onUserManagerMonitorClicked(bool const checked);

  ModeKinds const mode_;
  QSplitter* splitter_ = nullptr;
  QTreeWidget* tree_widget_ = nullptr;
  QMdiArea* main_view_ = nullptr;
  QMenuBar* admin_menubar_ = nullptr;
  QMenu* user_manager_menu_ = nullptr;
  QAction* user_manager_add_ = nullptr;
  QAction* user_manager_edit_ = nullptr;
  QAction* user_manager_monitor_ = nullptr;
};