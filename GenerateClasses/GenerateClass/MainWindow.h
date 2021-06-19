#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QAbstractButton>
#include <QCheckBox>
class MainWindow : public QWidget {
    /*
     Here i have used some convention :
     m_ : member to the class;
     L : to know that  it is a Label
     B : QPushButton
     LI : QLINE  (TextEdit for single line)
     Te : QTextEdit  (TextEdit for  multiple lines )
     */
    private:
       QWidget m_fenetre;
       QVBoxLayout *m_layoutPrincipal;
       QLabel * m_LSection1_Lclass;
       QLineEdit  * m_LINameClass;
       QLineEdit  * m_LImotherClass;
       QLabel * m_LTSection2_options;
       QCheckBox * m_CHBX_multipleInclude;
       QCheckBox * m_CHBX_GenerateConstruct;
       QCheckBox * m_CHBX_GenerateDestruct;
       QLabel * m_LAddComment;
       QLabel * m_LAuthor;
       QLabel * m_LDate;
       QLabel * m_LroleOfClasse;
       QTextEdit m_TeXroleofClasse;
       QPushButton m_BGenerate;
       QPushButton m_Bleave;
    public:
       MainWindow();
       void printHelloWorld();
       void fixSizeWindow();
       void fixLayoutSection1();
       void fixLayoutSection2();
       void fixLayoutSection3();



};

#endif // MAINWINDOW_H
