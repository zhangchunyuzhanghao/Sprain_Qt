#include "vlc_seek_slider.h"
#include <QDateTime>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

VLC_Seek_Slider::VLC_Seek_Slider(QWidget *parent) : BaseWidget(parent)
{
    initUI();
    retranslateUI();

    connect(m_progressSlider, &QSlider::sliderMoved, [=](int position){
        setCurrentTime(position);
    });
    setTotalTime(5555);
}

VLC_Seek_Slider::~VLC_Seek_Slider()
{

}

void VLC_Seek_Slider::retranslateUI()
{
//    m_currentTime->setText(QStringLiteral("00:00:00"));
//    m_totalTime->setText(QStringLiteral("21:58:40"));
    m_fileName->setText(QStringLiteral("F:\\Videos\\她说专辑.wav"));
}

void VLC_Seek_Slider::initUI()
{
    setFixedHeight(50);

    m_currentTime = new QLabel();
    m_currentTime->setObjectName("currentTime");
    m_totalTime = new QLabel();
    m_totalTime->setObjectName("totalTime");
    m_fileName = new QLabel();
    m_fileName->setObjectName("fileName");
    m_fileName->setAlignment(Qt::AlignHCenter);

    m_progressSlider = new QSlider(Qt::Horizontal, this);
    m_progressSlider->setObjectName("progressSlider");
    m_progressSlider->setMinimum(0);  // 最小值

    // 进度条
    QHBoxLayout *sliderHLayout = new QHBoxLayout();
    sliderHLayout->setContentsMargins(0, 0, 0, 0);
    sliderHLayout->setSpacing(5);
    sliderHLayout->addWidget(m_currentTime);
    sliderHLayout->addWidget(m_progressSlider);
    sliderHLayout->addWidget(m_totalTime);

    QVBoxLayout *sliderVLayout = new QVBoxLayout();
    sliderVLayout->setContentsMargins(0, 0, 0, 0);
    sliderVLayout->addWidget(m_fileName);
    sliderVLayout->addLayout(sliderHLayout);

    setLayout(sliderVLayout);
}

const QString &VLC_Seek_Slider::timestampToTime(qint64 )
{
    QDateTime *currentTime = new QDateTime();
    QString strTime = currentTime->toString(QString("hh:mm:ss"));
    return strTime;
}

void VLC_Seek_Slider::setFileName(const QString fileName)
{
    if(fileName.compare(QStringLiteral("")) != 0)
    {
         m_fileName = fileName;
    }

}

void VLC_Seek_Slider::setCurrentTime(qint64 progress)
{
    m_progressSlider->setValue(progress);
    m_currentTime = timestampToTime(m_progressSlider);
    qDebug()<< "current Time is : " <<progress;
}

void VLC_Seek_Slider::setTotalTime(qint64 totalTime)
{
    m_progressSlider->setMaximum(totalTime);
    if(totalTime != 0)
    {
        m_progressSlider->setRange(0,totalTime);
        m_progressSlider->setEnabled(true);
    }
    else
    {
        m_progressSlider->setRange(0,1);
        m_progressSlider->setEnabled(false);
    }
}
