#include <the_client_ui_showcase/compact/user_manager_add.hh>
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
}
void UserManagerAdd::generateAcceptButtons() {}