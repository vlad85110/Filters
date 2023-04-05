//
// Created by Влад Кирилов on 21.03.2023.
//

#include "RenderingGroup.h"

#include <utility>

RenderingGroup::RenderingGroup(QObject *parent, Runnable showFiltered, Runnable showOriginal) :
        AbstractActionGroup(parent, QString("Rendering")),
        showOriginal(std::move(showOriginal)), showFiltered(std::move(showFiltered)) {

    original = std::make_shared<ToolBarAction>(QString(""), QString("Original"));
    filtered = std::make_shared<ToolBarAction>(QString(""), QString("Filtered"));

    addAction(original.get());
    addAction(filtered.get());

    filtered->setEnabled(false);
    original->setEnabled(false);
    filtered->setCheckable(true);
    original->setCheckable(true);

    connect(original.get(), &QAction::triggered, this, this->showOriginal);
    connect(filtered.get(), &QAction::triggered, this, this->showFiltered);
}

void RenderingGroup::activateActions() const {
    filtered->setEnabled(true);
    original->setEnabled(true);
    filtered->trigger();
}

