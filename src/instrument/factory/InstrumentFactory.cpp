//
// Created by Влад Кирилов on 17.03.2023.
//

#include "InstrumentFactory.h"
#include "instrument/single_pixel/gray_scale/GrayScaleFilter.h"
#include "instrument/single_pixel/negative/NegativeFilter.h"
#include "instrument/matrix/smoothing/SmoothingFilter.h"
#include "instrument/matrix/sharpness/SharpnessFilter.h"
#include "instrument/matrix/embossing/EmbossingFilter.h"
#include "instrument/single_pixel/gamma/GammaFilter.h"
#include "instrument/highlight/roberts/RobertsFilter.h"
#include "instrument/highlight/sobel/SobelFilter.h"
#include "instrument/matrix/watercolor/WatercolorFilter.h"
#include "instrument/dither/FloydSteinbergDither.h"
#include "instrument/dither/OrderedDither.h"
#include "instrument/rotation/ImageRotation.h"
#include "instrument/vertical/VerticalPhotoFilter.h"

InstrumentPtr InstrumentFactory::create(const String &&name) const {
    return creators.at(name)->create();
}

InstrumentFactory::InstrumentFactory() {
    creators["Gray Scale"] = std::make_shared<InstrumentCreator<GrayScaleFilter>>();
    creators["Negative"] = std::make_shared<InstrumentCreator<NegativeFilter>>();
    creators["Smooth"] = std::make_shared<InstrumentCreator<SmoothingFilter>>();
    creators["Sharpness"] = std::make_shared<InstrumentCreator<SharpnessFilter>>();
    creators["Embossing"] = std::make_shared<InstrumentCreator<EmbossingFilter>>();
    creators["Gamma"] = std::make_shared<InstrumentCreator<GammaFilter>>();
    creators["Roberts"] = std::make_shared<InstrumentCreator<RobertsFilter>>();
    creators["Sobel"] = std::make_shared<InstrumentCreator<SobelFilter>>();
    creators["Watercolor"] = std::make_shared<InstrumentCreator<WatercolorFilter>>();
    creators["Median"] = std::make_shared<InstrumentCreator<MedianFilter>>();
    creators["Floyd Steinberg"] = std::make_shared<InstrumentCreator<FloydSteinbergDither>>();
    creators["Ordered"] = std::make_shared<InstrumentCreator<OrderedDither>>();
    creators["Image Rotation"] = std::make_shared<InstrumentCreator<ImageRotation>>();
    creators["Vertical Photo"] = std::make_shared<InstrumentCreator<VerticalPhotoFilter>>();
}

