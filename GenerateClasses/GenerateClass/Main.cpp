#include <QApplication>
#include <QtWidgets>
#include <MainWindow.h>

int main(int argc, char *argv[])
{
QApplication app(argc,argv);
MainWindow * main = new MainWindow;
main->printHelloWorld();
return  app.exec();
}
