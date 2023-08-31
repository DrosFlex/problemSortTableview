#ifndef TOOLNUMBER_H
#define TOOLNUMBER_H

#include <QString>

class ToolNumber
{
public:
    ToolNumber();
    ToolNumber(const ToolNumber &T);
    ~ToolNumber();
    bool setToolNumber(const int &toolRef , const int &rowModel);
    bool isToolValid();
    bool convertToolNumber(const int &toolRef , int &post , int &geometry) const;
    int getPost() const;
    int getGeometry() const;
    QString getToolNumber() const;
    int getRow() const;
    bool operator<(const ToolNumber &T) const;
    bool operator==(const ToolNumber &T) const;
    bool operator!=(const ToolNumber &T) const;

private:
    int m_post;
    int m_geometry;
    bool m_isValid;
    int m_rowModel;

};
bool isBigger(const ToolNumber &T1, const ToolNumber &T2);
#endif // TOOLNUMBER_H
