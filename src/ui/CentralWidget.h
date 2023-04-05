//
// Created by Влад Кирилов on 03.04.2023.
//

#ifndef FILTERS_CENTRALWIDGET_H
#define FILTERS_CENTRALWIDGET_H


#include <QWidget>
#include "canvas/Canvas.h"

class CentralWidget : public QWidget {
Q_OBJECT
protected:
    void paintEvent(QPaintEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

private:
    Canvas *canvas;
public:
    Canvas *getCanvas() const;

public:
    explicit CentralWidget(QWidget *parent);
};


#endif //FILTERS_CENTRALWIDGET_H
