//
// Created by Влад Кирилов on 03.04.2023.
//

#ifndef FILTERS_FILEACTION_H
#define FILTERS_FILEACTION_H


#include <QFileDialog>
#include "ui/button/ToolBarAction.h"
#include "canvas/Canvas.h"

class FileAction : public ToolBarAction {
protected:
    Canvas& canvas;
public:
    FileAction(QString &&iconPath, QString &&name, Canvas& canvas);

    void onMouseClicked() override;
};


#endif //FILTERS_FILEACTION_H
