#include <the_client_ui_showcase/compact/user_manager_edit.hh>
//
#include <the_client_ui_showcase/utility/layout.hh>

UserManagerEdit::UserManagerEdit(QWidget* const parent) : QWidget(parent) {
  generateView();
}

UserManagerEdit::LayoutType* UserManagerEdit::layout() const {
  assert(this->QWidget::layout() != nullptr);
  return qobject_cast<LayoutType*>(this->QWidget::layout());
}

void UserManagerEdit::generateView() {
  generateLayout();
  generateUsernameField();
}
void UserManagerEdit::generateLayout() {
  auto* const layout = new LayoutType;
  this->QWidget::setLayout(layout);
}
void UserManagerEdit::generateUsernameField() {
  auto* const username_label = new QLabel("Username: ");
  username_ = new QLineEdit;

  auto* const username_layout =
      ::PackWidgetsToLayout<QHBoxLayout>(username_label, username_);

  layout()->addLayout(username_layout);
}