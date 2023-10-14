#include <the_client_ui_showcase/compact/compact_mainwindow.hh>
//
#include <the_client_ui_showcase/sample_widget/plot.hh>
//
#include <QtCore/QRandomGenerator>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMdiSubWindow>
#include <QtWidgets/QMessageBox>
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
  auto* const layout = new QVBoxLayout;
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
  tree_widget_->setMaximumWidth(200);
  tree_widget_->setMinimumWidth(200);
  splitter_->addWidget(tree_widget_);

  QObject::connect(tree_widget_, &QTreeWidget::itemDoubleClicked, this,
                   &CompactMainWindow::onItemDoubleClicked);
}
void CompactMainWindow::generateMainView() {
  assert(splitter_ != nullptr);

  main_view_ = new QMdiArea;
  splitter_->addWidget(main_view_);
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

  {
    auto* const novin = new QTreeWidgetItem;
    auto* const novin_1 = new QTreeWidgetItem(novin);
    auto* const novin_2 = new QTreeWidgetItem(novin);
    auto* const novin_3 = new QTreeWidgetItem(novin);

    auto const available_icon = QIcon(":/available.svg");
    auto const unavailable_icon = QIcon(":/unavailable.svg");

    novin->setText(0, "Novin");
    novin_1->setText(0, "Platform 1");
    novin_1->setIcon(0, available_icon);
    novin_1->setToolTip(0, "Available");
    novin_1->setData(0, RK_Available, QVariant(true));

    novin_2->setText(0, "Platform 2");
    novin_2->setIcon(0, available_icon);
    novin_2->setToolTip(0, "Available");
    novin_2->setData(0, RK_Available, QVariant(true));

    novin_3->setText(0, "Platform 3");
    novin_3->setIcon(0, unavailable_icon);
    novin_3->setToolTip(0, "Unavailable");
    novin_3->setData(0, RK_Available, QVariant(false));

    tree_widget_->insertTopLevelItem(tree_widget_->topLevelItemCount(), novin);
  }

  {
    auto* const samavat = new QTreeWidgetItem;
    auto* const samavat_1 = new QTreeWidgetItem(samavat);
    auto* const samavat_2 = new QTreeWidgetItem(samavat);
    auto* const samavat_3 = new QTreeWidgetItem(samavat);
    auto* const samavat_4 = new QTreeWidgetItem(samavat);

    auto const available_icon = QIcon(":/available.svg");
    auto const unavailable_icon = QIcon(":/unavailable.svg");

    samavat->setText(0, "Samavat");

    samavat_1->setText(0, "Platform 1");
    samavat_1->setIcon(0, available_icon);
    samavat_1->setToolTip(0, "Available");
    samavat_1->setData(CK_First, RK_Available, QVariant(true));

    samavat_2->setText(0, "Platform 2");
    samavat_2->setIcon(0, unavailable_icon);
    samavat_2->setToolTip(0, "Unavailable");
    samavat_2->setData(CK_First, RK_Available, QVariant(false));

    samavat_3->setText(0, "Platform 3");
    samavat_3->setIcon(0, unavailable_icon);
    samavat_3->setToolTip(0, "Unavailable");
    samavat_3->setData(CK_First, RK_Available, QVariant(false));

    samavat_4->setText(0, "Platform 4");
    samavat_4->setIcon(0, available_icon);
    samavat_4->setToolTip(0, "Available");
    samavat_4->setData(CK_First, RK_Available, QVariant(true));

    tree_widget_->insertTopLevelItem(tree_widget_->topLevelItemCount(),
                                     samavat);
  }
}

void CompactMainWindow::onItemDoubleClicked(QTreeWidgetItem* item, int column) {
  (void)column;

  assert(main_view_ != nullptr);
  assert(tree_widget_ != nullptr);

  static QTreeWidgetItem* previous_selected_item = nullptr;

  if (item != nullptr && item != previous_selected_item) {
    QVariant const available = item->data(CK_First, RK_Available);

    if (available.isValid()) {
      if (available.toBool()) {
        previous_selected_item = item;
        main_view_->closeAllSubWindows();

        for (int i = 0; i < QRandomGenerator::global()->bounded(1, 5); ++i) {
          auto* const plot = new Plot;
          plot->setMinimumWidth(QRandomGenerator::global()->bounded(300, 600));
          plot->setMinimumHeight(200);
          main_view_->addSubWindow(plot)->show();
        }
        
        main_view_->cascadeSubWindows();
      } else {
        QMessageBox::information(this, "Failed To Open",
                                 "This platform isn't available");
      }
    }
  }
}