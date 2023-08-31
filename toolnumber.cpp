#include "toolnumber.h"
#include <QDebug>

ToolNumber::ToolNumber()
    :m_post(0)
    ,m_geometry(0)
    ,m_isValid(false)
    ,m_rowModel(-1)
{
}

ToolNumber::ToolNumber(const ToolNumber &T)
    :m_post(T.m_post)
    ,m_geometry(T.m_geometry)
    ,m_isValid(T.m_isValid)
    ,m_rowModel(T.m_rowModel)
{
}

ToolNumber::~ToolNumber()
{
    //qDebug()<<"ToolNumber destroyed";
}

bool ToolNumber::setToolNumber(const int &toolRef,const int &rowModel)
{
    int post(0);
    int geometry(0);
    if(convertToolNumber(toolRef,post,geometry) && (rowModel > -1)){
        m_post = post;
        m_geometry = geometry;
        m_rowModel = rowModel;
        m_isValid = true;
        return true;
    }
    else{
        m_post = 0;
        m_geometry = 0;
        m_isValid = false;
        m_rowModel = -1;
        return false;
    }
}

bool ToolNumber::isToolValid()
{
    return m_isValid;
}

bool ToolNumber::convertToolNumber(const int &toolRef,
                                   int &post,
                                   int &geometry) const
{
    QString toolRefStr(QString::number(toolRef));
    if((toolRefStr.size() > 4) || (toolRefStr.isEmpty()) || (toolRef == 0))
        return false;

    if((toolRefStr.size() == 1) || (toolRefStr.size() == 2)){
        post = toolRef;
        geometry = toolRef;
    }

    else if(toolRefStr.size() == 3){
        QString first(toolRefStr.at(0));
        post = first.toInt();
        QString end(toolRefStr.remove(0,1));
        geometry = end.toInt();
    }

    else if(toolRefStr.size() == 4){
        QString first(toolRefStr.mid(0,2));
        post = first.toInt();
        QString end(toolRefStr.mid(2));
        geometry = end.toInt();
    }

    if((post == 0 ) || (geometry == 0))
        return false;
    else
        return true;
}

int ToolNumber::getPost()const
{
    return m_post;
}

int ToolNumber::getGeometry()const
{
    return m_geometry;
}

QString ToolNumber::getToolNumber() const
{
    QString t("T");
    if(this->m_isValid){

    QString post(QString::number(this->getPost()));
    if(post.size()==1)
        post.insert(0,"0");
    t += post;

    QString geometry(QString::number(this->getGeometry()));
    if(geometry.size()==1)
        geometry.insert(0,"0");
    t += geometry;
    }
    else{
        t += "xxxx";
    }
    return t;
}

int ToolNumber::getRow() const
{
    return m_rowModel;
}

bool ToolNumber::operator<(const ToolNumber &T)const
{
    if(this->getPost() < T.getPost())
        return true;
    else if(this->getPost() == T.getPost()){
        if(this->getGeometry() < T.getGeometry())
            return true;
    }
    return false;
}

bool ToolNumber::operator==(const ToolNumber &T) const
{
    return (this->getPost() == T.getPost()) && (this->getGeometry() == T.getGeometry());
}

bool ToolNumber::operator!=(const ToolNumber &T) const
{
    return !(*this == T);
}

bool isBigger(const ToolNumber &T1, const ToolNumber &T2)
{
    return T1 < T2;
}

















