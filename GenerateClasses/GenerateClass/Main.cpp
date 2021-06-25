#include <QApplication>
#include <QtWidgets>
#include <MainWindow.h>
#include <GeneratedWindow.h>
#include <QTranslator>

int main(int argc, char *argv[])
{
QApplication app(argc,argv);
//MainWindow * main = new MainWindow;
//main->printHelloWorld();
//main->display2();
//main->TEST3();
QTranslator translator;
translator.load("/Users/adnaneafifi/Documents/GenerateClass/GenerateClasses/GenerateClass/GeneratedWindow_en.qm");
app.installTranslator(&translator);
MainWindow *main = new MainWindow;
main->TEST2();
return  app.exec();
}
