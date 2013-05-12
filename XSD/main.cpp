#include <QApplication>
#include "xsd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XSD w;
    w.show();
    
    return a.exec();
}
