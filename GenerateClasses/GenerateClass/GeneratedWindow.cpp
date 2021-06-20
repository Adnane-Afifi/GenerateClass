#include <QtDebug>
#include <iostream>
#include "GeneratedWindow.h"
#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>



GeneratedWindow::GeneratedWindow():QDialog(){
  fixLayoutMainSection();
  fixLayoutLastSection();
  GenerateFileDotH();
  m_dialog.show();
}





void GeneratedWindow::fixLayoutMainSection(){
m_dialog.setFixedHeight(600);
m_dialog.setFixedWidth(400);

m_contain = new QTextEdit;
m_contain->setFixedHeight(400);
m_contain->setFixedWidth(350);
m_contain->setReadOnly(true);


m_vLayout = new QVBoxLayout;
m_vLayout->addWidget(m_contain);
m_dialog.setLayout(m_vLayout);

}




void GeneratedWindow ::fixLayoutLastSection(){
    m_leaveapp = new QPushButton;
    m_leaveapp->setText("Fermer");

   m_vLayout->addWidget(m_leaveapp);

}

void GeneratedWindow::GenerateFileDotH(){
  MainWindow window ;
   QObject::connect((window.getButtonGenerate()),SIGNAL(clicked()),&window,SLOT(m_containt->setText(window.getAuthorName())));
}
