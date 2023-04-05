//
// Created by Влад Кирилов on 05.04.2023.
//

#include "TransformGroup.h"

TransformGroup::TransformGroup(QObject *parent, const Consumer<Qt::TransformationMode> &setMode) :
        AbstractActionGroup(parent, "Transform") {
    auto iconPrefix = QString("/Users/vladkirilov/CLionProjects/filters/resources/");

    setFast = std::make_shared<TransformAction>(QString(iconPrefix + "fast.png"), "Fast",
                                                Qt::TransformationMode::FastTransformation, setMode);

    setSmooth = std::make_shared<TransformAction>(QString(iconPrefix + "bilinear.png"), "Bilinear",
                                                Qt::TransformationMode::SmoothTransformation, setMode);

    setSmooth->setChecked(true);

    addAction(setSmooth.get());
    addAction(setFast.get());
}
