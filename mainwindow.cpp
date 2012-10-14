#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace twoDimensional;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    QObject::connect(ui->pushButton, SIGNAL(clicked()), SLOT(buttonReceiver()));
}

void MainWindow::buttonReceiver()
{
    try {
        SimpleIterationScheme *scheme = new SimpleIterationScheme(10, 10, 0.0, 1.0, 0.0, 1.0);
        scheme->execute(0.001);
        scheme->printConsole();
        delete scheme;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

    //scheme->printConsole();
}
