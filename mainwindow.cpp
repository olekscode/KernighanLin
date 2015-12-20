#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //_graphGenerator = new GraphGenerator();
    _graphController = new GraphController();
    _graphDrawer = new GraphDrawer(_graphController->graph());
    _kernighanLin = new KernighanLin(_graphController->graph());
    _analyzer = new Analyzer(_kernighanLin);

    ui->graphicsView->setScene(_graphDrawer);

    _verticesNamesModel = new QStringListModel(
                _graphController->graph()->vertices().keys());

    ui->edgeVertex1Id->setModel(_verticesNamesModel);
    ui->edgeVertex2Id->setModel(_verticesNamesModel);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _graphController;
    delete _graphDrawer;
    delete _kernighanLin;
    delete _analyzer;
    delete _verticesNamesModel;
}

void MainWindow::on_addVertexButton_clicked()
{
    _graphController->addVertex(ui->vertexId->text());
}
