#include "vlc_setting.h"
#include <QHBoxLayout>

VLC_Setting::VLC_Setting(QWidget *parent) : BaseWidget(parent)
{
    initUI();
    retranslateUI();
}

VLC_Setting::~VLC_Setting()
{

}

void VLC_Setting::retranslateUI()
{
    m_pauseBtn->setText(QStringLiteral("暂停"));
    m_stopBtn->setText(QStringLiteral("停止"));
    m_silenceBtn->setText(QStringLiteral("静音"));
    m_currentVolume->setText(QStringLiteral("80%"));
}

void VLC_Setting::initUI()
{
    setFixedHeight(30);

    m_pauseBtn = new QPushButton();
    m_pauseBtn->setObjectName("pauseBtn");
    m_stopBtn = new QPushButton();
    m_stopBtn->setObjectName("stopBtn");
    m_silenceBtn = new QPushButton();
    m_silenceBtn->setObjectName("silenceBtn");

    m_currentVolume = new QLabel();
    m_currentVolume->setObjectName("currentVolume");

    m_volumeSlider = new QSlider(Qt::Horizontal, this);
    m_volumeSlider->setObjectName("volumeSlider");

    // 工具栏
    QHBoxLayout *toolLayout = new QHBoxLayout();
    toolLayout->setContentsMargins(0, 0, 0, 0);
    toolLayout->setSpacing(10);
    toolLayout->addWidget(m_pauseBtn);
    toolLayout->addWidget(m_stopBtn);
    toolLayout->addStretch(1);
    toolLayout->addWidget(m_silenceBtn);
    toolLayout->addWidget(m_volumeSlider);
    toolLayout->addWidget(m_currentVolume);

    setLayout(toolLayout);
}
