#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include "mymodelsort.h"
#include "Enum.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QSortFilterProxyModel>

class MyTableView : public QTableView
{
    Q_OBJECT
public:
    MyTableView(QWidget *parent = nullptr);
public slots:
    void displayTool(const QModelIndex &index);
private:
    QStandardItemModel *m_model;
    MyModelSort *m_modelSort;
};

#endif // MYTABLEVIEW_H
