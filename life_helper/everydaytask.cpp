#include "everydaytask.h"

EverydayTask::EverydayTask()
{

}

QString EverydayTask::getTask()
{
    return m_task;//store everyday task
}
QString EverydayTask::getTime()
{
    return m_time;
}
int EverydayTask::getLevel()
{
    return m_level;//the importance
}

int EverydayTask::getFinish()
{
    return m_finish;//finish or not 
}

void EverydayTask::setMsg(QString task, QString time, int finish, int level)
{
    m_task=task;
    m_time=time;
    m_level=level;
    m_finish=finish;
}

