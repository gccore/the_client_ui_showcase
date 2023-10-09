#include <the_client_ui_showcase/choose_view_widget.hh>
//
#include <the_client_ui_showcase/compact/compact_mainwindow.hh>
//
#include <QtWidgets/QSpacerItem>
//
#include <cassert>

ChooseViewWidget::ChooseViewWidget(QWidget* const parent) : QWidget(parent) {
  generateView();
}

void ChooseViewWidget::closeEvent(QCloseEvent* event) {
  this->QWidget::closeEvent(event);

  for (QPointer<QWidget> const& widget : sub_windows_) {
    widget->deleteLater();
  }
}

void ChooseViewWidget::generateView() {
  generateLayout();
  generateGroupBox();
  generateCompactButton();
  generateSpacer();
}
void ChooseViewWidget::generateLayout() {
  QPointer<QVBoxLayout> const layout = new QVBoxLayout;
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
void ChooseViewWidget::generateCompactButton() {
  assert(groupbox_layout_ != nullptr);

  compact_button_ = new QPushButton("Compact View");
  groupbox_layout_->addWidget(compact_button_);

  QObject::connect(compact_button_, &QPushButton::clicked, this,
                   &ChooseViewWidget::onCompactButtonClicked);
}
void ChooseViewWidget::generateSpacer() {
  assert(groupbox_layout_ != nullptr);

  groupbox_layout_->addItem(
      new QSpacerItem(0, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));
}

void ChooseViewWidget::onCompactButtonClicked() {
  sub_windows_.push_back(new CompactMainWindow);
  sub_windows_.back()->show();
}
