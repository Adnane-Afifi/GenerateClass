#include "MainWindow.h"
#include <stdio.h>
#include <QHBoxLayout>
#include <QGridLayout>

MainWindow::MainWindow():QWidget(){
fixSizeWindow();
m_layoutPrincipal = new QVBoxLayout;
fixLayoutSection1();
fixLayoutSection2();
fixLayoutSection3();

m_fenetre.show();
}

void MainWindow:: printHelloWorld(){
    printf("Hello world ");
}
void MainWindow::fixSizeWindow(){
    m_fenetre.setFixedHeight(900);
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

    groupDefinition->setFixedHeight(200);

    m_layoutPrincipal->addWidget(groupDefinition);



    m_fenetre.setLayout(m_layoutPrincipal);
}

void MainWindow::fixLayoutSection2(){
QGroupBox * groupOptions = new QGroupBox("Options :");
QVBoxLayout *vboxLayout = new QVBoxLayout;
m_CHBX_multipleInclude = new QCheckBox("Protoger le header contre les inclusion multiples",&m_fenetre);
m_CHBX_GenerateConstruct = new QCheckBox("Generer un constructeur par defaut ",&m_fenetre);
m_CHBX_GenerateDestruct = new QCheckBox("Generer un destructeur",&m_fenetre);
m_CHBX_GenerateComment = new QCheckBox("Ajouter des commentaires",&m_fenetre);
vboxLayout->addWidget(m_CHBX_multipleInclude);
vboxLayout->addWidget(m_CHBX_GenerateConstruct);
vboxLayout->addWidget(m_CHBX_GenerateDestruct);
vboxLayout->addWidget(m_CHBX_GenerateComment);
groupOptions->setLayout(vboxLayout);
groupOptions->setFixedHeight(300);
//groupOptions->setFixedHeight(5);
m_layoutPrincipal->addWidget(groupOptions);
m_fenetre.setLayout(m_layoutPrincipal);

}
void MainWindow::fixLayoutSection3(){
 QGroupBox * groupMoreOptions = new QGroupBox("Plus d'options:");
 QFormLayout *formLayoutSection3 = new QFormLayout;
 m_LIAuthor = new QLineEdit;
 m_Date = new QDateEdit;
 m_TeXroleofClasse = new QTextEdit;
 m_TeXroleofClasse->setFixedHeight(200);
 m_TeXroleofClasse->setFixedWidth(300);

 formLayoutSection3->addRow("Auteur du projet",m_LIAuthor);
 m_LIAuthor->setFixedWidth(250);
 formLayoutSection3->addRow("Date de creation",m_Date);
 formLayoutSection3->addRow("Role de la classe ",m_TeXroleofClasse);
 groupMoreOptions->setLayout(formLayoutSection3);
 m_layoutPrincipal->addWidget(groupMoreOptions);
 m_fenetre.setLayout(m_layoutPrincipal);
}
