#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // message box
#include "secdialog.h" // the header file for the second window

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // the code for changing the horizontalSlider and progressBar at the same time
        // which also can be done in the visual windows editor
        connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Change the label text when the button is clicked.
    // ui->label->setText("Hi~");

    // Besides the simple text above, HTML text is allowed to show also.
    ui->label->setText("<html><b><u>T</u>wo</b><br>lines</html>");
}

void MainWindow::on_pushButton_2_clicked()
{
    // Show a information message box when the button is clicked
    // "information" can be changed to "warning", "question" or "critical"
    // "tr" here means "translate" and the string in the parenthesis can be used universally
    QMessageBox::information(this, tr("THE TITLE"), tr("This is a message"));
}

void MainWindow::on_pushButton_3_clicked()
{
    // One way to open a new window
    // The main window cannot be changed when the new window is open
    // ----initialize a new object of a new window class
    /*
    SecDialog secdialog;
    secdialog.setModal(true);
    secdialog.exec();
    */

    // The other way: change the "mainwindow.hpp" first
    // The second way to open a new window Step 3
    // All the windows can be operated on at the same time
    secdialog = new SecDialog(this);
    secdialog->show();
}
