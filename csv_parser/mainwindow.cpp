#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstring.h"
#include "qfiledialog.h"
#include "history.h"
#include "convert.h"
#include "qmessagebox.h"
#include "popup.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->select_csv_Button, SIGNAL(clicked()), this, SLOT(Select_csv()));
    QObject::connect(ui->select_directory_Button, SIGNAL(clicked()), this, SLOT(Select_directory()));
    QObject::connect(ui->history_info, SIGNAL(clicked()), this, SLOT(Show_popup(header_history_popup,text_history_popup)));
    QObject::connect(ui->csv_info, SIGNAL(clicked()), this, SLOT(Show_popup(header_csv_popup,text_csv_popup)));
    QObject::connect(ui->html_info, SIGNAL(clicked()), this, SLOT(Show_popup(header_html_popup,text_html_popup)));
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
    Convert.exec();
}

void MainWindow::Show_popup(char* header, char* text)
{
    QMessageBox::information(this,tr(header),tr(text));
}
