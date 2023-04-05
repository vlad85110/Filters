//
// Created by Влад Кирилов on 15.03.2023.
//

#ifndef FILTERS_TOOLBARACTION_H
#define FILTERS_TOOLBARACTION_H

#include <QPushButton>
#include <QMenu>
#include <QAction>


class ToolBarAction : public QAction {
Q_OBJECT
protected:
    QString name;

public:
    ToolBarAction(QString &&iconPath, QString &&name);
    virtual void onMouseClicked(){};
    ~ToolBarAction() override;

public slots:
    virtual void trig();
};


#endif //FILTERS_TOOLBARACTION_H
