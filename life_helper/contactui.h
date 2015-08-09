#ifndef CONTACTUI_H
#define CONTACTUI_H

#include <QWidget>
#include "contact.h"
#include <QMenu>

namespace Ui {
class ContactUI;
}

class ContactUI : public QWidget
{
    Q_OBJECT

public:
    explicit ContactUI(QWidget *parent = 0);
    ~ContactUI();
private slots:
    void contact_rec(Contact c);
    void emit_nameSend();
    void emit_contactSend();
    void contextMenuEvent(QContextMenuEvent* event);
signals:
    void nameSend(QString name);
    void contactSend(Contact c);
private:
    Ui::ContactUI *ui;
    int only;
    QString thisName;
    QAction *m_delete;
    QAction *m_edit;
    Contact m_contact;
};

#endif // CONTACTUI_H
