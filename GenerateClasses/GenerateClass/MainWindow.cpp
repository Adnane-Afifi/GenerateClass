#include "MainWindow.h"
#include <stdio.h>
#include <QHBoxLayout>
#include <QGridLayout>

MainWindow::MainWindow():QWidget(){
fixSizeWindow();
m_layoutPrincipal = new QVBoxLayout;
fixLayoutSection1();
fixLayoutSection2();

m_fenetre.show();
}

void MainWindow:: printHelloWorld(){
    printf("Hello world ");
}
void MainWindow::fixSizeWindow(){
    m_fenetre.setFixedHeight(700);
    m_fenetre.setFixedWidth(600);
}
void MainWindow::fixLayoutSection1(){
    m_LINameClass = new QLineEdit;
    m_LImotherClass = new QLineEdit;
    m_LINameClass->setFixedWidth(300);
    m_LImotherClass->setFixedWidth(300 );

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("ClassName   :",m_LINameClass);
    formLayout->addRow("motherClass :",m_LImotherClass);

    QGroupBox * groupDefinition = new QGroupBox("Definition de la classe :");
    groupDefinition->setLayout(formLayout);



    m_layoutPrincipal->addWidget(groupDefinition);



    m_fenetre.setLayout(m_layoutPrincipal);
}

void MainWindow::fixLayoutSection2(){
QVBoxLayout *vboxLayout = new QVBoxLayout;
m_CHBX_multipleInclude = new QCheckBox("Protoger le header contre les inclusion multiples",&m_fenetre);
m_CHBX_GenerateConstruct = new QCheckBox("Generer un constructeur par defaut ",&m_fenetre);
m_CHBX_GenerateDestruct = new QCheckBox("Generer un destructeur",&m_fenetre);
vboxLayout->addWidget(m_CHBX_multipleInclude);
vboxLayout->addWidget(m_CHBX_GenerateConstruct);
vboxLayout->addWidget(m_CHBX_GenerateDestruct);
QGroupBox * groupOptions = new QGroupBox("Options :");
groupOptions->setLayout(vboxLayout);
m_layoutPrincipal->addWidget(groupOptions);
m_fenetre.setLayout(m_layoutPrincipal);

}
