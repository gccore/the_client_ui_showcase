#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

class UserManagerAdd;
class UserManagerEdit;

class UserManagerConfig : public QWidget {
  Q_OBJECT

 public:
  UserManagerConfig(QWidget* const parent = nullptr);

 private:
  using LayoutType = QGridLayout;
  LayoutType* layout() const;

  void generateView();
  void generateLayout();
  void generateStackedWidget();
  void generateNavigator();
  void generateAddButton();
  void generateEditButton();
  void configStackedWidget();

  Q_SLOT void onAddClicked(bool const checked);
  Q_SLOT void onEditClicked(bool const checked);

  QStackedWidget* stacked_widget_ = nullptr;
  QButtonGroup* nav_button_group_ = nullptr;
  QHBoxLayout* nav_layout_ = nullptr;
  QPushButton* add_button_ = nullptr;
  QPushButton* edit_button_ = nullptr;
  UserManagerAdd* user_manager_add_ = nullptr;
  UserManagerEdit* user_manager_edit_ = nullptr;
};