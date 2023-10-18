#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

class UserManagerAdd;

class UserManagerEdit : public QWidget {
  Q_OBJECT

 public:
  UserManagerEdit(QWidget* const parent = nullptr);

 private:
  using LayoutType = QVBoxLayout;
  LayoutType* layout() const;

  void generateView();
  void generateLayout();
  void generateUsernameField();
  void generateEditSection();
  void generateApplyButton();

  Q_SLOT void onSearchClicked();
  Q_SLOT void onApplyClicked();

  QLineEdit* username_ = nullptr;
  QPushButton* search_ = nullptr;
  UserManagerAdd* user_manager_add_ = nullptr;
  QPushButton* apply_ = nullptr;
};