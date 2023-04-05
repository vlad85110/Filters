//
// Created by Влад Кирилов on 22.03.2023.
//

#ifndef FILTERS_RESIZEACTION_H
#define FILTERS_RESIZEACTION_H


#include <QAction>
#include "canvas/ImageSizeState.h"
#include "ui/button/ToolBarAction.h"
#include "types.h"

class ResizeAction : public ToolBarAction {
private:
    const ImageSizeState state;
    const Consumer<ImageSizeState> setState;
public:
    ResizeAction(QString &&iconPath, QString &&name, ImageSizeState state, Consumer<ImageSizeState>  setState);
    void onMouseClicked() override;
};


#endif //FILTERS_RESIZEACTION_H
