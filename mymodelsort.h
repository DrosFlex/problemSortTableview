#ifndef MYMODELSORT_H
#define MYMODELSORT_H

#include <QSortFilterProxyModel>

class MyModelSort : public QSortFilterProxyModel
{
public:
    explicit MyModelSort(QObject *parent = nullptr);
    // QSortFilterProxyModel interface
protected:
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const;
};

#endif // MYMODELSORT_H
