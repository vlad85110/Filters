//
// Created by Влад Кирилов on 04.04.2023.
//

#include "HelpGroup.h"
#include "ui/button/about/AboutAction.h"

HelpGroup::HelpGroup(QObject *parent) : AbstractActionGroup(parent, "Help") {
    auto iconPrefix = QString("/Users/vladkirilov/CLionProjects/filters/resources/");
    auto about = new AboutAction(QString(iconPrefix + QString("about.png")));
    addAction(about);
}
