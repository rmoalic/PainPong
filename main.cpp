#include "mainwindow.h"
#include "constantes.h"
#include "gamewidget.h"
#include <QApplication>
#include <QtDebug>

const QString APP_NAME ="PainPong";
const QString APP_VERSION = "DEV-1";

int main(int argc, char *argv[])
{
    qSetMessagePattern("[%{time hh:mm:ss.zzz} %{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}%{threadid}]%{file}:%{line} - %{message}");
    QApplication a(argc, argv);
    a.setApplicationName(APP_NAME);
    a.setApplicationVersion(APP_VERSION);
    MainWindow w;

    w.setFixedSize(QSize(WINDOW_WIDTH, WINDOW_HEIGHT));
    w.show();
    w.setWindowTitle(APP_NAME);

    w.start();

    qDebug() << "Starting " + APP_NAME;
    return a.exec();
}
