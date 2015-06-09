#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstring.h"
#include "qfiledialog.h"
#include "history.h"
#include "convert.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->select_csv_Button, SIGNAL(clicked()), this, SLOT(Select_csv()));
    QObject::connect(ui->select_directory_Button, SIGNAL(clicked()), this, SLOT(Select_directory()));
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

void MainWindow::Open_history()
{

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
