#ifndef EVERYDAYTASKUI_H
#define EVERYDAYTASKUI_H

#include <QWidget>
#include "everydaytask.h"
#include <QMenu>

namespace Ui {
class EveryDayTaskUI;
}

class EveryDayTaskUI : public QWidget
{
    Q_OBJECT

public:
    explicit EveryDayTaskUI(QWidget *parent = 0);
    ~EveryDayTaskUI();
public slots:
    void task_rec(EverydayTask t);
    void contextMenuEvent(QContextMenuEvent* event);
    void emit_taskSend();
    void emit_taskEditSend();

private:
    Ui::EveryDayTaskUI *ui;
    int only;//互斥
    QAction *m_delete;
    QAction *m_edit;
    EverydayTask thisTask;
signals:
    void taskSend(EverydayTask ta);
    void taskEditSend(EverydayTask t);
};

#endif // EVERYDAYTASKUI_H
