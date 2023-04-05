//
// Created by Влад Кирилов on 03.04.2023.
//

#ifndef FILTERS_OPENFILEACTION_H
#define FILTERS_OPENFILEACTION_H


#include "ui/button/file/FileAction.h"

class OpenFileAction : public FileAction {
public:
    OpenFileAction(QString &&iconPath, QString &&name, Canvas& canvas);

    void onMouseClicked() override;

};


#endif //FILTERS_OPENFILEACTION_H
