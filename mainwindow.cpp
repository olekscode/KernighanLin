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
    _graphDrawer->drawVertex(id);
    loadVerticesNames();
}

void MainWindow::on_addEdgeButton_clicked()
{
    QString id1 = ui->edgeVertex1Id->currentText();
    QString id2 = ui->edgeVertex2Id->currentText();
    int weight = ui->edgeWeight->value();

    // TODO: Set coordianates of vertices

    _graphController->addEdge(id1, id2, weight);
    _graphDrawer->drawEdge(id1, id2);
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
    int edges = ui->numOfEdges->value();

    _graphGenerator->generate(vertices, edges);

    // TODO: Replace this with something better
    foreach (QString id, _graphController->graph()->vertices().keys()) {
        _graphDrawer->drawVertex(id);
    }
}
