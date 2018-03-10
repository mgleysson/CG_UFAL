#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "defines.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("CG OpenGL Project");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        _eqRetaOrBresenham = EQRETA;
    } else {
        _eqRetaOrBresenham = BRESENHAM;
    }
    _color[0] = ui->doubleSpinBox->value();
    _color[1] = ui->doubleSpinBox_2->value();
    _color[2] = ui->doubleSpinBox_3->value();
    _tam = ui->spinBox->value();
}
