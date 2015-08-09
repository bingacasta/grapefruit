#include "essayui.h"
#include "ui_essayui.h"

EssayUI::EssayUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EssayUI)
{
    only=1;
    m_delete=new QAction("删除",this);
    m_edit=new QAction("编辑",this);
    ui->setupUi(this);
    connect(parent,SIGNAL(essaySend(Essay)),this,SLOT(essayRec(Essay)));
    connect(m_delete, SIGNAL(triggered()), this, SLOT(emit_essayDelSend()));//删除
    connect(m_edit, SIGNAL(triggered()), this, SLOT(emit_essayEditSend()));//编辑
}

EssayUI::~EssayUI()
{
    delete ui;
}
void EssayUI::essayRec(Essay t)
{
    if(only==1)
    {
        thisEssay=t;
        ui->label_title->setText(t.get_title());
        ui->label_time->setText(t.get_time());
        only=0;
    }
}

void EssayUI::contextMenuEvent(QContextMenuEvent *event)
{
    //定义右键菜单
    QMenu* popMenu = new QMenu(this);
        popMenu->addAction(m_delete);
        popMenu->addAction(m_edit);
    popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
}

void EssayUI::emit_essayDelSend()
{
    emit essayDelSend(thisEssay);
}
void EssayUI::emit_essayEditSend()
{
    emit essayEditSend(thisEssay);
}
