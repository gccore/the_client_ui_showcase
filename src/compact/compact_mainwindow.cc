#include <the_client_ui_showcase/compact/compact_mainwindow.hh>
//
#include <QtWidgets/QLayout>
//
#include <cassert>

CompactMainWindow::CompactMainWindow(QWidget* const parent) : QWidget(parent) {
  generateView();
}

void CompactMainWindow::generateView() {
  generateLayout();
  generateSplitter();
  generateTreeWidget();
  generateMainView();
}
void CompactMainWindow::generateLayout() {
  QPointer<QVBoxLayout> const layout = new QVBoxLayout;
  this->QWidget::setLayout(layout);
}
void CompactMainWindow::generateSplitter() {
  assert(this->QWidget::layout() != nullptr);

  splitter_ = new QSplitter;
  this->QWidget::layout()->addWidget(splitter_);
}
void CompactMainWindow::generateTreeWidget() {
  assert(splitter_ != nullptr);

  tree_widget_ = new QTreeWidget;
  splitter_->addWidget(tree_widget_);
  splitter_->setStretchFactor(0, 30);
}
void CompactMainWindow::generateMainView() {
  assert(splitter_ != nullptr);

  main_view_ = new QTreeWidget;
  splitter_->addWidget(main_view_);
  splitter_->setStretchFactor(1, 100);
}