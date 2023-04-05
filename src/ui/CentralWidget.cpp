//
// Created by Влад Кирилов on 03.04.2023.
//

#include "CentralWidget.h"
#include "canvas/Canvas.h"
#include <QScrollArea>
#include <QStyle>
#include <QPainter>

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent) {
    auto layout = new QHBoxLayout();
    setLayout(layout);

    layout->setContentsMargins(5, 5, 5, 5);
    auto *scrollArea = new QScrollArea(this);

    canvas = new Canvas(scrollArea);
    scrollArea->setWidget(canvas);

    layout->addWidget(scrollArea);
}

Canvas *CentralWidget::getCanvas() const {
    return canvas;
}

void CentralWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    auto rect = QRect(5, 5, size().width() - 10, size().height() - 10);

    QPainter painter(this);
    QPen pen;
    pen.setDashPattern({7.0, 7.0});
    painter.setPen(pen);
    painter.drawRect(rect);
    painter.end();
}

void CentralWidget::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    canvas->onResize();
}
