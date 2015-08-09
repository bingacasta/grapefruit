#include "everydaytaskui.h"
#include "ui_everydaytaskui.h"

EveryDayTaskUI::EveryDayTaskUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EveryDayTaskUI)
{
    ui->setupUi(this);

    only=1;
    m_delete=new QAction("删除",this);
    m_edit=new QAction("编辑",this);
    connect(parent,SIGNAL(taskSend(EverydayTask)),this,SLOT(task_rec(EverydayTask)));
    connect(m_delete, SIGNAL(triggered()), this, SLOT(emit_taskSend()));//删除
    connect(m_edit, SIGNAL(triggered()), this, SLOT(emit_taskEditSend()));//编辑
}

EveryDayTaskUI::~EveryDayTaskUI()
{
    delete ui;
}

void EveryDayTaskUI::task_rec(EverydayTask t)
{
    //设置item内容，图标，文本，checkbox
if(only==1)
{
    thisTask=t;
    ui->label_task->setText(t.getTask());
    ui->label_time->setText(t.getTime());
    //QString path="./release/logo.png";//相对项目文件
     /* QString  path=":/menu/images/同事.png";//如果运行release目录的exe文件的话，那么注意和图片的相对位置
        QPixmap img(path);
        ui->label->setPixmap(img);
        ui->label->resize(img.width(),img.height());*/
    only=0;
}
}

void EveryDayTaskUI::contextMenuEvent(QContextMenuEvent *event)
{
    //定义右键菜单
    QMenu* popMenu = new QMenu(this);
        popMenu->addAction(m_delete);
        popMenu->addAction(m_edit);
    popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
}

void EveryDayTaskUI::emit_taskSend()
{
    emit taskSend(thisTask);
}

void EveryDayTaskUI::emit_taskEditSend()
{
    emit taskEditSend(thisTask);
}


