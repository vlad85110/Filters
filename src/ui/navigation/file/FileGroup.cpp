//
// Created by Влад Кирилов on 03.04.2023.
//

#include "FileGroup.h"
#include "ui/button/file/open/OpenFileAction.h"
#include "ui/button/file/save/SaveFileAction.h"

FileGroup::FileGroup(QObject *parent, Canvas &canvas) : AbstractActionGroup(parent, "File") {
    auto iconPrefix = QString("/Users/vladkirilov/CLionProjects/filters/resources/");
    auto loadFileIconPath = QString("load.png");
    auto loadFileAction = new OpenFileAction(QString(iconPrefix + loadFileIconPath), "Open", canvas);

    auto saveFileIconPath = QString("save.png");
    auto saveFileAction = new SaveFileAction(QString(iconPrefix + saveFileIconPath), "Save", canvas);

    saveFileAction->setEnabled(false);

    addAction(loadFileAction);
    addAction(saveFileAction);
}
