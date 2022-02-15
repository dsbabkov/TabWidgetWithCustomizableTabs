#pragma once

#include <QTabWidget>
#include "TabBarWithCustomizableTabs.h"

class TabWidget final: public QTabWidget {
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent = nullptr);
    void setTabHighlighted(QWidget *tab, TabBarWithCustomizableTabs::HighlightType type);
    void setTabHighlighted(int tabNumber, TabBarWithCustomizableTabs::HighlightType type);
};
