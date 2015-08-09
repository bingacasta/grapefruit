#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <qpalette.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("生活小助手");

    w.show();

    /**********
    QMainWindow window;

        window.setWindowFlags(window.windowFlags()

                & ~Qt::WindowMaximizeButtonHint

                & ~Qt::WindowMinimizeButtonHint

                );

        int titleBarHeight =

        QApplication::style()->pixelMetric(QStyle::PM_TitleBarHeight);

        QRect rect = QApplication::desktop()->availableGeometry();

        rect.setTop(rect.top() + titleBarHeight);

        window.setGeometry(rect);

        window.setFixedSize(window.size());

        window.showMaximized();
        *********/
    return a.exec();
}
