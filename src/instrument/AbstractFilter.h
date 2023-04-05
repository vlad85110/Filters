//
// Created by Влад Кирилов on 22.03.2023.
//

#ifndef FILTERS_ABSTRACTFILTER_H
#define FILTERS_ABSTRACTFILTER_H

#include <QtCore/QRunnable>
#include <QtCore/QThreadPool>

#include "Instrument.h"

class AbstractFilter : public Instrument {
protected:
    int taskCnt = 4;

    class HandleImageTask : public QRunnable {
    private:
        int num;
        int startIndex;
        int endIndex;
    private:
        QImage image;
        QImage &copy;
    public:
        [[nodiscard]] int getStartIndex() const;

        [[nodiscard]] int getEndIndex() const;

    private:
        AbstractFilter &filter;
    public:
        HandleImageTask(int num, int startIndex, int endIndex, QImage &image, QImage &copy, AbstractFilter &filter);

        [[nodiscard]] const QImage &getImage() const;

        void run() override;
    };

public:
    std::shared_ptr<QImage> run(QImage &image) override;

    virtual QRgb getNewPixelColor(int x, int y, QImage &image, int threadNum) = 0;
};


#endif //FILTERS_ABSTRACTFILTER_H
