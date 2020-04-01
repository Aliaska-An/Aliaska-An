#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
   // QObject::connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), ui->MyGLWidget, SLOT(changeShapePicture(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getComboBoxValue()
{

    return ui->comboBox->currentText();
}
