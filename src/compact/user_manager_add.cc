#include <the_client_ui_showcase/compact/user_manager_add.hh>
//
#include <the_client_ui_showcase/utility/layout.hh>
//
#include <QtWidgets/QSpacerItem>
//
#include <cassert>

UserManagerAdd::UserManagerAdd(QWidget* const parent) : QWidget(parent) {
  generateView();
}

QString UserManagerAdd::fullname() const {
  assert(fullname_ != nullptr);
  return fullname_->text();
}
QString UserManagerAdd::username() const {
  assert(username_ != nullptr);
  return username_->text();
}
QString UserManagerAdd::password() const {
  assert(password_ != nullptr);
  return password_->text();
}

bool UserManagerAdd::isAccepted() const { return is_accepted_; }

UserManagerAdd::LayoutType* UserManagerAdd::layout() const {
  assert(this->QWidget::layout() != nullptr);
  return qobject_cast<LayoutType*>(this->QWidget::layout());
}

void UserManagerAdd::generateView() {
  generateLayout();
  generateFieldsLayout();
  generateFields();
  generateAcceptButtons();
}
void UserManagerAdd::generateLayout() {
  auto* const layout = new QVBoxLayout;

  this->QWidget::setLayout(layout);
}
void UserManagerAdd::generateFieldsLayout() {
  fields_layout_ = new QGridLayout;
  layout()->addLayout(fields_layout_);
}
void UserManagerAdd::generateFields() {
  auto* const fullname_label = new QLabel("Full Name: ");
  auto* const username_label = new QLabel("Username: ");
  auto* const password_label = new QLabel("Password: ");

  fullname_ = new QLineEdit;
  username_ = new QLineEdit;
  password_ = new QLineEdit;

  fields_layout_->addWidget(fullname_label, ::Row<0>, ::Column<0>);
  fields_layout_->addWidget(fullname_, ::Row<0>, ::Column<1>);

  fields_layout_->addWidget(username_label, ::Row<1>, ::Column<0>);
  fields_layout_->addWidget(username_, ::Row<1>, ::Column<1>);

  fields_layout_->addWidget(password_label, ::Row<2>, ::Column<0>);
  fields_layout_->addWidget(password_, ::Row<2>, ::Column<1>);
}
void UserManagerAdd::generateAcceptButtons() {
  accept_ = new QPushButton("Accept");
  reject_ = new QPushButton("Reject");

  QObject::connect(accept_, &QPushButton::clicked, this,
                   &UserManagerAdd::onAcceptClicked);
  QObject::connect(reject_, &QPushButton::clicked, this,
                   &UserManagerAdd::onRejectClicked);

  QHBoxLayout* const button_layout =
      ::PackWidgetsToLayout<QHBoxLayout>(accept_, reject_);

  layout()->addSpacerItem(
      new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout()->addLayout(button_layout);
}

void UserManagerAdd::onAcceptClicked() { is_accepted_ = true; }
void UserManagerAdd::onRejectClicked() { is_accepted_ = false; }