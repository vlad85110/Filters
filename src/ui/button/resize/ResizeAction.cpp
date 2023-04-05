//
// Created by Влад Кирилов on 22.03.2023.
//

#include "ResizeAction.h"

#include <utility>

ResizeAction::ResizeAction(QString &&iconPath, QString &&name, ImageSizeState state, Consumer<ImageSizeState>  setState)
        : ToolBarAction(std::move(iconPath), std::move(name)),
          state(state), setState(std::move(setState)) {
    setCheckable(true);
}

void ResizeAction::onMouseClicked() {
    setState(state);
}
