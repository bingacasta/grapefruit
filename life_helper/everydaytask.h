#ifndef EVERYDAYTASK_H
#define EVERYDAYTASK_H
#include <QString>

class EverydayTask
{
public:
    EverydayTask();
    void setMsg(QString task,QString time,int finish,int level);
    QString getTask();
    QString getTime();
    int getFinish();
    int getLevel();
private:
    QString m_task;
    QString m_time;
    int m_finish;
    int m_level;
};

#endif // EVERYDAYTASK_H
