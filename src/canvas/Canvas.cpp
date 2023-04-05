//
// Created by Влад Кирилов on 15.03.2023.
//

#include <QGridLayout>
#include "Canvas.h"
#include <QPainter>
#include <QApplication>
#include <QMouseEvent>
#include <QScrollBar>
#include <QSizePolicy>

#include <iostream>
#include <utility>

Canvas::Canvas(QScrollArea *parent) : QWidget(parent), parent(parent), originalImage(std::make_shared<QImage>()),
                                      lastMouseLocation(-1, -1) {}

void Canvas::setInstrument(InstrumentPtr instrument) {
    this->instrument = std::move(instrument);
    canvasState = CanvasState::ORIGINAL;
    filteredImage = nullptr;
    onMouseRelease();
}

void Canvas::paintEvent(QPaintEvent *event) {
    if (currentImage == nullptr) {
        return;
    }

    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);

    auto imageToDraw = currentImage.get();

    if (imageSizeState == ImageSizeState::SCALED) {
        auto newScaledImage = currentImage->scaled(parent->size(), Qt::KeepAspectRatio,
                                                   transformationMode);

        this->scaledImage = std::make_shared<QImage>(std::move(newScaledImage));
        imageToDraw = this->scaledImage.get();
    }

    painter.drawImage(0, 0, *imageToDraw);
    painter.end();
}

void Canvas::showFilteredImage() {
    if (currentImage == nullptr) {
        return;
    }

    if (instrument == nullptr) {
        return;
    }

    if (filteredImage == nullptr) {
        QApplication::setOverrideCursor(Qt::WaitCursor);
        filteredImage = instrument->run(*notFilteredImage);
        QApplication::setOverrideCursor(Qt::ArrowCursor);
    }

    currentImage = filteredImage;

    onResize();
    update();
}

void Canvas::showNotFiltered() {
    currentImage = notFilteredImage;
    onResize();
    update();
}

void Canvas::onMouseRelease() {
    switch (canvasState) {
        case CanvasState::ORIGINAL: {
            showFilteredImage();
            canvasState = CanvasState::FILTERED;
            break;
        }
        case CanvasState::FILTERED: {
            showNotFiltered();
            canvasState = CanvasState::ORIGINAL;
            break;
        }
    }
}

void Canvas::setImageSizeState(ImageSizeState imageSizeState) {
    this->imageSizeState = imageSizeState;
    onResize();
    update();
}

void Canvas::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    lastMouseLocation = event->pos();
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    QWidget::mouseReleaseEvent(event);

    if (!isMouseDragging) {
        onMouseRelease();
    }

    isMouseDragging = false;
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);

    isMouseDragging = true;

    auto pos = event->pos();
    auto delta = pos - lastMouseLocation;
    parent->horizontalScrollBar()->setValue(parent->horizontalScrollBar()->value() - delta.x());
    parent->verticalScrollBar()->setValue(parent->verticalScrollBar()->value() - delta.y());
}

void Canvas::setFileUrl(const QString &url) {
    originalImage->load(url);

    notFilteredImage = originalImage;

    currentImage = notFilteredImage;
    filteredImage = nullptr;

    onResize();
    emit imageLoaded();
}

const QImage &Canvas::getCurrentImage() const {
    return *currentImage;
}

void Canvas::onResize() {
    auto parentSize = parent->size();

    if (imageSizeState == ImageSizeState::SCALED) {
        resize(parentSize.width() - 2, parentSize.height() - 2);
    } else {
        if (!currentImage) return;

        int newWidth = currentImage->width();
        int newHeight = currentImage->height();

        if (parentSize.height() > currentImage->height()) {
            newHeight = parent->height() - 2;
        }
        if (parentSize.width() > currentImage->width()) {
            newWidth = parent->width() - 2;
        }

        resize(newWidth, newHeight);
    }

}

void Canvas::setTransformationMode(Qt::TransformationMode transformationMode) {
    Canvas::transformationMode = transformationMode;
    update();
}




