#include "contact.h"

Contact::Contact()
{

}
void Contact::setMsg(QString name, QString phone, QString email, QString job, QString address, QDate birthday,QString type)
{
    m_name=name;
    m_phone=phone;
    m_job=job;
    m_address=address;
    m_birthday=birthday;
    m_email=email;
    m_type=type;
}

QString Contact::getAddress()
{
    return m_address;
}
QDate Contact::getBirthday()
{
    return m_birthday;
}
QString Contact::getEmail()
{
    return m_email;
}
QString Contact::getJob()
{
    return m_job;
}

QString Contact::getName()
{
    return m_name;
}
QString Contact::getPhone()
{
    return m_phone;
}
QString Contact::getType()
{
    return m_type;
}
