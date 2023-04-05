//
// Created by Влад Кирилов on 22.03.2023.
//

#include <iostream>
#include <QPainter>
#include "AbstractFilter.h"

std::shared_ptr<QImage> AbstractFilter::run(QImage &image) {
    auto iterPerTask = image.height() / taskCnt;
    auto copy = std::make_shared<QImage>(image);

    Vector<std::shared_ptr<HandleImageTask>> tasks;

    for (int i = 0; i < taskCnt; ++i) {
        auto startIndex = i * iterPerTask;

        int endIndex;

        if (i == taskCnt - 1) {
            endIndex = startIndex + (image.height() - i * iterPerTask);
        } else {
            endIndex = (i + 1) * iterPerTask;
        }

        tasks.emplace_back(std::make_shared<HandleImageTask>(i, startIndex, endIndex, image, *copy,
                                                             *this));
        QThreadPool::globalInstance()->start(tasks[i].get());
    }

    QThreadPool::globalInstance()->waitForDone();

    QPainter painter(copy.get());
    for (const auto &task: tasks) {
        auto imagePart = task->getImage();
        auto rect = QRect(0, task->getStartIndex(), image.width(), task->getEndIndex());
        painter.drawImage(rect, imagePart, rect);
    }
    painter.end();

    return copy;
}

AbstractFilter::HandleImageTask::HandleImageTask(int num, int startIndex, int endIndex, QImage &image, QImage &copy,
                                                 AbstractFilter &filter)
        : num(num), startIndex(startIndex), endIndex(endIndex), image(image), copy(copy), filter(filter) {
    setAutoDelete(false);
}

void AbstractFilter::HandleImageTask::run() {
    for (int i = startIndex; i < endIndex; ++i) {
        for (int j = 0; j < image.width(); ++j) {
            auto newPixelColor = filter.getNewPixelColor(j, i, copy, num);
            image.setPixel(j, i, newPixelColor);
        }
    }
}

const QImage &AbstractFilter::HandleImageTask::getImage() const {
    return image;
}

int AbstractFilter::HandleImageTask::getStartIndex() const {
    return startIndex;
}

int AbstractFilter::HandleImageTask::getEndIndex() const {
    return endIndex;
}


