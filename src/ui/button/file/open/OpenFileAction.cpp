//
// Created by Влад Кирилов on 03.04.2023.
//

#include <iostream>
#include "OpenFileAction.h"

OpenFileAction::OpenFileAction(QString &&iconPath, QString &&name, Canvas& canvas) :
        FileAction(std::move(iconPath), std::move(name), canvas) {}

void OpenFileAction::onMouseClicked() {
    FileAction::onMouseClicked();
    auto name = QFileDialog::getOpenFileName(nullptr, tr("Save Image File"),
                                              QString(),
                                              tr("Images (*.png *.bmp *.jpeg *.jpg *.gif)"));
    if (name.isEmpty()) return;
    canvas.setFileUrl(name);
}
