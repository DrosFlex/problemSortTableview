#include "mytableview.h"
#include <QHeaderView>

MyTableView::MyTableView(QWidget *parent)
    :QTableView(parent)
{
    //TableView
    m_model = new QStandardItemModel(this);
    m_model->setHorizontalHeaderItem(TOOL_NUMBER,new QStandardItem("T...."));
    m_model->setHorizontalHeaderItem(INFO,new QStandardItem("Description"));
    m_model->setHorizontalHeaderItem(M3_M4,new QStandardItem("M3/M4"));
    m_model->setHorizontalHeaderItem(TOOL_TYPE,new QStandardItem("Type"));
    m_model->setHorizontalHeaderItem(S1_S2,new QStandardItem("Broche"));
    m_model->setHorizontalHeaderItem(SORTIR,new QStandardItem("Sortir"));
    m_model->setHorizontalHeaderItem(X,new QStandardItem("X"));
    m_model->setHorizontalHeaderItem(Z,new QStandardItem("Z"));
    m_model->setHorizontalHeaderItem(Y,new QStandardItem("Y"));
    m_model->setHorizontalHeaderItem(IMAGE,new QStandardItem("Image"));

    this->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->horizontalHeader()->setResizeContentsPrecision(500);

    m_modelSort = new MyModelSort(this);
    m_modelSort->setSourceModel(m_model);
    this->setSortingEnabled(false);
    this->setModel(m_modelSort);
    this->setColumnWidth(TOOL_NUMBER,60);
    this->setColumnWidth(INFO,240);
    this->setColumnWidth(M3_M4,80);
    this->setColumnWidth(TOOL_TYPE,80);
    this->setColumnWidth(S1_S2,60);
    this->setColumnWidth(SORTIR,80);
    this->setColumnWidth(X,80);
    this->setColumnWidth(Z,80);
    this->setColumnWidth(Y,80);
    this->setColumnWidth(IMAGE,100);



    QList < QStandardItem * > listItem;
    for(int i(0);i < 10 ;i++){
        listItem << new QStandardItem;
        listItem.last()->setTextAlignment(Qt::AlignCenter);
    }
    listItem.at(TOOL_NUMBER)->setData("3",Qt::DisplayRole);
    listItem.at(S1_S2)->setData("S1",Qt::DisplayRole);

    listItem.at(X)->setEditable(false);
    listItem.at(Z)->setEditable(false);
    listItem.at(Y)->setEditable(false);
    listItem.at(IMAGE)->setEditable(false);
    m_model->appendRow(listItem);
    m_model->setVerticalHeaderItem(m_model->rowCount()-1,new QStandardItem("->"));
    this->setRowHeight(m_model->rowCount()-1,this->font().pointSize()+4);
    this->setCurrentIndex(m_modelSort->index(m_model->rowCount()-1 , 0));






    QList < QStandardItem * > listItem2;
    for(int i(0);i < 10 ;i++){
        listItem2 << new QStandardItem;
        listItem2.last()->setTextAlignment(Qt::AlignCenter);
    }
    listItem2.at(TOOL_NUMBER)->setData("1",Qt::DisplayRole);
    listItem2.at(S1_S2)->setData("S1",Qt::DisplayRole);

    listItem2.at(X)->setEditable(false);
    listItem2.at(Z)->setEditable(false);
    listItem2.at(Y)->setEditable(false);
    listItem2.at(IMAGE)->setEditable(false);
    m_model->appendRow(listItem2);
    m_model->setVerticalHeaderItem(m_model->rowCount()-1,new QStandardItem("->"));
    this->setRowHeight(m_model->rowCount()-1,this->font().pointSize()+4);
    this->setCurrentIndex(m_modelSort->index(m_model->rowCount()-1 , 0));







    QList < QStandardItem * > listItem3;
    for(int i(0);i < 10 ;i++){
        listItem3 << new QStandardItem;
        listItem3.last()->setTextAlignment(Qt::AlignCenter);
    }
    listItem3.at(TOOL_NUMBER)->setData("2",Qt::DisplayRole);
    listItem3.at(S1_S2)->setData("S2",Qt::DisplayRole);

    listItem3.at(X)->setEditable(false);
    listItem3.at(Z)->setEditable(false);
    listItem3.at(Y)->setEditable(false);
    listItem3.at(IMAGE)->setEditable(false);
    m_model->appendRow(listItem3);
    m_model->setVerticalHeaderItem(m_model->rowCount()-1,new QStandardItem("->"));
    this->setRowHeight(m_model->rowCount()-1,this->font().pointSize()+4);
    this->setCurrentIndex(m_modelSort->index(m_model->rowCount()-1 , 0));


    this->resize(500,200);



    m_modelSort->sort(TOOL_NUMBER);
    m_modelSort->sort(S1_S2);

    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    connect(this,&QTableView::clicked,this,&MyTableView::displayTool);
}

void MyTableView::displayTool(const QModelIndex &index)
{
    qDebug()<<"Tool:"<<this->model()->data(index,Qt::DisplayRole).toInt(),index.row();
    qDebug()<<"Tool:"<<m_modelSort->index(index.row(),TOOL_NUMBER).data(Qt::EditRole).toInt();
    qDebug()<<"Tool:"<<m_model->item(index.row())->data(Qt::EditRole).toInt();
    qDebug()<<"------------------------------------------------------------";
}
