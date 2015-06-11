#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstring.h"
#include "qfiledialog.h"
#include "history.h"
#include "convert.h"
#include "qmessagebox.h"
#include "popup.h"
#include <string>

#include <QDebug>
#include "parsersession.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->select_csv_Button, SIGNAL(clicked()), this, SLOT(Select_csv()));
    QObject::connect(ui->select_directory_Button, SIGNAL(clicked()), this, SLOT(Select_directory()));
    QObject::connect(ui->history_info, SIGNAL(clicked()), this, SLOT(Show_history_popup()));
    QObject::connect(ui->csv_info, SIGNAL(clicked()), this, SLOT(Show_csv_popup()));
    QObject::connect(ui->html_info, SIGNAL(clicked()), this, SLOT(Show_html_popup()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Select_csv()
{
    QString select_csv_Edit = QFileDialog::getOpenFileName(0, "Выберите фаил", "", "*.csv");
    ui->select_csv_Edit->setText(select_csv_Edit);
}

void MainWindow::Select_directory()
{
    QString Select_directory = QFileDialog::getExistingDirectory(0, "Directory Dialog", "");
    ui->select_directory_Edit->setText(Select_directory);
}

void MainWindow::on_history_Button_clicked()
{
    History history;
    history.setModal(true);
    history.exec();
}

void MainWindow::on_convert_Button_clicked()
{
    convert Convert;
    Convert.setModal(true);

    QString csvDir = "/Users/anna/Desktop/Untitled.csv";
    QString htmlDir = "/Users/anna/Desktop/";

    ParserSession* ps = new ParserSession(csvDir, htmlDir);
    if (ps->start()) {
        qDebug() << "success!";
    } else {
        qDebug() << "failure!";
    }

    Convert.exec();
}

void MainWindow::Show_csv_popup()
{
    QMessageBox::information(
                this,
                tr("CSV"),
                tr("Источники в файле .csv должны быть оформлены следующим образом:\n"
                   "1. Для книг: формат “0;Автор(ы);Название;Место издания;Издательство;Год издания.\n"
                   "2. Для статей: “1;Автор(ы);Название статьи;Название источника;Год выпуска;Номер выпуска;Диапазон стр.”\n"
                   "3. Для URL: “2;Автор(ы);Название статьи;Год публикации;День и месяц прописью;Название ресурса;URL;Дата обращения”.\n"
                   "Если автор зарубежный, укажите оригинальное написание его имени через “/“."));
}

void MainWindow::Show_html_popup()
{
    QMessageBox::information(
                this,
                tr("HTML директория"),
                tr("Нажмите на кнопку 'Выбрать директорию html', чтобы выбрать место, куда будет сохранен html"));
}

void MainWindow::Show_history_popup()
{
    QMessageBox::information(
                this,
                tr("История"),
            tr("Здесь хранится история всех преобразованых файлов"));
}
