#include <the_client_ui_showcase/compact/user_manager_add.hh>
//
#include <the_client_ui_showcase/utility/layout.hh>
//
#include <cassert>

UserManagerAdd::UserManagerAdd(QWidget* const parent) : QWidget(parent) {
  generateView();
}

void UserManagerAdd::generateView() {
  generateLayout();
  generateFields();
  generateAcceptButtons();
}
void UserManagerAdd::generateLayout() {
  auto* const layout = new QHBoxLayout;
  this->QWidget::setLayout(layout);
}
void UserManagerAdd::generateFields() {
  assert(this->QWidget::layout() != nullptr);

  auto* const fullname_label = new QLabel("Full Name: ");
  auto* const username_label = new QLabel("Username: ");
  auto* const password_label = new QLabel("Password: ");

  fullname_ = new QLineEdit;
  username_ = new QLineEdit;
  password_ = new QLineEdit;

  QHBoxLayout* const fullname_layout =
      ::PackWidgetsToLayout<QHBoxLayout>(fullname_label, fullname_);
  QHBoxLayout* const username_layout =
      ::PackWidgetsToLayout<QHBoxLayout>(username_label, username_);
  QHBoxLayout* const password_layout =
      ::PackWidgetsToLayout<QHBoxLayout>(password_label, password_);

  QVBoxLayout* const fields_layout = ::PackLayoutsToLayout<QVBoxLayout>(
      fullname_layout, username_layout, password_layout);

  dynamic_cast<QHBoxLayout*>(this->QWidget::layout())->addLayout(fields_layout);
}
void UserManagerAdd::generateAcceptButtons() {}