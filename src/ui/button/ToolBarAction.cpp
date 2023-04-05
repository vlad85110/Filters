//
// Created by Влад Кирилов on 15.03.2023.
//

#include "ToolBarAction.h"

#include <QIcon>
#include <iostream>
#include <QSignalMapper>

ToolBarAction::ToolBarAction(QString &&iconPath, QString &&name) : QAction(), name(name) {
    auto *icon = new QIcon(iconPath);
    setText(name);
    setIconVisibleInMenu(true);
    setIcon(*icon);
    setToolTip(name);

    connect(this, &QAction::triggered, this, &ToolBarAction::trig);
}

void ToolBarAction::trig() {
    onMouseClicked();
}

ToolBarAction::~ToolBarAction() = default;
