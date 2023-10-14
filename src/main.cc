#include <the_client_ui_showcase/choose_view_widget.hh>
//
#include <QtWidgets/QApplication>

int main(int argc, char** argv) {
  QApplication const app(argc, argv);

  ChooseViewWidget mainwindow;
  mainwindow.setMinimumSize(300, 400);
  mainwindow.show();

  QApplication::exec();
}