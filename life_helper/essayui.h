#ifndef ESSAYUI_H
#define ESSAYUI_H

#include <QWidget>
#include "essay.h"
#include <QMenu>

namespace Ui {
class EssayUI;
}

class EssayUI : public QWidget
{
    Q_OBJECT

public:
    explicit EssayUI(QWidget *parent = 0);
    ~EssayUI();
public slots:
    void essayRec(Essay t);
    void contextMenuEvent(QContextMenuEvent* event);
    void emit_essayDelSend();
    void emit_essayEditSend();
signals:
    void essayDelSend(Essay e);
    void essayEditSend(Essay e);


private:
    Ui::EssayUI *ui;
    Essay thisEssay;
    QAction *m_delete;
    QAction *m_edit;
    int only;
};

#endif // ESSAYUI_H
