#ifndef UPDATABLEIMAGE_H
#define UPDATABLEIMAGE_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QAbstractButton>

class UpdatableImage : public QLabel
{
    Q_OBJECT
public:
    UpdatableImage(QWidget* parent);
    ~UpdatableImage();
public slots:
    void updateImage(QString filepath);
    void resetImageSlot();
};

#endif // UPDATABLEIMAGE_H
