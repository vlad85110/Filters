//
// Created by Влад Кирилов on 15.03.2023.
//

#pragma once

#include "canvas/Canvas.h"
#include "ui/config/InstrumentForm.h"
#include "ui/button/ToolBarAction.h"

class Canvas;

class Instrument {
public:
    virtual std::shared_ptr<QImage> run(QImage &image) = 0;

    [[nodiscard]] virtual InstrumentForm *getForm() const { return nullptr; }

    virtual ~Instrument() = default;
};

using InstrumentPtr = std::shared_ptr<Instrument>;

