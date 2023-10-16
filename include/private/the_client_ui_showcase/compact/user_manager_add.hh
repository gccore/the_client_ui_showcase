#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

class UserManagerAdd : public QWidget {
  Q_OBJECT

 public:
  UserManagerAdd(QWidget* const parent = nullptr);

 private:
  void generateView();
  void generateLayout();
  void generateFields();
  void generateAcceptButtons();

  QLineEdit* fullname_ = nullptr;
  QLineEdit* username_ = nullptr;
  QLineEdit* password_ = nullptr;

  QPushButton* accept_ = nullptr;
  QPushButton* reject_ = nullptr;
};