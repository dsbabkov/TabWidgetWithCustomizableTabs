#pragma once

#include <QTabBar>

class TabBarWithCustomizableTabs final: public QTabBar {
    Q_OBJECT
    using QTabBar::QTabBar;
public:
    enum HighlightType {
        NoHighlight,
        Highlight,
    };

private:
    struct TabAttributes {
        HighlightType highlightType = NoHighlight;
    };

public:
    void setTabHighlighted(int tabNumber, HighlightType type);

protected:
    void tabInserted(int index) final;
    void paintEvent(QPaintEvent *event) final;

private:
    std::vector<TabAttributes> tabAttributes_;
};

