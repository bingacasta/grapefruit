#ifndef CONTACT_H
#define CONTACT_H

#include<QString>
#include<QDate>
class Contact
{
public:
    Contact();
    QString getName();
    QString getPhone();
    QString getEmail();
    QString getJob();
    QDate getBirthday();
    QString getAddress();
    QString getType();
    void setMsg(QString name,QString phone,QString email,QString job,QString address,QDate birthday,QString m_type);
private:
    QString m_name;
    QString m_phone;
    QString m_email;
    QString m_job;
    QString m_address;
    QDate m_birthday;
    QString m_type;
};

#endif // CONTACT_H
