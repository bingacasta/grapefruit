#include "essay.h"

Essay::Essay(QString a,QString b,QString c,QString d)
{
    m_title=a;
    m_essay=b;
    m_type=c;
    m_time=d;
}

QString Essay::get_essay()
{
    return m_essay;
}
QString Essay::get_time()
{
    return m_time;
}
QString Essay::get_title()
{
    return m_title;
}

QString Essay::get_type()
{
    return m_type;
}
void Essay::setMsg(QString a,QString b,QString c,QString d)
{
    m_title=a;
    m_essay=b;
    m_type=c;
    m_time=d;
}
