/****************************************
* @file    VLC
* @brief   包含了一些常用的枚举值和接口
* @author  ...
* @date    2020/03/02
****************************************/
#ifndef VLC_H
#define VLC_H

#include <QObject>

class VLC : public QObject
{
    Q_OBJECT
public:
    explicit VLC(QObject *parent = nullptr);
    ~VLC();

signals:

public slots:
};

#endif // VLC_H
