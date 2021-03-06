#include "MainWindow.h"
#include <stdio.h>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QtDebug>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QTranslator>
#include "GeneratedWindow.h"
MainWindow::MainWindow():QWidget(){
fixSizeWindow();
m_layoutPrincipal = new QVBoxLayout;
fixLayoutSection1();
fixLayoutSection2();
fixLayoutSection3();
fixLayoutSection5();
fixLayoutSection4();
GenerateAllThecode();
//GenerateHeaders();
CloseWindow();
m_fenetre.show();
}



QPushButton * MainWindow::getButtonGenerate(){
   return m_BGenerate;
}

void MainWindow:: printHelloWorld(){
    printf("Hello world ");
}





void MainWindow::fixSizeWindow(){
    m_fenetre.setFixedHeight(950);
    m_fenetre.setFixedWidth(700);
}



void MainWindow::fixLayoutSection1(){
    QGroupBox * groupDefinition = new QGroupBox(tr("Definition de la classe :"));
    groupDefinition->setFixedHeight(200);


    m_LINameClass = new QLineEdit;
    m_LImotherClass = new QLineEdit;
    m_LINameClass->setFixedWidth(300);
    m_LImotherClass->setFixedWidth(300 );

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("ClassName   :",m_LINameClass);
    formLayout->addRow("motherClass :",m_LImotherClass);

    groupDefinition->setLayout(formLayout);



    m_layoutPrincipal->addWidget(groupDefinition);
    m_fenetre.setLayout(m_layoutPrincipal);
}




void MainWindow::fixLayoutSection2(){
QGroupBox * groupOptions = new QGroupBox(tr("Options :"));
groupOptions->setFixedHeight(300);

QVBoxLayout *vboxLayout = new QVBoxLayout;
m_CHBX_multipleInclude = new QCheckBox(tr("Protoger le header contre les inclusion multiples"),&m_fenetre);
m_CHBX_GenerateConstruct = new QCheckBox(tr("Generer un constructeur par defaut "),&m_fenetre);
m_CHBX_GenerateDestruct = new QCheckBox(tr("Generer un destructeur"),&m_fenetre);
m_CHBX_GenerateComment = new QCheckBox(tr("Ajouter des commentaires"),&m_fenetre);

vboxLayout->addWidget(m_CHBX_multipleInclude);
vboxLayout->addWidget(m_CHBX_GenerateConstruct);
vboxLayout->addWidget(m_CHBX_GenerateDestruct);
vboxLayout->addWidget(m_CHBX_GenerateComment);

groupOptions->setLayout(vboxLayout);
m_layoutPrincipal->addWidget(groupOptions);
m_fenetre.setLayout(m_layoutPrincipal);

}



void MainWindow::fixLayoutSection3(){
 QGroupBox * groupMoreOptions = new QGroupBox(tr("Plus d'options:"));
 QFormLayout *formLayoutSection3 = new QFormLayout;

 m_LIAuthor = new QLineEdit;
 m_Date = new QDateEdit;
 m_TeXroleofClasse = new QTextEdit;

 m_LIAuthor->setFixedWidth(250);
 m_TeXroleofClasse->setFixedHeight(200);
 m_TeXroleofClasse->setFixedWidth(300);

 formLayoutSection3->addRow("Auteur du projet",m_LIAuthor);
 formLayoutSection3->addRow("Date de creation",m_Date);
 formLayoutSection3->addRow("Role de la classe ",m_TeXroleofClasse);

 groupMoreOptions->setLayout(formLayoutSection3);
 m_layoutPrincipal->addWidget(groupMoreOptions);
 m_fenetre.setLayout(m_layoutPrincipal);
}

void MainWindow:: fixLayoutSection4(){
    QGroupBox *groupButton = new QGroupBox;
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    m_BGenerate = new QPushButton;
    m_BGenerate->setText(tr("Generate"));
    m_Bleave = new QPushButton;
    m_Bleave->setText(tr("Quitter"));


    horizontalLayout->addWidget(m_BGenerate);
    horizontalLayout->addWidget(m_Bleave);

    groupButton->setLayout(horizontalLayout);
    m_layoutPrincipal->addWidget(groupButton);
    m_fenetre.setLayout(m_layoutPrincipal);
}

void MainWindow::fixLayoutSection5(){
    QGroupBox *groupButton = new QGroupBox(tr("Choisir les inclusions :"));
    QVBoxLayout *horizontalLayout = new QVBoxLayout;
    m_LIST_HeaderInclude = new QComboBox;
    m_LIST_HeaderInclude->addItem("iostream");
    m_LIST_HeaderInclude->addItem("string.h");
    m_LIST_HeaderInclude->addItem("cctype");
    m_LIST_HeaderInclude->addItem("vector");
    m_LIST_HeaderInclude->addItem("array");
    m_LIST_HeaderInclude->addItem("map");

    m_IncludeHeader = new QPushButton;
    m_IncludeHeader->setText("Inclure");
    m_IncludeHeader->setFixedWidth(100);







    horizontalLayout->addWidget(m_LIST_HeaderInclude);
    horizontalLayout->addWidget(m_IncludeHeader,Qt::AlignCenter);
    groupButton->setLayout(horizontalLayout);
    m_layoutPrincipal->addWidget(groupButton);
}

QString MainWindow::getClassName(){
    return m_LINameClass->text().toStdString().c_str();
}
QString  MainWindow :: getNameMotherClass(){
    return m_LINameClass->text();
}
QString MainWindow::getAuthorName(){
    return m_LIAuthor->text().toStdString().c_str();
}
QString MainWindow::getCreationDate(){
    return m_Date->text().toStdString().c_str();
}

void MainWindow::GenerateSecondWindow(){
     QString  code;
    if(!getAuthorName().isEmpty()){
     code +="Auteur : "+getAuthorName()+"\n";
    }
    if(!getCreationDate().isEmpty()){
      code+="Date de creation : "+getCreationDate()+"\n\n";
    }

    if(m_CHBX_GenerateComment->isChecked()){
       code+="/* "+m_TeXroleofClasse->toPlainText()+" */"+"\n"+"\n"+"\n";
    }
    if(m_CHBX_multipleInclude->isChecked()){
      code+="#ifndef HEADER_"+m_LINameClass->text().toUpper()+"\n";
      code+="#define HEADER_"+m_LINameClass->text().toUpper()+"\n"+"\n"+"\n";
    }
    code+=m_LImotherClass->text()==""?"Class "+m_LINameClass->text()+"\n":"Class " +m_LINameClass->text()+" : public " +m_LImotherClass->text()+"\n";
    code+="{  \n" ;
    if(m_CHBX_GenerateConstruct->isChecked()){
        code+="public: \n";
        code+="\t"+m_LINameClass->text()+"() \n";
    }
    if(m_CHBX_GenerateDestruct->isChecked()){
        code+="\t ~"+m_LINameClass->text();+"() \n";
    }
    code+="\n \n protected :";
    code+="\n \n private :";
    code+="\n \n   }";

    GeneratedWindow *secondWindow = new GeneratedWindow(code,this);

}
//void MainWindow::GenerateHeaders(){
//     QObject::connect(m_IncludeHeader,SIGNAL(clicked()),this,SLOT(setHeader()));
//}
//void MainWindow::setHeader(){
//   code +=m_LIST_HeaderInclude->currentText().toStdString().c_str();
//}


void MainWindow:: CloseWindow(){
    QObject::connect(m_Bleave,SIGNAL(clicked()),qApp,SLOT(quit()));
}
void MainWindow::GenerateAllThecode(){
    QObject::connect(m_BGenerate,SIGNAL(clicked()),this,SLOT(GenerateSecondWindow()));
}

// ================ ================ ================ ================  ================  ================ TESTING...  ================ ================ ================ ================ ================ ================

void MainWindow::TestQEditLine(){
    qDebug()<<getClassName();
    std::cout<<"TEST::::::"<<getAuthorName().toStdString().c_str()<<'\n';
}
void MainWindow::TestQdate(){
    std::cout<<"TEST:::::::"<<getCreationDate().toStdString().c_str()<<'\n';
}
void MainWindow::TestQTextEditLine(){
    std::cout<<"TEST:::::::"<<getAuthorName().toStdString().c_str()<<'\n';
}
void MainWindow::TestCheckbox(){
    if(m_CHBX_GenerateComment->isChecked()){
       std::cout<<"The user need somme comment"<<std::endl;
    }
    if (m_CHBX_GenerateConstruct->isChecked()){
       std::cout<<"The user need a constructeur "<<std::endl;
    }
    if(m_CHBX_GenerateDestruct->isChecked()){
       std::cout<<"The user need a destructuer "<<std::endl;
    }
    if(m_CHBX_multipleInclude->isCheckable()){
       std::cout<<"The user said do not include multiple times"<<std::endl;
    }
    else{
        std::cout<<"The user need nothing . "<<std::endl;
    }
}
void MainWindow::TEST2(){
    QObject::connect(m_BGenerate,SIGNAL(clicked()),this,SLOT(TestQEditLine()));
}
void MainWindow::TEST3(){
    QObject::connect(m_BGenerate,SIGNAL(clicked()),this,SLOT(TestCheckbox()));
}
void MainWindow::TEST4(){
  QObject::connect(m_BGenerate,SIGNAL(clicked()),this,SLOT(TestQdate()));
}
void MainWindow::TEST5(){
  QObject::connect(m_BGenerate,SIGNAL(clicked()),this,SLOT(TestQEditLine()));
}
