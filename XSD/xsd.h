#ifndef XSD_H
#define XSD_H

#include <QMainWindow>
#include <QLineEdit>
#include <QString>
#include <QDesktopWidget>


namespace Ui {
class XSD;
}

class XSD : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit XSD(QWidget *parent = 0);
    ~XSD();
    
private slots:

    void on_FolderBrowser_clicked();

    void on_xsdbrowser_clicked();

    void on_cxx_button_toggled(bool checked);

    void on_cpp_button_toggled(bool checked);

    void on_h_button_toggled(bool checked);

    void on_hpp_button_toggled(bool checked);

    void on_hxx_button_toggled(bool checked);

    void on_pushButton_clicked();

    void on_GenSerialization_toggled(bool checked);

    void on_GenDoxygen_toggled(bool checked);

    void on_exit_button_clicked();  

    void on_checkBox_toggled(bool checked);

    void actionAbout(void);

    void actionContent(void);


private:
    Ui::XSD *ui;
    QString m_directory;
    QString m_selectedFile;
    QString m_srcSuffix;
    QString m_headerSuffix;
    QStringList m_commandOptions;
    QString m_xsdCommand;
    bool m_hasNamespace;

    void set_namespace(void);

    void display_popup(int exitcode, QString errMessage );

    void get_xsd_command_type(void);



};

#endif // XSD_H
