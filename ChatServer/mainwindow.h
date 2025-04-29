#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chatserver.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startStopButton_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_gosearch_clicked();

    void on_comboBox_currentIndexChanged(int index);

public slots:
    void logMessage(const QString & msg);

private:
    Ui::MainWindow *ui;
    ChatServer *m_chatServer;

    int m_curIndex;
};
#endif // MAINWINDOW_H
