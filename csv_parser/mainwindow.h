#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
public slots:
    void Select_csv();
    void Select_directory();
    void Show_html_popup();
    void Show_csv_popup();
    void Show_history_popup();

private slots:
    void on_history_Button_clicked();
    void on_convert_Button_clicked();
};


#endif // MAINWINDOW_H
