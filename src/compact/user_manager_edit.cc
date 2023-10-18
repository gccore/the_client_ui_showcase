#include <the_client_ui_showcase/compact/user_manager_edit.hh>
//
#include <the_client_ui_showcase/compact/user_manager_add.hh>
#include <the_client_ui_showcase/utility/layout.hh>
//
#include <QtWidgets/QSpacerItem>

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
  generateEditSection();
  generateApplyButton();
}
void UserManagerEdit::generateLayout() {
  auto* const layout = new LayoutType;
  this->QWidget::setLayout(layout);
}
void UserManagerEdit::generateUsernameField() {
  auto* const username_label = new QLabel("Username: ");

  username_ = new QLineEdit;
  search_ = new QPushButton;

  username_->setAlignment(Qt::AlignCenter);
  search_->setIcon(QIcon::fromTheme("search"));

  QObject::connect(search_, &QPushButton::clicked, this,
                   &UserManagerEdit::onSearchClicked);

  auto* const username_layout =
      ::PackWidgetsToLayout<QHBoxLayout>(username_label, username_, search_);

  layout()->addLayout(username_layout);
}
void UserManagerEdit::generateEditSection() {
  auto* const group_box = new QGroupBox;
  group_box->setTitle("Edit Section:");

  auto* const group_box_layout = new QHBoxLayout;
  group_box->setLayout(group_box_layout);

  user_manager_add_ = new UserManagerAdd;
  user_manager_add_->QWidget::setEnabled(false);
  user_manager_add_->setAcceptButtonsVisibility(false);
  user_manager_add_->setUsernameEnabled(false);
  group_box_layout->addWidget(user_manager_add_);

  layout()->addWidget(group_box);
}
void UserManagerEdit::generateApplyButton() {
  auto* const apply_layout = new QHBoxLayout;
  apply_ = new QPushButton("Apply");

  QObject::connect(apply_, &QPushButton::clicked, this,
                   &UserManagerEdit::onApplyClicked);

  apply_layout->addSpacerItem(
      new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
  apply_layout->addWidget(apply_);

  layout()->addLayout(apply_layout);
}

void UserManagerEdit::onSearchClicked() {}
void UserManagerEdit::onApplyClicked() {}