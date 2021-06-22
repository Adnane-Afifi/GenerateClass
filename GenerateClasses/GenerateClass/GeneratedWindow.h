#ifndef GENERATEDWINDOW_H
#define GENERATEDWINDOW_H
#include <QDialog>
#include <QtWidgets>
 class GeneratedWindow : public QDialog {
     Q_OBJECT
private:
    QVBoxLayout * m_vLayout ;
    QDialog   m_dialog;
    QTextEdit  * m_contain;
    QPushButton * m_leaveapp;
public:
    GeneratedWindow(QString &code , QWidget * parent=0);
    void DisplayName();
    void fixLayoutMainSection();
    void fixLayoutLastSection();
    QTextEdit * getContain();
    void CloseWindow();

};
#endif // GENERATEDWINDOW_H
