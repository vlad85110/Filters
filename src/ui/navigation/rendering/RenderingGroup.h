//
// Created by Влад Кирилов on 21.03.2023.
//

#ifndef FILTERS_RENDERINGGROUP_H
#define FILTERS_RENDERINGGROUP_H


#include <QActionGroup>
#include "types.h"
#include "ui/button/ToolBarAction.h"
#include "ui/navigation/AbstractActionGroup.h"

class RenderingGroup : public AbstractActionGroup {
Q_OBJECT
public:
    RenderingGroup(QObject *parent, Runnable showFiltered, Runnable showOriginal);

public slots:
    void activateActions() const;

private:
    std::shared_ptr<ToolBarAction> original, filtered;
    Runnable showFiltered;
    Runnable showOriginal;
};


#endif //FILTERS_RENDERINGGROUP_H
