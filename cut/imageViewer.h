#ifndef QIMAGEVIEWER_H
#define QIMAGEVIEWER_H
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QDebug>
#include "cropRect.h"

class ImageViewer : public QWidget
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();
    bool isContainPoint(QPoint p);
    QPoint mapToPixmap(QPoint screenPoint);
    void draw(QPainter &painter);
    void cropFinished();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QPixmap m_pixmap;
    CropRect cropRect;
    qreal scalling;
    bool isLoaded;
    bool isInitialised;
    bool isCropping;
    bool isStartingCrop;
};

#endif // QIMAGEVIEWER_H
