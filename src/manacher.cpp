#include "manacher.h"

Manacher::Manacher()
{

}

#include <QtCore>



ManacherBackInfo manacher_core(const QString& str)
{
    const int size = str.size();

    ManacherBackInfo res;
    res.maxLenCenterIdx = 0;
    res.maxLenRadius = 0;


    QVector<int > radius(size, 0);
    int rPos   = 0;
    int center = 0;
    for(int i = 0; i < size; i++){

        if (i >= rPos){

        }else{
            int j = 2*center - i;
            int riMax = rPos - i;
            if (radius[j] < riMax){
                radius[i] = radius[j];
                continue;
            }else{
                radius[i] = riMax;
            }

//            radius[i] = radius[j] < riMax ? radius[j] : riMax;
        }

        while(i - radius[i] >=0    &&
              i + radius[i] < size &&
              str[i - radius[i]] == str[i + radius[i]]){
            radius[i]++;
        }

        if (i + radius[i]-1 > rPos) {
            rPos = i + radius[i]-1;
            center = i;
        }

        if (radius[i] > res.maxLenRadius){
            res.maxLenRadius  = radius[i];
            res.maxLenCenterIdx = i;
        }
    }

    return res;
}

QString preProcess(const QString& str)
{
    QString res;

    const int size = str.size();
    for(int i = 0; i < size; i++){
        res.append("#");
        res.append(str.at(i));
    }
    res.append("#");

    return res;
}

QString proProcess(const QString& str)
{
    QString res;

    const int size = str.size();
    for(int i = 0; i < size; i++){
        if (str.at(i) != "#"){
            res.append(str.at(i));
        }
    }

    return res;

}



QString manacher(const QString& str){
    QString input = preProcess(str);

    QElapsedTimer timer;
    timer.start();
    ManacherBackInfo info = manacher_core(input);
    qDebug()<< "manacher_core:"<< timer.elapsed()<< "ms";

    const int sIdx = info.maxLenCenterIdx - (info.maxLenRadius-1);
    const int len  = 2*info.maxLenRadius - 1;
    QString ppstr = input.mid(sIdx, len);

    return proProcess(ppstr);
}
