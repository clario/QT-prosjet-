#include <QtGui/QApplication>
#include <QtXml/QDomDocument>

int main(int argc, char *argv[])
{
    QString name = "test";
    QString fileName = "C:/Users/anders/github13-github.com-clario-QT-prosjet-/XML_struct.xml";
    QDomDocument *doc = new QDomDocument(); //Definerer QDom treet
    QFile file(fileName);
    //qDebug() << (file.open(QIODevice::ReadOnly));
    doc->setContent(&file);
    file.close();
    QDomElement root = doc->documentElement();
    qDebug() << root.tagName();
    return 0;
}





