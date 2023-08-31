#include <toolnumber.h>
#include "Enum.h"
#include "mymodelsort.h"

MyModelSort::MyModelSort(QObject *parent) : QSortFilterProxyModel(parent)
{

}

bool MyModelSort::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
{
    QVariant v1 = source_left.data(Qt::DisplayRole);
    if((source_left.column() == S1_S2) && (v1.toString().isEmpty()))
        v1 = source_left.data(INFO_DATA);
    QVariant v2 = source_right.data(Qt::DisplayRole);
    if((source_right.column() == S1_S2) && (v2.toString().isEmpty()))
        v1 = source_right.data(INFO_DATA);

    if((source_left.column() == TOOL_NUMBER) && (source_right.column() == TOOL_NUMBER)){
        ToolNumber t1;
        t1.setToolNumber(v1.toString().toInt(),source_left.row());
        ToolNumber t2;
        t2.setToolNumber(v2.toString().toInt(),source_right.row());
        if(t1.isToolValid() && t2.isToolValid())
            return t1 < t2;
        else
            return false;
    }
    else if ((source_left.column() == S1_S2) && (source_right.column() == S1_S2)) {
        if(v1.toString() == "S1:" && v2.toString() != "S2:"){
            return true;
        }
        else if(v1.toString() == "S2:" && v2.toString() != "S1:"){
            if(v2.toString() == "S1")
                return false;
            else
                return true;
        }
        else
            return v1.toString() < v2.toString();
    }
    else
        return false;
}
