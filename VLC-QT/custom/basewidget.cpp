#include "basewidget.h"
#include <QEvent>
#include <QStyleOption>
#include <QPainter>

BaseWidget::BaseWidget(QWidget *parent) : QWidget(parent)
{

}

BaseWidget::~BaseWidget()
{

}

void BaseWidget::changeEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::LanguageChange:
        retranslateUI();
        break;
    default:
        break;
    }

    QWidget::changeEvent(event);
}

void BaseWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void BaseWidget::retranslateUI()
{

}
