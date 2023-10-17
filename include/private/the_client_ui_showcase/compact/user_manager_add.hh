#pragma once

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

class UserManagerAdd : public QWidget {
  Q_OBJECT

 public:
  UserManagerAdd(QWidget* const parent = nullptr);

  QString fullname() const;
  QString username() const;
  QString password() const;

  bool isAccepted() const;

 private:
  using LayoutType = QVBoxLayout;
  LayoutType* layout() const;

  void generateView();
  void generateLayout();
  void generateFieldsLayout();
  void generateFields();
  void generateAcceptButtons();

  Q_SLOT void onAcceptClicked();
  Q_SLOT void onRejectClicked();

  QGridLayout* fields_layout_ = nullptr;

  QLineEdit* fullname_ = nullptr;
  QLineEdit* username_ = nullptr;
  QLineEdit* password_ = nullptr;

  QPushButton* accept_ = nullptr;
  QPushButton* reject_ = nullptr;
  bool is_accepted_ = false;
};