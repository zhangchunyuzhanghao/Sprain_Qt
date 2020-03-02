#ifndef VLC_SEEK_SLIDER_H
#define VLC_SEEK_SLIDER_H

#include "basewidget.h"
#include <QLabel>
#include <QSlider>

class VLC_Seek_Slider : public BaseWidget
{
    Q_OBJECT
public:
    explicit VLC_Seek_Slider(QWidget *parent = nullptr);
    ~VLC_Seek_Slider();

protected:
    void retranslateUI() Q_DECL_OVERRIDE;

private:
    void initUI();
    const QString& timestampToTime(qint64);
signals:

public slots:
    void setFileName(const QString fileName);
    void setCurrentTime(qint64 progress);
    void setTotalTime(qint64 totalTime);

private:
    QLabel *m_currentTime;
    QLabel *m_totalTime;
    QLabel *m_fileName;

    QSlider *m_progressSlider;
};

#endif // VLC_SEEK_SLIDER_H
