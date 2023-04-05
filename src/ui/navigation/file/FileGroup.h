//
// Created by Влад Кирилов on 03.04.2023.
//

#ifndef FILTERS_FILEGROUP_H
#define FILTERS_FILEGROUP_H


#include "ui/navigation/AbstractActionGroup.h"
#include "canvas/Canvas.h"

class FileGroup : public AbstractActionGroup {
public:
    explicit FileGroup(QObject *parent, Canvas &canvas);

};


#endif //FILTERS_FILEGROUP_H
