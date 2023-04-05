//
// Created by Влад Кирилов on 16.03.2023.
//

#ifndef FILTERS_TOOLBARWIDGET_H
#define FILTERS_TOOLBARWIDGET_H


#include <QWidget>
#include "types.h"
#include <QToolBar>
#include "instrument/Instrument.h"
#include "ui/button/instrument/FilterAction.h"
#include "ui/navigation/filter/FilterGroup.h"
#include "ui/navigation/rendering/RenderingGroup.h"
#include "ui/navigation/resize/ResizeGroup.h"
#include "ui/navigation/file/FileGroup.h"
#include "ui/navigation/help/HelpGroup.h"
#include "ui/navigation/transform/TransformGroup.h"

class ToolBarWidget : public QToolBar {
Q_OBJECT
private:
    std::shared_ptr<FileGroup> fileGroup;
    std::shared_ptr<FilterGroup> filterGroup;
    std::shared_ptr<RenderingGroup> renderingGroup;
    std::shared_ptr<ResizeGroup> resizeGroup;
    std::shared_ptr<HelpGroup> helpGroup;
    std::shared_ptr<TransformGroup> transformGroup;

public:
    explicit ToolBarWidget(Canvas *canvas);

    [[nodiscard]] FilterGroup *getFilterGroup() const;

    [[nodiscard]] RenderingGroup *getRenderingGroup() const;

    [[nodiscard]] FileGroup *getFileGroup() const;

    [[nodiscard]] HelpGroup *getHelpGroup() const;

    [[nodiscard]] ResizeGroup *getResizeGroup() const;

    void deactivateActions();

public slots:

    void activateActions();
    [[nodiscard]] const TransformGroup *getTransformGroup() const;
};


#endif //FILTERS_TOOLBARWIDGET_H
