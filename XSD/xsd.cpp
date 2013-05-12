#include "xsd.h"
#include "ui_xsd.h"
#include <QDir>
#include <QFileDialog>
#include <QProcess>
#include <QStringList>
#include <iostream>
#include <QDialog>
#include <QTextStream>
#include <QMessageBox>


XSD::XSD(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XSD),
    m_directory(""),
    m_selectedFile(""),
    m_srcSuffix(".cxx"),
    m_headerSuffix(".hxx"),
    m_commandOptions(""),
    m_xsdCommand(""),
    m_hasNamespace(false)


{
    ui->setupUi(this);
    move(QApplication::desktop()->screen()->rect().center() - this->rect().center());

    connect(ui->menu_About, SIGNAL(triggered()), this, SLOT(actionAbout()));
    connect(ui->menu_Content, SIGNAL(triggered()), this, SLOT(actionContent()));

}

XSD::~XSD()
{
    delete ui;

}


void XSD::on_FolderBrowser_clicked()
{
    m_directory = QFileDialog::getExistingDirectory(this,
                               tr("S"), QDir::currentPath());
    if (NULL != m_directory) {

        ui->outputFolder->insert(m_directory);
    }

}

void XSD::on_xsdbrowser_clicked()
{
    m_selectedFile = QFileDialog::getOpenFileName(this,
                                                     tr("Select XSD"), QDir::currentPath(),tr("*.xsd"));
    if (NULL != m_selectedFile) {

        ui->xsdfile->insert(m_selectedFile);
    }
}


void XSD::on_cpp_button_toggled(bool checked)
{
    if(checked)
        m_srcSuffix = "--cxx-suffix .cpp";
}

void XSD::on_cxx_button_toggled(bool checked)
{
    if(checked)
        m_srcSuffix = "--cxx-suffix .cxx";

}

void XSD::on_h_button_toggled(bool checked)
{
    if(checked)
       m_headerSuffix = "--hxx-suffix .h";

}

void XSD::on_hpp_button_toggled(bool checked)
{
    if(checked)
       m_headerSuffix = "--hxx-suffix .hpp";
}

void XSD::on_hxx_button_toggled(bool checked)
{
    if(checked)
       m_headerSuffix = "--hxx-suffix .hxx";
}


void XSD::on_GenSerialization_toggled(bool checked)
{
    if (checked)
        m_commandOptions << "--generate-serialization";
}

void XSD::on_GenDoxygen_toggled(bool checked)
{
    if (checked)
        m_commandOptions << "--generate-doxygen";
}




void XSD::on_pushButton_clicked()
{
    QProcess XsdCmd;
    QStringList CmdStr;

    /* Set XSD command type cxx-tree or cxx-parser */
    get_xsd_command_type();

    /* Set global namespace if enabled */
    set_namespace();

    CmdStr << "/usr/bin/xsdcxx"
               << m_xsdCommand
               << m_srcSuffix
               << m_headerSuffix
               <<"--output-dir"
               << m_directory
               << m_commandOptions.join(" ")
               << m_selectedFile;

    QString execCmd = CmdStr.join(" ");


    XsdCmd.setProcessChannelMode(QProcess::MergedChannels);


    XsdCmd.start(execCmd);

    XsdCmd.waitForFinished();

    int processExitCode = XsdCmd.exitCode();

    QString errMessage = XsdCmd.readAllStandardOutput();

    display_popup( processExitCode, errMessage );




}

void XSD::get_xsd_command_type()
{
  int pageIndex =  ui->tabWidget->currentIndex();
  m_xsdCommand = ui->tabWidget->tabText(pageIndex);
}

void XSD::on_exit_button_clicked()
{
    exit(0);
}

void XSD::display_popup(int exitcode,QString errMessage  )
{

    QString TextMessage;
    QMessageBox popup;

    if(0 == exitcode) {

        TextMessage = "Code Generated Successfully... \n\n";
        popup.setText(TextMessage);

    } else {

        TextMessage = " Code Generation Failed... \n\n";
        TextMessage += errMessage;
        popup.setText(TextMessage);
    }

    popup.setWindowTitle("Status");
    popup.move(ui->centralWidget->rect().center());

    QAbstractButton *addButton =
                popup.addButton(tr("Ok"), QMessageBox::ActionRole);

        popup.exec();
        if (popup.clickedButton() == addButton)
            exit(0);

}

void XSD::set_namespace()
{

  if(m_hasNamespace) {

    m_commandOptions << "--namespace-map"<<"="+ui->NameSpace->text();
   }
}

void XSD::on_checkBox_toggled(bool checked)
{
  if (checked) {
    ui->NameSpace->setEnabled(true);
    ui->NameSpace->setPlaceholderText("Enter Namespace");
    m_hasNamespace = true;
    }
  else{
     ui->NameSpace->setEnabled(false);
     m_hasNamespace = false;
   }
}

void XSD::actionAbout()
{
  QMessageBox toolInfo;

  toolInfo.move(ui->centralWidget->rect().center());

  toolInfo.setWindowTitle("About Tool");
  toolInfo.setInformativeText(" XSD Code Synthesis\n Version 1.0 \n Author : Ravi Trivedi \n trivedi.ravi13@gmail.com");
  toolInfo.exec();

}

void XSD::actionContent()
{
  QMessageBox helpContent;
  QString textMessage;

  textMessage = "Documentation :\n http://www.codesynthesis.com/projects/xsd/";

  helpContent.move(ui->centralWidget->rect().center());
  helpContent.setWindowTitle("Help");
  helpContent.setText(textMessage);
  helpContent.exec();

}
