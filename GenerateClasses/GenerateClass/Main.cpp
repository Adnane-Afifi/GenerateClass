#include <QApplication>
#include <QtWidgets>
#include <MainWindow.h>
#include <GeneratedWindow.h>

int main(int argc, char *argv[])
{
QApplication app(argc,argv);
//MainWindow * main = new MainWindow;
//main->printHelloWorld();
//main->display2();
//main->TEST3();
MainWindow *main = new MainWindow;
return  app.exec();
}
