//
// Created by Влад Кирилов on 05.04.2023.
//

#include "TransformAction.h"

#include <utility>

using std::move;

TransformAction::TransformAction(QString &&iconPath, QString &&name, TransformationMode mode,
                                 Consumer<TransformationMode> setMode) :
        ToolBarAction(std::move(iconPath),std::move(name)), mode(mode),
        setMode(std::move(setMode)) {
    setCheckable(true);
}

void TransformAction::onMouseClicked() {
    setMode(mode);
}
