#include "TabWidget.h"
#include "TabBarWithCustomizableTabs.h"
#include <QDebug>

TabWidget::TabWidget(QWidget *parent)
        : QTabWidget(parent) {
    setTabBar(new TabBarWithCustomizableTabs(this));
}

void TabWidget::setTabHighlighted(int tabNumber, TabBarWithCustomizableTabs::HighlightType type) {
    auto *bar = dynamic_cast<TabBarWithCustomizableTabs *>(tabBar());
    if (!bar) {
        qCritical() << "Tab bar does not support tab highlighting";
        return;
    }
    bar->setTabHighlighted(tabNumber, type);
}

void TabWidget::setTabHighlighted(QWidget *tab, TabBarWithCustomizableTabs::HighlightType type) {
    const auto index = indexOf(tab);
    if (index < 0) {
        qCritical() << "No tab found to set it highlight. Tab widget to search:" << tab;
        return;
    }

    setTabHighlighted(index, type);
}
