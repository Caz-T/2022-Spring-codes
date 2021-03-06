#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_plusbutton_clicked();
    void on_minusbutton_clicked();
    void on_mulbutton_clicked();
    void on_divbutton_clicked();

private:
    Ui::MainWindow *ui;
    bool checklegality();
    void showans(double num);
};
#endif // MAINWINDOW_H
