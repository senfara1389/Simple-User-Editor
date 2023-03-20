#ifndef UPDATABLEIMAGE_H
#define UPDATABLEIMAGE_H

#include <QLabel>
#include <QObject>
#include <QWidget>

class UpdatableImage : public QLabel
{
    Q_OBJECT
public:
    UpdatableImage();
    ~UpdatableImage();
public slots:
    void updateImage(QString filepath);
};

#endif // UPDATABLEIMAGE_H
