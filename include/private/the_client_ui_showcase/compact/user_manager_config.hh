#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

class UserManagerConfig : public QWidget {
  Q_OBJECT

 public:
  UserManagerConfig(QWidget* const parent = nullptr);
  
 private:
  void generateView();
  void generateLayout();
  void generateNavigator();
  void generateAddButton();
  void generateEditButton();
};