//
// Created by Влад Кирилов on 21.03.2023.
//

#include <iostream>
#include "FilterGroup.h"
#include "instrument/factory/InstrumentFactory.h"
#include "ui/button/instrument/FilterAction.h"
#include "ui/button/about/AboutAction.h"

FilterGroup::FilterGroup(QObject *parent, const Consumer<InstrumentPtr> &setInstrument)
        : AbstractActionGroup(parent, QString("Filter")) {
    auto names = std::vector<std::pair<QString, QString>>{
            {"Gray Scale", "grayScale.png"},
            {"Negative", "negative.png"},
            {"Smooth", "smooth.png"},
            {"Sharpness", "sharpness"},
            {"Embossing", "embossing.png"},
            {"Gamma", "gamma.png"},
            {"Roberts", "Roberts.png"},
            {"Sobel", "Sobel.png"},
            {"Watercolor", "watercolor.png"},
            {"Floyd Steinberg", "FloydSteinberg.png"},
            {"Ordered", "Ordered.png"},
            {"Image Rotation", "rotate.png"},
            {"Vertical Photo", "vertical.png"}
    };

    setExclusive(true);

    auto iconPrefix = QString("/Users/vladkirilov/CLionProjects/filters/resources/");
    auto factory = InstrumentFactory();

    for (auto &pair: names) {
        auto iconPath = iconPrefix + pair.second;
        auto filterName = pair.first;
        auto action = new FilterAction(
                iconPath, filterName, filterName.toStdString(), factory, setInstrument
        );
        addAction(action);
    }
}
