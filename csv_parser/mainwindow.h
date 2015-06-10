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
    char* header_csv_popup = "CSV";
    char* text_csv_popup = "Нажмите на кнопку 'Выбрать csv', чтобы выбрать csv фаил который вы хотите преобразовать";
    char* header_html_popup = "HTML директория";
    char* text_html_popup = "Нажмите на кнопку 'Выбрать директорию html', чтобы выбрать место куда будет сохранен html";
    char* header_history_popup = "История";
    char* text_history_popup = "Здесь хронится история всех преобразованых файлов";
private:
    Ui::MainWindow *ui;
public slots:
    void Select_csv();
    void Select_directory();
    void Show_popup(char* header, char* text);

private slots:
    void on_history_Button_clicked();
    void on_convert_Button_clicked();
};


#endif // MAINWINDOW_H
