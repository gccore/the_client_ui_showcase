#include <the_client_ui_showcase/compact/user_manager_config.hh>
//
#include <the_client_ui_showcase/compact/user_manager_add.hh>
#include <the_client_ui_showcase/compact/user_manager_edit.hh>
#include <the_client_ui_showcase/utility/layout.hh>
//
#include <QtCore/QSignalBlocker>
#include <QtWidgets/QGroupBox>
//
#include <cassert>

UserManagerConfig::UserManagerConfig(QWidget* const parent) : QWidget(parent) {
  generateView();
}

UserManagerConfig::LayoutType* UserManagerConfig::layout() const {
  assert(this->QWidget::layout() != nullptr);
  return qobject_cast<LayoutType*>(this->QWidget::layout());
}

void UserManagerConfig::generateView() {
  generateLayout();
  generateStackedWidget();
  generateNavigator();
  generateAddButton();
  generateEditButton();
  configStackedWidget();
}
void UserManagerConfig::generateLayout() {
  auto* const layout = new LayoutType;
  this->QWidget::setLayout(layout);
}
void UserManagerConfig::generateStackedWidget() {
  stacked_widget_ = new QStackedWidget;
  nav_button_group_ = new QButtonGroup;

  nav_button_group_->setExclusive(true);

  auto* const group_box = new QGroupBox;
  auto* const group_box_layout = new QHBoxLayout;

  group_box_layout->setMargin(0);
  group_box->setLayout(group_box_layout);
  group_box_layout->addWidget(stacked_widget_);
  stacked_widget_->setSizePolicy(QSizePolicy::Expanding,
                                 QSizePolicy::Expanding);
  group_box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  layout()->addWidget(group_box, ::Row<0>, ::Column<0>, Qt::AlignTop);
}
void UserManagerConfig::generateNavigator() {
  nav_layout_ = new QHBoxLayout;

  layout()->addLayout(nav_layout_, ::Row<1>, ::Column<0>, Qt::AlignBottom);
}
void UserManagerConfig::generateAddButton() {
  assert(nav_layout_ != nullptr);
  assert(stacked_widget_ != nullptr);
  assert(nav_button_group_ != nullptr);

  user_manager_add_ = new UserManagerAdd;
  stacked_widget_->addWidget(user_manager_add_);

  add_button_ = new QPushButton("Add");
  add_button_->setCheckable(true);
  add_button_->setChecked(true);
  nav_button_group_->addButton(add_button_);
  nav_layout_->addWidget(add_button_);

  QObject::connect(add_button_, &QPushButton::clicked, this,
                   &UserManagerConfig::onAddClicked);
}
void UserManagerConfig::generateEditButton() {
  assert(nav_layout_ != nullptr);
  assert(stacked_widget_ != nullptr);
  assert(nav_button_group_ != nullptr);

  user_manager_edit_ = new UserManagerEdit;
  stacked_widget_->addWidget(user_manager_edit_);

  edit_button_ = new QPushButton("Edit");
  edit_button_->setCheckable(true);
  edit_button_->setChecked(false);
  nav_button_group_->addButton(edit_button_);
  nav_layout_->addWidget(edit_button_);

  QObject::connect(edit_button_, &QPushButton::clicked, this,
                   &UserManagerConfig::onEditClicked);
}
void UserManagerConfig::configStackedWidget() {
  assert(stacked_widget_ != nullptr);

  stacked_widget_->setCurrentIndex(::Index<0>);
}

void UserManagerConfig::onAddClicked(bool const checked) {
  Q_UNUSED(checked);

  assert(stacked_widget_ != nullptr);

  stacked_widget_->setCurrentIndex(::Index<0>);
}
void UserManagerConfig::onEditClicked(bool const checked) {
  Q_UNUSED(checked);

  assert(stacked_widget_ != nullptr);

  stacked_widget_->setCurrentIndex(::Index<1>);
}
