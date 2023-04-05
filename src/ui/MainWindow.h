//
// Created by Влад Кирилов on 15.03.2023.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "instrument/Instrument.h"


class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
};

#endif // MAINWINDOW_H
