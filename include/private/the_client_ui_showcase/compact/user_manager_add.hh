#pragma once

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

class UserManagerAdd : public QWidget {
  Q_OBJECT

 public:
  UserManagerAdd(QWidget* const parent = nullptr);

  void setAcceptButtonsVisibility(bool const visible);

  QString fullname() const;
  QString username() const;
  QString password() const;

  bool isAccepted() const;

  bool hasNovinPermission() const;
  bool hasSamavatPermission() const;
  bool hasScanPermission() const;
  bool hasLocalStoragePermission() const;

 private:
  using LayoutType = QVBoxLayout;
  LayoutType* layout() const;

  void generateView();
  void generateLayout();
  void generateFieldsLayout();
  void generateFields();
  void generatePermsLayout();
  void generatePerms();
  void generateAcceptButtons();

  Q_SLOT void onAcceptClicked();
  Q_SLOT void onRejectClicked();

  QGridLayout* fields_layout_ = nullptr;

  QLineEdit* fullname_ = nullptr;
  QLineEdit* username_ = nullptr;
  QLineEdit* password_ = nullptr;

  QGridLayout* perms_layout_ = nullptr;

  QCheckBox* novin_perm_ = nullptr;
  QCheckBox* samavat_perm_ = nullptr;
  QCheckBox* scan_perm_ = nullptr;
  QCheckBox* local_storage_perm_ = nullptr;

  QPushButton* accept_ = nullptr;
  QPushButton* reject_ = nullptr;
  bool is_accepted_ = false;
};