#pragma once

#include <QtCore/QEvent>
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
  void generateRegularCompactButton();
  void generateAdminCompactButton();
  void generateSpacer();

  Q_SLOT void onRegularCompactButtonClicked();
  Q_SLOT void onAdminCompactButtonClicked();

  QGroupBox* groupbox_ = nullptr;
  QVBoxLayout* groupbox_layout_ = nullptr;
  QPushButton* regular_compact_button_ = nullptr;
  QPushButton* admin_compact_button_ = nullptr;
};