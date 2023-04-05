//
// Created by Влад Кирилов on 03.04.2023.
//

#include "SaveFileAction.h"

SaveFileAction::SaveFileAction(QString &&iconPath, QString &&name, Canvas &canvas) :
        FileAction(std::move(iconPath), std::move(name), canvas) {}

void SaveFileAction::onMouseClicked() {
    FileAction::onMouseClicked();
    auto name = QFileDialog::getSaveFileName(nullptr, tr("Save Image File"),
                                              QString("*.png"),
                                              tr("Images (*.png)"));
    if (name.isEmpty()) return;
    auto image = canvas.getCurrentImage();
    image.save(name);

}
