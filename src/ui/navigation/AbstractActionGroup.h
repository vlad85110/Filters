//
// Created by Влад Кирилов on 26.03.2023.
//

#ifndef FILTERS_ABSTRACTACTIONGROUP_H
#define FILTERS_ABSTRACTACTIONGROUP_H


#include <QActionGroup>

class AbstractActionGroup : public QActionGroup {
Q_OBJECT
public:
    [[nodiscard]] QMenu *getMenu() const;

    ~AbstractActionGroup() override;

    QString name;

protected:
     AbstractActionGroup(QObject *parent, QString name);
};


#endif //FILTERS_ABSTRACTACTIONGROUP_H
