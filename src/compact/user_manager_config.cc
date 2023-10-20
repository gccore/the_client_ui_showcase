#include <the_client_ui_showcase/compact/user_manager_config.hh>
//
#include <cassert>

UserManagerConfig::UserManagerConfig(QWidget* const parent) : QWidget(parent) {
  generateView();
}

void UserManagerConfig::generateView() {
  generateLayout();
  generateNavigator();
  generateAddButton();
  generateEditButton();
}
void UserManagerConfig::generateLayout() {
  auto* const layout = new QVBoxLayout;
  this->QWidget::setLayout(layout);
}
void UserManagerConfig::generateNavigator() {}
void UserManagerConfig::generateAddButton() {}
void UserManagerConfig::generateEditButton() {}