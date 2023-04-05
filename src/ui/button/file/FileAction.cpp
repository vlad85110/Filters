//
// Created by Влад Кирилов on 03.04.2023.
//

#include "FileAction.h"
#include "canvas/Canvas.h"

#include <QFileDialog>

FileAction::FileAction(QString &&iconPath, QString &&name, Canvas &canvas) :
        ToolBarAction(std::move(iconPath), std::move(name)), canvas(canvas) {}

void FileAction::onMouseClicked() {
}
