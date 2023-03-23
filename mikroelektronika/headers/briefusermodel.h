#ifndef BRIEFUSERMODEL_H
#define BRIEFUSERMODEL_H

#include <QAbstractItemModel>
#include <QVectorIterator>
#include "jsonhandler.h"

class BriefUserModel : public QAbstractItemModel
{

    Q_OBJECT

private:
    int colNumber;
    JsonHandler json;
    QVector<QList<QString>> items; //We use a vector of lists because of the 2D nature of the model. Vector represents the rows and List the columns

public:
    BriefUserModel(int colNumber, QObject *parent = Q_NULLPTR);
    ~BriefUserModel();

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex& index) const;

    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;

    QList<QString> getRow(const QModelIndex& index, int role = Qt::DisplayRole) const;

    void append(const QList<QString>& data);
    void reset();

    void convertUserListToModel();
    void deleteUser(QList<QString> parameters);
};

#endif // BRIEFUSERMODEL_H
