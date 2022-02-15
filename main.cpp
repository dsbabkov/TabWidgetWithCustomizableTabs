#include "TabWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabWidget w;

    w.addTab(new QWidget(&w), "Hello");
    w.addTab(new QWidget(&w), "World");
    w.addTab(new QWidget(&w), "!");

    w.setTabHighlighted(1, TabBarWithCustomizableTabs::Highlight);

    w.show();

    return a.exec();
}
