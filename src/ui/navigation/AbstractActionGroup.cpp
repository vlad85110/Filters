//
// Created by Влад Кирилов on 26.03.2023.
//

#include "AbstractActionGroup.h"

#include <utility>
#include "ui/button/ToolBarAction.h"

AbstractActionGroup::AbstractActionGroup(QObject *parent, QString name) :
        QActionGroup(parent), name(std::move(name)) {}

QMenu *AbstractActionGroup::getMenu() const {
    auto res = new QMenu(name);
    res->addActions(actions());
    return res;
}

AbstractActionGroup::~AbstractActionGroup() {
    for (auto action : actions()) {
        delete action;
    }
}
