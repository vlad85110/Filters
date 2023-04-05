//
// Created by Влад Кирилов on 05.04.2023.
//

#ifndef FILTERS_TRANSFORMACTION_H
#define FILTERS_TRANSFORMACTION_H


#include "ui/button/ToolBarAction.h"
#include "types.h"

using Qt::TransformationMode;

class TransformAction : public ToolBarAction {
private:
    const TransformationMode mode;
    const Consumer<TransformationMode> setMode;

public:
    TransformAction(QString &&iconPath, QString &&name, TransformationMode mode, Consumer<TransformationMode> setMode);

    void onMouseClicked() override;

};


#endif //FILTERS_TRANSFORMACTION_H
