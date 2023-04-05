//
// Created by Влад Кирилов on 15.03.2023.
//

#include "MainWindow.h"
#include "ui/navigation/ToolBarWidget.h"
#include "ui/menu/MenuWidget.h"
#include "CentralWidget.h"

#include <QPainter>
#include <QStatusBar>
#include <iostream>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(740, 480);

    auto centralWidget = new CentralWidget(this);
    setCentralWidget(centralWidget);

    auto *navigationWidget = new ToolBarWidget(centralWidget->getCanvas());
    addToolBar(navigationWidget);

    auto *menuWidget = new MenuWidget(navigationWidget);
    setMenuBar(menuWidget);
}


