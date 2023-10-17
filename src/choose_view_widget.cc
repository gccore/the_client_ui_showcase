#include <the_client_ui_showcase/choose_view_widget.hh>
//
#include <the_client_ui_showcase/compact/compact_mainwindow.hh>
//
#include <QtWidgets/QApplication>
#include <QtWidgets/QSpacerItem>
//
#include <cassert>

ChooseViewWidget::ChooseViewWidget(QWidget* const parent) : QWidget(parent) {
  generateView();
}

void ChooseViewWidget::closeEvent(QCloseEvent* event) { QApplication::quit(); }

void ChooseViewWidget::generateView() {
  generateLayout();
  generateGroupBox();
  generateRegularCompactButton();
  generateAdminCompactButton();
  generateSpacer();
}
void ChooseViewWidget::generateLayout() {
  QVBoxLayout* const layout = new QVBoxLayout;
  this->QWidget::setLayout(layout);
}
void ChooseViewWidget::generateGroupBox() {
  assert(this->QWidget::layout() != nullptr);

  groupbox_ = new QGroupBox;
  groupbox_->setTitle("Views");
  groupbox_layout_ = new QVBoxLayout;
  groupbox_->setLayout(groupbox_layout_);

  this->QWidget::layout()->addWidget(groupbox_);
}
void ChooseViewWidget::generateRegularCompactButton() {
  assert(groupbox_layout_ != nullptr);

  regular_compact_button_ = new QPushButton("Regular Compact View");
  groupbox_layout_->addWidget(regular_compact_button_);

  QObject::connect(regular_compact_button_, &QPushButton::clicked, this,
                   &ChooseViewWidget::onRegularCompactButtonClicked);
}
void ChooseViewWidget::generateAdminCompactButton() {
  assert(groupbox_layout_ != nullptr);

  admin_compact_button_ = new QPushButton("Admin Compact View");
  groupbox_layout_->addWidget(admin_compact_button_);

  QObject::connect(admin_compact_button_, &QPushButton::clicked, this,
                   &ChooseViewWidget::onAdminCompactButtonClicked);
}
void ChooseViewWidget::generateSpacer() {
  assert(groupbox_layout_ != nullptr);

  groupbox_layout_->addItem(
      new QSpacerItem(0, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));
}

void ChooseViewWidget::onRegularCompactButtonClicked() {
  (new CompactMainWindow(CompactMainWindow::MK_Regular))->show();
}
void ChooseViewWidget::onAdminCompactButtonClicked() {
  (new CompactMainWindow(CompactMainWindow::MK_Admin))->show();
}
