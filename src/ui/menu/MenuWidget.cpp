//
// Created by Влад Кирилов on 20.03.2023.
//

#include <QRadioButton>
#include <iostream>
#include "MenuWidget.h"

MenuWidget::MenuWidget(ToolBarWidget *widget) {
    auto fileMenu = widget->getFileGroup()->getMenu();
    auto transformMenu = widget->getTransformGroup()->getMenu();
    auto filterMenu = widget->getFilterGroup()->getMenu();
    auto renderingMenu = widget->getRenderingGroup()->getMenu();
    auto resizeMenu = widget->getResizeGroup()->getMenu();
    auto helpMenu = widget->getHelpGroup()->getMenu();


    addMenu(fileMenu);
    addMenu(filterMenu);
    addMenu(renderingMenu);
    addMenu(transformMenu);
    addMenu(resizeMenu);
    addMenu(helpMenu);
}
