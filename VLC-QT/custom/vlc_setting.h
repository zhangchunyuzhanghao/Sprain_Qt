#ifndef VLC_SETTING_H
#define VLC_SETTING_H

#include "basewidget.h"
#include <QPushButton>
#include <QSlider>
#include <QLabel>

class VLC_Setting : public BaseWidget
{
    Q_OBJECT
public:
    explicit VLC_Setting(QWidget *parent = nullptr);
    ~VLC_Setting();

protected:
    void retranslateUI() Q_DECL_OVERRIDE;

private:
    void initUI();
signals:

public slots:
private:
    QPushButton *m_pauseBtn;
    QPushButton *m_stopBtn;
    QPushButton *m_silenceBtn;
    QSlider *m_volumeSlider;
    QLabel *m_currentVolume;
};

#endif // VLC_SETTING_H
