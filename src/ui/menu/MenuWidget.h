//
// Created by Влад Кирилов on 20.03.2023.
//

#ifndef FILTERS_MENUWIDGET_H
#define FILTERS_MENUWIDGET_H

#include <QMenuBar>
#include "ui/navigation/ToolBarWidget.h"

class MenuWidget : public QMenuBar {
Q_OBJECT
public:
    explicit MenuWidget(ToolBarWidget* widget);
};


#endif //FILTERS_MENUWIDGET_H
