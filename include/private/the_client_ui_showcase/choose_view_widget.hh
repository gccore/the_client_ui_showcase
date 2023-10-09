#pragma once

#include <QtCore/QEvent>
#include <QtCore/QPointer>
#include <QtCore/QVector>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

class ChooseViewWidget : public QWidget {
  Q_OBJECT

 public:
  ChooseViewWidget(QWidget* const parent = nullptr);

 protected:
  void closeEvent(QCloseEvent* event) override;

 private:
  void generateView();
  void generateLayout();
  void generateGroupBox();
  void generateCompactButton();
  void generateSpacer();

  Q_SLOT void onCompactButtonClicked();

  QPointer<QGroupBox> groupbox_ = nullptr;
  QPointer<QVBoxLayout> groupbox_layout_ = nullptr;
  QPointer<QPushButton> compact_button_ = nullptr;
  QVector<QPointer<QWidget>> sub_windows_;
};