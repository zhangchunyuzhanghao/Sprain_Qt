#ifndef VLC_APP_H
#define VLC_APP_H

#include "custom/basewidget.h"
#include <QPushButton>
#include <QSlider>
#include <QLabel>

class VLC_Seek_Slider;
class VLC_Setting;

class VLC_App : public BaseWidget
{
    Q_OBJECT
public:
    explicit VLC_App(QWidget *parent = nullptr);
    ~VLC_App();
    static VLC_App *instance();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void retranslateUI() Q_DECL_OVERRIDE;

private:
    void initUI();
signals:
    void newFile(QString filePath);

private slots:
    void openFile();
private:
    static VLC_App *m_pInstance;

    QPushButton *m_openBtn;
    QWidget *m_screenWidget;

    VLC_Seek_Slider *m_seekSlider;
    VLC_Setting *m_setting;
};

#endif // VLC_APP_H
