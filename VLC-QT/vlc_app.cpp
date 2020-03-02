#include "vlc_app.h"
#include "custom/vlc_seek_slider.h"
#include "custom/vlc_setting.h"
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcessEnvironment>
#include <QDebug>

VLC_App *VLC_App::m_pInstance = Q_NULLPTR;

VLC_App* VLC_App::instance()
{
    return m_pInstance;
}

VLC_App::VLC_App(QWidget *parent) : BaseWidget(parent)
{
    if (Q_NULLPTR != m_pInstance)
    {
        QMessageBox::critical(this,
             QStringLiteral("提示"),
             QStringLiteral("ERenderApp 实例已创建，请直接使用 VLC_App::instance()。"));
        abort();
    }
    m_pInstance = this;


    initUI();
    retranslateUI();

    connect(m_openBtn, &QPushButton::clicked, this, &VLC_App::openFile);
//    connect(this, &VLC_App::newFile, )
}

VLC_App::~VLC_App()
{

}

void VLC_App::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}

void VLC_App::retranslateUI()
{
    m_openBtn->setText(QStringLiteral("打开"));
}

void VLC_App::initUI()
{
    m_openBtn = new QPushButton();
    m_openBtn->setObjectName("openBtn");

    m_screenWidget = new QWidget();
    m_screenWidget->setObjectName("screenWidget");
    m_screenWidget->setContentsMargins(0, 0, 0, 0);
    m_screenWidget->setAutoFillBackground(true);
    m_screenWidget->setPalette(QPalette(Qt::black));

    // 菜单栏
    QHBoxLayout *menuLayout = new QHBoxLayout();
    menuLayout->addWidget(m_openBtn);
    menuLayout->addStretch(1);

    // 进度条
    m_seekSlider = new VLC_Seek_Slider();

    // 工具栏
    m_setting = new VLC_Setting();

    // 显示区布局
    QVBoxLayout *showLayout = new QVBoxLayout();
    showLayout->setContentsMargins(5, 5, 5, 5);
    showLayout->setSpacing(10);
    showLayout->addWidget(m_screenWidget);
    showLayout->addWidget(m_seekSlider);
    showLayout->addWidget(m_setting);

    // 总布局
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addLayout(menuLayout);
    layout->addLayout(showLayout);

    setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

void VLC_App::openFile()
{
    QString desk = QProcessEnvironment::systemEnvironment().value("USERPROFILE")+"\\Desktop";
    const QString fullPath = QFileDialog::getOpenFileName(this,
          tr("Open File"), desk, tr("Audio/Video Files (*.mp4 *.wav)"));
    if(fullPath.compare(QStringLiteral("") != 0))
        emit newFile(fullPath);

}
