//
// Created by Влад Кирилов on 16.03.2023.
//

#include "ToolBarWidget.h"
#include "instrument/factory/InstrumentFactory.h"
#include <QHBoxLayout>

ToolBarWidget::ToolBarWidget(Canvas *canvas) {
    setIconSize(QSize(20, 20));

    connect(canvas, &Canvas::imageLoaded, this, &ToolBarWidget::activateActions);

    auto setInstrument = [=](InstrumentPtr instrument) {
        canvas->setInstrument(std::move(instrument));
        renderingGroup->activateActions();
    };

    auto showFiltered = [=]() {
        canvas->showFilteredImage();
    };

    auto showOriginal = [=]() {
        canvas->showNotFiltered();
    };

    auto setState = [=](ImageSizeState state) {
        canvas->setImageSizeState(state);
    };

    auto setMode = [=](Qt::TransformationMode mode) {
        canvas->setTransformationMode(mode);
    };

    fileGroup = std::make_shared<FileGroup>(this, *canvas);
    addActions(fileGroup->actions());

    addSeparator();

    filterGroup = std::make_shared<FilterGroup>(this, setInstrument);
    connect(canvas, &Canvas::imageLoaded, filterGroup.get(), &FilterGroup::resetChecked);
    addActions(filterGroup->actions());

    renderingGroup = std::make_shared<RenderingGroup>(this, showFiltered, showOriginal);

    connect(canvas, SIGNAL(instrumentSet()),
            renderingGroup.get(), SLOT(activateActions()));

    addSeparator();

    resizeGroup = std::make_shared<ResizeGroup>(this, setState);
    addActions(resizeGroup->actions());

    addSeparator();

    transformGroup = std::make_shared<TransformGroup>(this, setMode);
    addActions(transformGroup->actions());

    addSeparator();

    helpGroup = std::make_shared<HelpGroup>(this);
    addActions(helpGroup->actions());

    deactivateActions();
}

const TransformGroup *ToolBarWidget::getTransformGroup() const {
    return transformGroup.get();
}

FilterGroup *ToolBarWidget::getFilterGroup() const {
    return filterGroup.get();
}

RenderingGroup *ToolBarWidget::getRenderingGroup() const {
    return renderingGroup.get();
}

ResizeGroup *ToolBarWidget::getResizeGroup() const {
    return resizeGroup.get();
}

FileGroup *ToolBarWidget::getFileGroup() const {
    return fileGroup.get();
}

HelpGroup *ToolBarWidget::getHelpGroup() const {
    return helpGroup.get();
}

void ToolBarWidget::activateActions() {
    for (auto action: filterGroup->actions()) {
        action->setEnabled(true);
    }

    for (auto action: fileGroup->actions()) {
        action->setEnabled(true);
    }

}

void ToolBarWidget::deactivateActions() {
    for (auto action: filterGroup->actions()) {
        action->setEnabled(false);
    }
}
