#ifndef DETAILEDUSERMODEL_H
#define DETAILEDUSERMODEL_H

#include <QAbstractItemModel>
#include <QObject>
#include <QVectorIterator>
#include "jsonhandler.h"

class DetailedUserModel : public QAbstractItemModel
{
    Q_OBJECT

private:
    int colNumber;
    JsonHandler json;
    QString imagePath;
    QVector<QList<QString>> items; //We use a vector of lists because of the 2D nature of the model. Vector represents the rows and List the columns

public:
    DetailedUserModel(int colNumber, QObject *parent = Q_NULLPTR);
    ~DetailedUserModel();

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex& index) const;

    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;

    void append(const QList<QString>& data);
    void reset();

    QList<QString> getRow(const QModelIndex& index, int role = Qt::DisplayRole) const;

    void convertUserToModel(QList<QString>& identifiers);
    QString getImagePath() const;
};

#endif // DETAILEDUSERMODEL_H
