#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

class UserManagerEdit : public QWidget {
  Q_OBJECT

 public:
  UserManagerEdit(QWidget* const parent = nullptr);

 private:
  using LayoutType = QGridLayout;
  LayoutType* layout() const;

  void generateView();
  void generateLayout();
  void generateUsernameField();

  QLineEdit* username_ = nullptr;
};