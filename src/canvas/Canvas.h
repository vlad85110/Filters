//
// Created by Влад Кирилов on 15.03.2023.
//

#pragma once

#include <QSharedDataPointer>
#include <QWidget>
#include <QImage>
#include <QMainWindow>
#include <QScrollArea>
#include "instrument/Instrument.h"
#include "CanvasState.h"
#include "types.h"
#include "ImageSizeState.h"

class Instrument;

class Canvas : public QWidget {
Q_OBJECT
private:
    std::shared_ptr<Instrument> instrument;

    const std::shared_ptr<QImage> originalImage;
    std::shared_ptr<QImage> notFilteredImage;
    std::shared_ptr<QImage> filteredImage;
    std::shared_ptr<QImage> currentImage;

    std::shared_ptr<QImage> scaledImage;

    CanvasState canvasState = CanvasState::ORIGINAL;
    ImageSizeState imageSizeState = ImageSizeState::ORIGINAL;

    QScrollArea *parent;

    bool isMouseDragging = false;
public:
    void setTransformationMode(Qt::TransformationMode transformationMode);

private:

    QPoint lastMouseLocation;

    Qt::TransformationMode transformationMode = Qt::SmoothTransformation;

public:
    explicit Canvas(QScrollArea* parent);

    void setInstrument(std::shared_ptr<Instrument> instrument);

    void paintEvent(QPaintEvent *event) override;

    void showFilteredImage();

    void showNotFiltered();

    void setImageSizeState(ImageSizeState imageSizeState);

    void setFileUrl(const QString &url);

    [[nodiscard]] const QImage& getCurrentImage() const;

signals:
    void instrumentSet();
    void imageLoaded();

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

    void onMouseRelease();

    void mouseMoveEvent(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

public slots:
    void onResize();
};


