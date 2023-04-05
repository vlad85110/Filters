//
// Created by Влад Кирилов on 05.04.2023.
//

#ifndef FILTERS_TRANSFORMGROUP_H
#define FILTERS_TRANSFORMGROUP_H


#include "ui/navigation/AbstractActionGroup.h"
#include "types.h"
#include "ui/button/transform/TransformAction.h"

class TransformGroup : public AbstractActionGroup {
private:
    std::shared_ptr<TransformAction> setFast;
    std::shared_ptr<TransformAction> setSmooth;

public:
    TransformGroup(QObject *parent, const Consumer<Qt::TransformationMode>& setMode);

};


#endif //FILTERS_TRANSFORMGROUP_H
