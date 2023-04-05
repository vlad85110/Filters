//
// Created by Влад Кирилов on 22.03.2023.
//

#include "ResizeGroup.h"

ResizeGroup::ResizeGroup(QObject *parent, const Consumer<ImageSizeState> &changeState) :
        AbstractActionGroup(parent, QString("Resize")) {
    auto iconPrefix = QString("/Users/vladkirilov/CLionProjects/filters/resources/");

    auto scaleIconPath = iconPrefix + QString("resizeScaled.png");
    auto showOriginalIconPath = iconPrefix + QString("resizeOriginal.png");

    scale = std::make_shared<ResizeAction>(std::move(scaleIconPath),
                                           QString("Scale"),
                                           ImageSizeState::SCALED, changeState);

    setOriginal = std::make_shared<ResizeAction>(std::move(showOriginalIconPath),
                                                 QString("Original"),
                                                 ImageSizeState::ORIGINAL, changeState);

    setOriginal->setChecked(true);

    addAction(setOriginal.get());
    addAction(scale.get());
}
