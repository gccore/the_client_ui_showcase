#include <the_client_ui_showcase/compact/compact_mainwindow.hh>
//
#include <QtWidgets/QLayout>
#include <QtWidgets/QTreeWidgetItem>
//
#include <cassert>

CompactMainWindow::CompactMainWindow(QWidget* const parent) : QWidget(parent) {
  generateView();
  configureSamples();
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
  splitter_->setStretchFactor(0, 40);
}
void CompactMainWindow::generateMainView() {
  assert(splitter_ != nullptr);

  main_view_ = new QTreeWidget;
  splitter_->addWidget(main_view_);
  splitter_->setStretchFactor(1, 100);
}

void CompactMainWindow::configureSamples() { configureTreeWidgetSamples(); }
void CompactMainWindow::configureTreeWidgetSamples() {
  assert(tree_widget_ != nullptr);

  tree_widget_->setColumnCount(1);
  if (QTreeWidgetItem* const header = tree_widget_->headerItem()) {
    header->setText(0, "Platforms");
  } else {
    tree_widget_->setHeaderLabel("Platforms");
  }

  auto* const novin = new QTreeWidgetItem;
  auto* const novin_1 = new QTreeWidgetItem(novin);
  auto* const novin_2 = new QTreeWidgetItem(novin);
  auto* const novin_3 = new QTreeWidgetItem(novin);

  novin->setText(0, "Novin");
  novin_1->setText(0, "Platform 1");
  novin_2->setText(0, "Platform 2");
  novin_3->setText(0, "Platform 3");

  tree_widget_->insertTopLevelItem(0, novin);
}