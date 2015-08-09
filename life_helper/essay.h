#ifndef ESSAY
#define ESSAY
#include "qstring.h"

class Essay
{
public:
    Essay():m_title("null"),m_essay("null"),m_type("null"),m_time("null"){}
    Essay(QString a,QString b,QString c,QString d);
    QString get_title();
    QString get_essay();
    QString get_type();
    QString get_time();
    void setMsg(QString title,QString essay,QString type,QString time);
private:
    QString m_title;
    QString m_essay;
    QString m_type;
    QString m_time;
};
#endif // ESSAY

