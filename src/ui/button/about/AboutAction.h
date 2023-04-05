//
// Created by Влад Кирилов on 04.04.2023.
//

#ifndef FILTERS_ABOUTACTION_H
#define FILTERS_ABOUTACTION_H


#include "ui/button/ToolBarAction.h"

#include "types.h"

class AboutAction : public ToolBarAction {
private:
    String text;

public:
    explicit AboutAction(QString &&iconPath);

    void onMouseClicked() override;
};


#endif //FILTERS_ABOUTACTION_H
