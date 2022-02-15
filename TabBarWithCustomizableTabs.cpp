#include "TabBarWithCustomizableTabs.h"
#include <QStylePainter>
#include <QStyleOptionTab>
#include <QDebug>

void TabBarWithCustomizableTabs::tabInserted(int index) {
    tabAttributes_.emplace(tabAttributes_.cbegin() + index);
    QTabBar::tabInserted(index);
}

void TabBarWithCustomizableTabs::paintEvent(QPaintEvent *event) {
    QStylePainter painter(this);
    QStyleOptionTab opt;

    for(int i = 0; i < count();i++) {
        initStyleOption(&opt, i);
        const auto &attributes = tabAttributes_[i];
        if (attributes.highlightType == Highlight) {
            QLinearGradient gradient (0, 0, 10, 10);
            gradient.setColorAt(0, QColor("#80FF80"));
            gradient.setColorAt(1, QColor("#00b700"));
            QLinearGradient gradient2 (0, 0, 1, 1);
            gradient.setColorAt(0, QColor("#FF8080"));
            gradient.setColorAt(1, QColor("#b78000"));

            opt.palette.setColor(QPalette::Button, Qt::green); // фон таба
//            opt.palette.setBrush(QPalette::Button, gradient); // фон таба
//            opt.palette.setColor(QPaletteWindow, Qt::green); // Рамка таба
            opt.palette.setColor(QPalette::ColorRole::WindowText, Qt::blue); // Цвет подписей
//            opt.palette.setBrush(QPalette::ColorRole::WindowText, gradient2); // Цвет подписей
        }
        painter.drawControl(QStyle::CE_TabBarTab, opt);
    }
}

void TabBarWithCustomizableTabs::setTabHighlighted(int tabNumber, TabBarWithCustomizableTabs::HighlightType type) {
    if (tabNumber < 0) {
        qCritical() << "Unable to set tab highlight because it is negative. Tab number:" << tabNumber;
        return;
    }

    if (tabNumber >= tabAttributes_.size()) {
        qCritical() << "Unable to set tab highlight because it is greater or equal to tab count. Tab number:"
        << tabNumber << "Tab count:" << tabAttributes_.size();
        return;
    }
    auto &attributes = tabAttributes_[tabNumber];
    if (attributes.highlightType == type) {
        return;
    }

    attributes.highlightType = type;
    update();
}
