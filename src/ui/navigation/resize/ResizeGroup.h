//
// Created by Влад Кирилов on 22.03.2023.
//

#ifndef FILTERS_RESIZEGROUP_H
#define FILTERS_RESIZEGROUP_H


#include <QActionGroup>
#include "types.h"
#include "ui/button/resize/ResizeAction.h"
#include "ui/navigation/AbstractActionGroup.h"

class ResizeGroup : public AbstractActionGroup {
private:
    std::shared_ptr<ResizeAction> scale;
    std::shared_ptr<ResizeAction> setOriginal;

public:
    explicit ResizeGroup(QObject *parent, const Consumer<ImageSizeState>& changeState);
};


#endif //FILTERS_RESIZEGROUP_H
