/********************************************************************************
** Form generated from reading UI file 'xsd.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XSD_H
#define UI_XSD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XSD
{
public:
    QAction *menu_Content;
    QAction *menu_About;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *xsdfile;
    QPushButton *xsdbrowser;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *outputFolder;
    QPushButton *FolderBrowser;
    QLabel *label_3;
    QLabel *label_4;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QFormLayout *formLayout;
    QCheckBox *GenDoxygen;
    QCheckBox *GenSerialization;
    QCheckBox *checkBox;
    QLabel *label_5;
    QLineEdit *NameSpace;
    QWidget *tab_4;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *cpp_button;
    QRadioButton *cxx_button;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *h_button;
    QRadioButton *hpp_button;
    QRadioButton *hxx_button;
    QPushButton *pushButton;
    QPushButton *exit_button;
    QMenuBar *menuBar;
    QMenu *menuHelp;

    void setupUi(QMainWindow *XSD)
    {
        if (XSD->objectName().isEmpty())
            XSD->setObjectName(QString::fromUtf8("XSD"));
        XSD->resize(731, 518);
        menu_Content = new QAction(XSD);
        menu_Content->setObjectName(QString::fromUtf8("menu_Content"));
        menu_About = new QAction(XSD);
        menu_About->setObjectName(QString::fromUtf8("menu_About"));
        centralWidget = new QWidget(XSD);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 611, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        xsdfile = new QLineEdit(layoutWidget);
        xsdfile->setObjectName(QString::fromUtf8("xsdfile"));

        horizontalLayout->addWidget(xsdfile);

        xsdbrowser = new QPushButton(layoutWidget);
        xsdbrowser->setObjectName(QString::fromUtf8("xsdbrowser"));

        horizontalLayout->addWidget(xsdbrowser);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 50, 611, 56));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        outputFolder = new QLineEdit(layoutWidget1);
        outputFolder->setObjectName(QString::fromUtf8("outputFolder"));

        horizontalLayout_2->addWidget(outputFolder);

        FolderBrowser = new QPushButton(layoutWidget1);
        FolderBrowser->setObjectName(QString::fromUtf8("FolderBrowser"));

        horizontalLayout_2->addWidget(FolderBrowser);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 100, 151, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 100, 151, 21));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 170, 701, 241));
        tabWidget->setAutoFillBackground(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        formLayout = new QFormLayout(tab_3);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        GenDoxygen = new QCheckBox(tab_3);
        GenDoxygen->setObjectName(QString::fromUtf8("GenDoxygen"));

        formLayout->setWidget(0, QFormLayout::LabelRole, GenDoxygen);

        GenSerialization = new QCheckBox(tab_3);
        GenSerialization->setObjectName(QString::fromUtf8("GenSerialization"));

        formLayout->setWidget(0, QFormLayout::FieldRole, GenSerialization);

        checkBox = new QCheckBox(tab_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        formLayout->setWidget(1, QFormLayout::LabelRole, checkBox);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        NameSpace = new QLineEdit(tab_3);
        NameSpace->setObjectName(QString::fromUtf8("NameSpace"));
        NameSpace->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, NameSpace);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 130, 124, 28));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        cpp_button = new QRadioButton(layoutWidget2);
        cpp_button->setObjectName(QString::fromUtf8("cpp_button"));

        horizontalLayout_3->addWidget(cpp_button);

        cxx_button = new QRadioButton(layoutWidget2);
        cxx_button->setObjectName(QString::fromUtf8("cxx_button"));

        horizontalLayout_3->addWidget(cxx_button);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(180, 130, 154, 28));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        h_button = new QRadioButton(layoutWidget3);
        h_button->setObjectName(QString::fromUtf8("h_button"));

        horizontalLayout_4->addWidget(h_button);

        hpp_button = new QRadioButton(layoutWidget3);
        hpp_button->setObjectName(QString::fromUtf8("hpp_button"));

        horizontalLayout_4->addWidget(hpp_button);

        hxx_button = new QRadioButton(layoutWidget3);
        hxx_button->setObjectName(QString::fromUtf8("hxx_button"));

        horizontalLayout_4->addWidget(hxx_button);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 430, 111, 31));
        exit_button = new QPushButton(centralWidget);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setGeometry(QRect(480, 430, 98, 31));
        XSD->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        label_3->raise();
        label_4->raise();
        tabWidget->raise();
        pushButton->raise();
        exit_button->raise();
        menuBar = new QMenuBar(XSD);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 29));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        XSD->setMenuBar(menuBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(menu_Content);
        menuHelp->addAction(menu_About);

        retranslateUi(XSD);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(XSD);
    } // setupUi

    void retranslateUi(QMainWindow *XSD)
    {
        XSD->setWindowTitle(QApplication::translate("XSD", "XSD CodeSynthesis", 0, QApplication::UnicodeUTF8));
        menu_Content->setText(QApplication::translate("XSD", "Content", 0, QApplication::UnicodeUTF8));
        menu_About->setText(QApplication::translate("XSD", "About", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("XSD", "XSD File", 0, QApplication::UnicodeUTF8));
        xsdbrowser->setText(QApplication::translate("XSD", "Browse", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("XSD", "Output Folder", 0, QApplication::UnicodeUTF8));
        FolderBrowser->setText(QApplication::translate("XSD", "Browse", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("XSD", "Source File Suffix", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("XSD", "Header File Suffix", 0, QApplication::UnicodeUTF8));
        GenDoxygen->setText(QApplication::translate("XSD", "Generate Doxygen", 0, QApplication::UnicodeUTF8));
        GenSerialization->setText(QApplication::translate("XSD", "Generate Serialization", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("XSD", "Namespace", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("XSD", "cxx-tree", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("XSD", "cxx-parser", 0, QApplication::UnicodeUTF8));
        cpp_button->setText(QApplication::translate("XSD", "cpp", 0, QApplication::UnicodeUTF8));
        cxx_button->setText(QApplication::translate("XSD", "cxx", 0, QApplication::UnicodeUTF8));
        h_button->setText(QApplication::translate("XSD", "h", 0, QApplication::UnicodeUTF8));
        hpp_button->setText(QApplication::translate("XSD", "hpp", 0, QApplication::UnicodeUTF8));
        hxx_button->setText(QApplication::translate("XSD", "hxx", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("XSD", "Generate Code", 0, QApplication::UnicodeUTF8));
        exit_button->setText(QApplication::translate("XSD", "Exit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("XSD", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XSD: public Ui_XSD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XSD_H
