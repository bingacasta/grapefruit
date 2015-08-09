void on_cancelBtn_clicked();
void on_addBtn_3_clicked();
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "everydaytask.h"
#include "everydaytaskui.h"
//联系人头文件
#include "contact.h"
#include "contactui.h"
//记事头文件
#include "essay.h"
#include "essayui.h"


class QPoint;       //定义一个Qpoint类
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /*自定义窗口*/
    void mousePressEvent(QMouseEvent *);        //自定义一个鼠标点击事件函数
    void mouseMoveEvent(QMouseEvent *);         //自定义一个鼠标拖动事件函数

    void on_renmaiBtn_clicked();
    void on_richengBtn_clicked();

    void on_loginBtn_clicked();

    void on_jishiBtn_clicked();

    void on_zhangbenBtn_clicked();

    void on_loginBtn_2_clicked();

    void on_registerBtn_clicked();

    void on_signoutBtn_clicked();

    void on_incomeBtn_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_7_clicked();

    void on_sureBtn_clicked();

    void on_pushButton_20_clicked();

    void on_outcomeBtn_clicked();

    void on_minBtn_clicked();

    void on_closeBtn_clicked();
    void on_addBtn_3_clicked();

    void on_saveBtn_clicked();

    void on_cancelBtn_4_clicked();

    void on_addBtn_6_clicked();

    void on_okBtn_2_clicked();

    void on_cancelBtn_6_clicked();

    void on_cancelBtn_clicked();

    void on_cancelBtn_2_clicked();

    void emit_taskSend();//发送task信号
    void emit_contactSend();//发送联系人信号
    void emit_essaySend();//发送essay信号

    void nameRec(QString name);//接收删除函数
    void contactRec(Contact name);//接收编辑消息
    void taskRec(EverydayTask e);//接收删除消息
    void taskEditRec(EverydayTask e);//接收编辑消息
    void essayDelRec(Essay e);//接收删除消息
    void essayEditRec(Essay e);//接受编辑消息

    void on_addBtn_clicked();

signals:
    void taskSend(EverydayTask t);//定义信号
    void contactSend(Contact c);//定义联系人信号
    void essaySend(Essay e);//定义文章信号

private:
    Ui::MainWindow *ui;
    QPoint dragPosition;
    EverydayTask m_everydaytask;//每日任务对象
    Contact m_contact;//联系人对象
    Essay m_essay;//文章对象
};

#endif // MAINWINDOW_H
