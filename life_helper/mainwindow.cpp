#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QCursor>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent,Qt::FramelessWindowHint),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //程序启动  进入登陆界面
    ui->renmai_swid->hide();
    ui->jishi_wid->hide();
    ui->main_wid->hide();
    ui->zhangben_wid_2->hide();
    ui->login_wid->show();
    ui->renmai_swid->hide();
    ui->menu_frame->hide();
    ui->register_wid->hide();
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(-5, 5);
    shadow_effect->setColor(Qt::gray);
    shadow_effect->setBlurRadius(8);

    ui->login_wid->setGraphicsEffect(shadow_effect);
    //注册信号与槽
    connect(ui->addBtn,SIGNAL(clicked()),this,SLOT(emit_taskSend()));//每日任务
    connect(ui->sureBtn,SIGNAL(clicked()),this,SLOT(emit_contactSend()));//联系人信息
    connect(ui->okBtn_2,SIGNAL(clicked()),this,SLOT(emit_essaySend()));//联系人信息
}


MainWindow::~MainWindow()
{
    delete ui;
}

/*************
 *自定义窗口
 *
 * ***********/

//窗口移动
void MainWindow::mousePressEvent(QMouseEvent * event)
{
   if (event->button() == Qt::LeftButton) //点击左边鼠标
   {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        //globalPos()获取根窗口的相对路径，frameGeometry().topLeft()获取主窗口左上角的位置
        event->accept();   //鼠标事件被系统接收
   }
   if (event->button() == Qt::RightButton)
   {
        close();
   }
}

void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
   if (event->buttons() == Qt::LeftButton) //当满足鼠标左键被点击时。
   {
        move(event->globalPos() - dragPosition);//移动窗口
        event->accept();
   }
}

void MainWindow::on_minBtn_clicked()
{
    showMinimized();
}

void MainWindow::on_closeBtn_clicked()
{
    close();
}

/**********************
//界面切换
主页面 登陆 日程 记事 人脉 账本

***********************/
void MainWindow::on_richengBtn_clicked()   //进入日程界面
{
    ui->renmai_swid->hide();
    ui->jishi_wid->hide();
    ui->renmai_swid->hide();
    ui->zhangben_wid_2->hide();
    ui->login_wid->hide();
    ui->main_wid->show();


}
void MainWindow::on_renmaiBtn_clicked()
{

    ui->jishi_wid->hide();
    ui->main_wid->hide();
    ui->zhangben_wid_2->hide();
    ui->login_wid->hide();
    ui->renmai_swid->hide();
    ui->renmai_swid->show();
    ui->renmai1->show();
    ui->renmai2->hide();

}



void MainWindow::on_jishiBtn_clicked()
{
    ui->zhangben_wid_2->hide();
    ui->login_wid->hide();
    ui->renmai_swid->hide();
    ui->renmai_swid->hide();
    ui->main_wid->hide();
    ui->jishi_wid->show();
    ui->jishi2->hide();
    ui->jishi1->show();

}


void MainWindow::on_zhangbenBtn_clicked()
{
    ui->jishi_wid->hide();
    ui->login_wid->hide();
    ui->renmai_swid->hide();
    ui->renmai_swid->hide();
    ui->main_wid->hide();
    ui->zhangben_wid_2->show();
    ui->zhangben2->hide();
    ui->zhangben3->hide();
    ui->zhangben1->show();

}


/***************
 * 记事页面 次级页面判断
 *
 * ************/

void MainWindow::on_addBtn_6_clicked()
{
    ui->jishi1->hide();
    ui->jishi2->show();
}



/*********记事保存 取消 ************/
void MainWindow::on_okBtn_2_clicked()
{
    if(ui->textEdit_essay->toPlainText()!="")
    {
    ui->jishi2->hide();
    ui->jishi1->show();
    //更新列表
    QDateTime mtime=QDateTime::currentDateTime();
    QString s=mtime.toString();
    m_essay.setMsg("title",ui->textEdit_essay->toPlainText(),"type",s);
    QListWidgetItem *mItem=new QListWidgetItem(ui->listWidget_essay);
    mItem->setSizeHint(QSize(mItem->sizeHint().width(),71));
    EssayUI *essayui=new EssayUI(this);
    connect(essayui,SIGNAL(essayDelSend(Essay)),this,SLOT(essayDelRec(Essay)));
    connect(essayui,SIGNAL(essayEditSend(Essay)),this,SLOT(essayEditRec(Essay)));
    ui->listWidget_essay->setItemWidget(mItem,essayui);
    ui->textEdit_essay->setText("");
    }
    else
    {
        QMessageBox *b=new QMessageBox();
        b->setText("不能为空！");
        b->exec();
    }
    //写入数据库
}

void MainWindow::on_cancelBtn_6_clicked()
{
    ui->jishi2->hide();
    ui->jishi1->show();
}

/***************
 * 账本页面 次级页面判断
 *
 * ************/

//点击收入按钮
void MainWindow::on_incomeBtn_clicked()
{
     ui->zhangben3->hide();
     ui->zhangben2->show();
     ui->zhangben1->hide();


}
  //点击支出按钮
void MainWindow::on_outcomeBtn_clicked()
{
    ui->zhangben3->hide();
    ui->zhangben2->show();
    ui->zhangben1->hide();
}


/****** 账本显示 点击关闭按钮关闭页面********/
void MainWindow::on_pushButton_19_clicked()
{
    ui->zhangben3->hide();
    ui->zhangben2->hide();
    ui->zhangben1->show();
}
/******添加页面  收入 支出******/
void MainWindow::on_addBtn_3_clicked()
{
    ui->zhangben2->hide();
    ui->zhangben1->hide();
    ui->zhangben3->show();
}
//收入支出保存
void MainWindow::on_saveBtn_clicked()
{
    ui->zhangben3->hide();
    ui->zhangben2->hide();
    ui->zhangben1->show();
}
//收入支出取消
void MainWindow::on_cancelBtn_4_clicked()
{
    ui->zhangben3->hide();
    ui->zhangben2->hide();
    ui->zhangben1->show();
}

/***************
 * 人脉页面 次级页面判断
 *
 * ************/

void MainWindow::on_pushButton_7_clicked()
{
    ui->renmai2->show();
    ui->renmai1->hide();
}

void MainWindow::on_sureBtn_clicked()           //确定消息处理
{
    //添加至列表
    if(ui->lineEdit_name->text()!="")
    {
   // 判断数据库中是否存在
        //然后再执行
    m_contact.setMsg(ui->lineEdit_name->text(),ui->lineEdit_phone->text(),ui->lineEdit_email->text(),ui->lineEdit_job->text(),ui->lineEdit_address->text(),ui->dateEdit_bir->date(),ui->comboBox->currentText());
    QListWidgetItem *mItem=new QListWidgetItem(ui->listWidget_contact);
    mItem->setSizeHint(QSize(mItem->sizeHint().width(),68));
    ContactUI *contactUI=new ContactUI(this);
    connect(contactUI,SIGNAL(nameSend(QString)),this,SLOT(nameRec(QString)));
    connect(contactUI,SIGNAL(contactSend(Contact)),this,SLOT(contactRec(Contact)));
    ui->listWidget_contact->setItemWidget(mItem,contactUI);
  //************************************//
    ui->lineEdit_name->setText("");
    ui->lineEdit_address->setText("");
    ui->lineEdit_email->setText("");
    ui->lineEdit_job->setText("");
    ui->lineEdit_qq->setText("");
    ui->lineEdit_phone->setText("");
    ui->label_5->setText("新联系人");
    //返回页面
    ui->renmai1->show();
    ui->renmai2->hide();
    //添加至数据库
   /*数据库代码操作*/
    }
    else
    {
        QMessageBox *b=new QMessageBox();
        b->setText("姓名不能为空！");
        b->exec();
    }

}

void MainWindow::on_pushButton_20_clicked()      //取消消息处理
{
    ui->renmai1->show();
    ui->renmai2->hide();
}


/**********************
//登陆界面判断

***********************/

void MainWindow::on_loginBtn_clicked()
{
    //判断用户名 及 密码 进去主页面

    //要加判断  与数据库中数据对比
    ui->jishi_wid->hide();
    ui->zhangben_wid_2->hide();
    ui->login_wid->hide();
    ui->renmai_swid->hide();
    ui->renmai_swid->hide();
    ui->menu_frame->show();
    ui->main_wid->show();
}



void MainWindow::on_loginBtn_2_clicked()
{
    ui->renmai_swid->hide();
    ui->jishi_wid->hide();
    ui->main_wid->hide();
    ui->zhangben_wid_2->hide();
    ui->login_wid->show();
    ui->renmai_swid->hide();
    ui->menu_frame->hide();
    ui->register_wid->hide();
}

void MainWindow::on_registerBtn_clicked()
{
    ui->renmai_swid->hide();
    ui->jishi_wid->hide();
    ui->main_wid->hide();
    ui->zhangben_wid_2->hide();
    ui->login_wid->hide();
    ui->renmai_swid->hide();
    ui->menu_frame->hide();
    ui->register_wid->show();
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(-5, 5);
    shadow_effect->setColor(Qt::gray);
    shadow_effect->setBlurRadius(8);
    ui->register_wid->setGraphicsEffect(shadow_effect);

}
void MainWindow::on_signoutBtn_clicked()
{
    ui->renmai_swid->hide();
    ui->jishi_wid->hide();
    ui->main_wid->hide();
    ui->zhangben_wid_2->hide();
    ui->login_wid->show();
    ui->renmai_swid->hide();
    ui->menu_frame->hide();
    ui->register_wid->hide();
}


void MainWindow::on_cancelBtn_clicked()
{
   close();
}

void MainWindow::on_cancelBtn_2_clicked()
{
   close();
}

void MainWindow::on_addBtn_clicked()
{
    if(ui->textEdit->toPlainText()!="")
    {
        EveryDayTaskUI *taskui=new EveryDayTaskUI(this);
        QListWidgetItem *mItem=new QListWidgetItem(ui->listWidget_task);
        connect(taskui,SIGNAL(taskSend(EverydayTask)),this,SLOT(taskRec(EverydayTask)));
        connect(taskui,SIGNAL(taskEditSend(EverydayTask)),this,SLOT(taskEditRec(EverydayTask)));
        mItem->setSizeHint(QSize(mItem->sizeHint().width(),70));
        ui->listWidget_task->setItemWidget(mItem,taskui);
        //设置
        QTime myTime;
        myTime=QTime::currentTime();
        QString str=myTime.toString();
        m_everydaytask.setMsg(ui->textEdit->toPlainText(),str,1,0);
        ui->textEdit->setText("");
       //创建一个everyday对象并写入数据库

    }
    else
    {
        QMessageBox *b=new QMessageBox();
        b->setText("不能为空！");
        b->exec();
    }
}

/*各种信号发送函数定义
 * */
void MainWindow::emit_taskSend()
{
    emit taskSend(m_everydaytask);
}

void MainWindow::emit_contactSend()
{
    emit contactSend(m_contact);
}
void MainWindow::emit_essaySend()
{
    emit essaySend(m_essay);
}
void MainWindow::nameRec(QString name)
{
    //删除列表中的当前项
    QListWidgetItem *m=ui->listWidget_contact->currentItem();
    ui->listWidget_contact->removeItemWidget(m);
    delete m;
    ui->lineEdit_name->setText("");
    ui->lineEdit_address->setText("");
    ui->lineEdit_email->setText("");
    ui->lineEdit_job->setText("");
    ui->lineEdit_qq->setText("");
    ui->lineEdit_phone->setText("");
    //删除数据库中姓名为name的记录

}

void MainWindow::contactRec(Contact c)//联系人编辑
{
    //完成编辑
    ui->renmai2->show();
    ui->renmai1->hide();
    ui->lineEdit_name->setText(c.getName());
    ui->lineEdit_address->setText(c.getAddress());
    ui->lineEdit_job->setText(c.getJob());
    ui->lineEdit_phone->setText(c.getPhone());
    ui->dateEdit_bir->setDate(c.getBirthday());
    ui->comboBox->setCurrentText(c.getType());
    ui->lineEdit_email->setText(c.getEmail());
    QListWidgetItem *m=ui->listWidget_contact->currentItem();
    ui->listWidget_contact->removeItemWidget(m);
    delete m;
    //完成编辑后插入数据库

}

void MainWindow::taskRec(EverydayTask e)
{
    //删除列表
    ui->listWidget_task->removeItemWidget(ui->listWidget_task->currentItem());
    delete ui->listWidget_task->currentItem();
    //删除数据库中的数据
}
void MainWindow::taskEditRec(EverydayTask e)
{
    ui->listWidget_task->removeItemWidget(ui->listWidget_task->currentItem());
    delete ui->listWidget_task->currentItem();
    ui->textEdit->setText(e.getTask());
}

void MainWindow::essayDelRec(Essay e)
{
    ui->listWidget_essay->removeItemWidget(ui->listWidget_essay->currentItem());
    delete ui->listWidget_essay->currentItem();
   //删除数据库中的数据
}

void MainWindow::essayEditRec(Essay e)
{
    //设置列表样式
    ui->textEdit_essay->setText(e.get_essay());
    ui->jishi2->show();
    ui->jishi1->hide();
    delete ui->listWidget_essay->currentItem();
}
