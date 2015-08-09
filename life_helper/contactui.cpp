#include "contactui.h"
#include "ui_contactui.h"

ContactUI::ContactUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactUI)
{
    ui->setupUi(this);

    only=1;
    m_delete=new QAction(tr("删除"),this);
    m_edit=new QAction(tr("查看"),this);
    connect(parent,SIGNAL(contactSend(Contact)),this,SLOT(contact_rec(Contact)));
    connect(m_delete, SIGNAL(triggered()), this, SLOT(emit_nameSend()));//删除
    connect(m_edit, SIGNAL(triggered()), this, SLOT(emit_contactSend()));//查询
}

ContactUI::~ContactUI()
{
    delete ui;
}


void ContactUI::contact_rec(Contact c)
{
    if(only==1)
    {
     m_contact=c;
    ui->label_name->setText(c.getName());
    ui->label_phone->setText(c.getPhone());
    QString s;
    s=c.getBirthday().toString();
   // ui->label_birth->setText(s);
   // ui->label_email->setText(c.getEmail());
   // ui->label_job->setText(c.getJob());
   // ui->label_type->setText(c.getType());
    only=0;
    }
}
void ContactUI::emit_nameSend()
{
    emit nameSend(thisName);
}

/*void ContactUI::on_pushButton_clicked()
{
    //获取当前姓名
    thisName=ui->label_name->text();
}
*/
void ContactUI::contextMenuEvent(QContextMenuEvent *event)
{
    //定义右键菜单
    QMenu* popMenu = new QMenu(this);
        popMenu->addAction(m_delete);
        popMenu->addAction(m_edit);
    popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
}

void ContactUI::emit_contactSend()
{
    emit contactSend(m_contact);
}

