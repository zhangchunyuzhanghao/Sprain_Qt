#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include <QFile>
#include <QApplication>
//#include <QDebug>

class CommonHelper
{
public:
    static void setStyle(const QString &style)
    {
        QFile qss(style);
//        qDebug()<< qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};

#endif // COMMONHELPER_H
