#ifndef GARBAGEINFO_H
#define GARBAGEINFO_H
#include <QString>

class GarbageInfo
{
private:
    QString name;
    QString classification;
public:
    GarbageInfo();
    GarbageInfo(QString tname, QString classification){
        name = tname;
        this->classification = classification;
    }
    QString getClass(){
        return classification;
    }
    QString getName(){
        return name;
    }
    void setClass(QString classification){
        this->classification = classification;
    }
};

#endif // GARBAGEINFO_H
