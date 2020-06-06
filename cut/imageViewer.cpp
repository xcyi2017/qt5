#include "imageViewer.h"

ImageViewer::ImageViewer(QWidget *parent):
    QWidget(parent),
    scalling(1.0),
    isLoaded(true),
    isInitialised(false),
    isCropping(false)

{
    cropRect.reset();
    m_pixmap.load("C:\\Users\\xcy\\Pictures\\Saved Pictures\\eberhard-grossgasteiger-2gNx4aKQYvY-unsplash.jpg");

}

ImageViewer::~ImageViewer()
{

}

bool ImageViewer::isContainPoint(QPoint p)
{
    QSize s = m_pixmap.size();
    s.scale(scalling * s, Qt::KeepAspectRatio);

    //If pixmap bigger than current window.
    if ((s.height() > this->rect().height()) && (s.width() > this->rect().width()))
    {
        return true;
    }

    QPoint topleft;
    topleft.setX((this->width() - s.width()) / 2);
    topleft.setY((this->height() - s.height()) / 2);

    QRect rect(topleft, s);
    return rect.contains(p);
}

QPoint ImageViewer::mapToPixmap(QPoint screenPoint)
{
    QSize pixmapSize = m_pixmap.size();
    pixmapSize.scale(scalling * pixmapSize, Qt::KeepAspectRatio);

    //Get the position of screenPoint to the pixmap in show.
    QPoint tmpPos;
    if (pixmapSize.width() > this->width() && pixmapSize.height() > this->height())
    {
        tmpPos.setX(pixmapSize.width() - (this->width() - screenPoint.x()));
        tmpPos.setY(pixmapSize.height() - (this->height() - screenPoint.y()));
    }
    else if (pixmapSize.width() < this->width() && pixmapSize.height() > this->height())
    {
        tmpPos.setX(screenPoint.x() - (this->width() - pixmapSize.width()) / 2);
        tmpPos.setY(pixmapSize.height() - (this->height() - screenPoint.y()));
    }
    else if (pixmapSize.width() > this->width() && pixmapSize.height() < this->height())
    {
        tmpPos.setX(pixmapSize.width() - (this->width() - screenPoint.x()));
        tmpPos.setY(screenPoint.y() - (this->height() - pixmapSize.height()) / 2);
    }
    else{
        QPoint topleft;
        topleft.setX((this->width() - pixmapSize.width()) / 2);
        topleft.setY((this->height() - pixmapSize.height()) / 2);
        tmpPos.setX(screenPoint.x() - topleft.x());
        tmpPos.setY(screenPoint.y() - topleft.y());
    }
    //return the position to the real pixmap.*/
    return QPoint(static_cast<int>(tmpPos.x() / scalling), static_cast<int>(tmpPos.y() / scalling));
}

void ImageViewer::draw(QPainter &painter)

{
    painter.save();
    if (isCropping)
    {
        qDebug() << cropRect.width() << cropRect.height();
        //painter.setPen(Qt::darkGreen);
        QPen pen;
        pen.setBrush(Qt::red);
        pen.setStyle(Qt::DashLine);
        pen.setWidth(1);
        painter.setPen(pen);

        //start point in the left to the end point.
        if (cropRect.startPoint().x() < cropRect.endPoint().x())
        {

            if (cropRect.startPoint().y() < cropRect.endPoint().y())
            {
                //start point in the top to the end point.
                painter.drawRect(cropRect.startPoint().x() * scalling, cropRect.startPoint().y() * scalling, cropRect.width() * scalling, cropRect.height() * scalling);
            }
            else{
                //start point in the bottom to the end point.
                painter.drawRect(cropRect.startPoint().x() * scalling, cropRect.endPoint().y() * scalling, cropRect.width() * scalling, cropRect.height() * scalling);
            }
        }
        else
        {
            if (cropRect.startPoint().y() > cropRect.endPoint().y())
            {
                painter.drawRect(cropRect.endPoint().x() * scalling, cropRect.endPoint().y() * scalling, cropRect.width() * scalling, cropRect.height() * scalling);
            }
            else{
                painter.drawRect(cropRect.endPoint().x() * scalling, cropRect.startPoint().y() * scalling, cropRect.width() * scalling, cropRect.height() * scalling);
            }
        }
    }
    painter.restore();
}

void ImageViewer::cropFinished()
{
    QRect crop(cropRect.startPoint(), QSize(cropRect.width(), cropRect.height()));
    QPixmap cropped = m_pixmap.copy(crop);
    m_pixmap = cropped;
    cropRect.reset();
    isCropping = false;
    this->update();
}

void ImageViewer::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    if (m_pixmap.isNull())
    {
        return;
    }

    QPainter painter(this);
    if (isLoaded)
    {
        qDebug() << "hello world";
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        QSize pixSize = m_pixmap.size();

        //For canvas's size not change when window's size change.
        if (!isInitialised)
        {
            QSize initialSize = event->rect().size();
            scalling = 1.0 * initialSize.width() / pixSize.width();
            isInitialised = true;
        }
        pixSize.scale(scalling * pixSize, Qt::KeepAspectRatio);
        this->setMinimumSize(pixSize);

        QPoint topleft;
        topleft.setX((this->width() - pixSize.width()) / 2);
        topleft.setY((this->height() - pixSize.height()) / 2);

        painter.drawPixmap(topleft, m_pixmap.scaled(pixSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    draw(painter);
}

void ImageViewer::mousePressEvent(QMouseEvent *event)
{
    isCropping = true;
    qDebug() << "screenPos: " << event->pos();
    qDebug() << "是否在照片上: " << isContainPoint(event->pos());
    if ((event->buttons() == Qt::LeftButton) && isContainPoint(event->pos()) && isCropping)
    {

        cropRect.setStart(mapToPixmap(event->pos()));
        cropRect.setEnd(mapToPixmap(event->pos()));
        isStartingCrop = true;
        qDebug() << "点下鼠标左键";
    }
}

void ImageViewer::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() == Qt::LeftButton) && isStartingCrop)
    {
        //qDebug() << "点下鼠标左键并移动"
        if (isContainPoint(event->pos()))
        {
            cropRect.setEnd(mapToPixmap(event->pos()));
            update();
        }

    }
}

void ImageViewer::mouseReleaseEvent(QMouseEvent *)
{   qDebug() << "释放鼠标";
    QRect rect(cropRect.startPoint(), cropRect.endPoint());
    isStartingCrop = false;
    isCropping = false;
}


