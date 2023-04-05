//
// Created by Влад Кирилов on 03.04.2023.
//

#ifndef FILTERS_SAVEFILEACTION_H
#define FILTERS_SAVEFILEACTION_H


#include "ui/button/file/FileAction.h"

class SaveFileAction : public FileAction {
public:
    SaveFileAction(QString &&iconPath, QString &&name, Canvas &canvas);

    void onMouseClicked() override;

};


#endif //FILTERS_SAVEFILEACTION_H
