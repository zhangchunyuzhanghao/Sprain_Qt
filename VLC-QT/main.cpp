#include <QApplication>
#include "vlc_config.h"
#include "utils/commonhelper.h"
#include "vlc_app.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName(LVLC_ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(LVLC_ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(LVLC_APPLICATION_NAME);
    QCoreApplication::setApplicationVersion(LVLC_APPLICATION_VERSION);

    CommonHelper::setStyle(":/qss/black");

    VLC_App *vlcApp = new VLC_App();
    vlcApp->resize(900, 600);
    vlcApp->show();

    QObject::connect(&app, &QApplication::lastWindowClosed, &app, &QApplication::quit);

    int retVal = app.exec();
    delete vlcApp;
    return retVal;
}
