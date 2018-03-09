#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    _tam = ui->spinBox->value();
    _color[0] = ui->doubleSpinBox->value();
    _color[1] = ui->doubleSpinBox_2->value();
    _color[2] = ui->doubleSpinBox_3->value();
}
