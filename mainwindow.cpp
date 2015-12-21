#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _graphController = new GraphController();
    _graphGenerator = new GraphGenerator(_graphController);
    _graphDrawer = new GraphDrawer(_graphController->graph());
    _kernighanLin = new KernighanLin(_graphController->graph());
    _analyzer = new Analyzer(_kernighanLin);

    ui->graphicsView->setScene(_graphDrawer);

    _verticesNamesModel = new QStringListModel();
    loadVerticesNames();

    ui->numOfThreadsSpin->setRange(1, 8);
    ui->numOfThreadsSlider->setRange(
                ui->numOfThreadsSpin->minimum(),
                ui->numOfThreadsSpin->maximum());

    ui->numOfPartitionsSpin->setRange(1, 10);
    ui->numOfPartitionsSlider->setRange(
                ui->numOfPartitionsSpin->minimum(),
                ui->numOfPartitionsSpin->maximum());

    connect(ui->numOfThreadsSpin,
            SIGNAL(valueChanged(int)),
            ui->numOfThreadsSlider,
            SLOT(setValue(int)));

    connect(ui->numOfThreadsSlider,
            SIGNAL(valueChanged(int)),
            ui->numOfThreadsSpin,
            SLOT(setValue(int)));

    connect(ui->numOfPartitionsSpin,
            SIGNAL(valueChanged(int)),
            ui->numOfPartitionsSlider,
            SLOT(setValue(int)));

    connect(ui->numOfPartitionsSlider,
            SIGNAL(valueChanged(int)),
            ui->numOfPartitionsSpin,
            SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _graphController;
    delete _graphGenerator;
    delete _graphDrawer;
    delete _kernighanLin;
    delete _analyzer;
    delete _verticesNamesModel;
}

void MainWindow::on_addVertexButton_clicked()
{
    QString id = ui->vertexId->text();
    _graphController->addVertex(id);
    _graphController->completeConnectVertex(id);
    loadVerticesNames();

    _graphDrawer->draw();
}

void MainWindow::on_addEdgeButton_clicked()
{
    QString id1 = ui->edgeVertex1Id->currentText();
    QString id2 = ui->edgeVertex2Id->currentText();
    int weight = ui->edgeWeight->value();

    // TODO: Set coordianates of vertices

    _graphController->addEdge(id1, id2, weight);
}

void MainWindow::loadVerticesNames()
{
    _verticesNamesModel->setStringList(
                _graphController->graph()->vertices().keys());

    ui->edgeVertex1Id->setModel(_verticesNamesModel);
    ui->edgeVertex2Id->setModel(_verticesNamesModel);
}

void MainWindow::on_generateButton_clicked()
{
    int vertices = ui->numOfVertices->value();

    _graphGenerator->generate(vertices);
    _graphDrawer->draw();
}

void MainWindow::on_runButton_clicked()
{
    _kernighanLin->run();
}
