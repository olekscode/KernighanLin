#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

//#include "graphgenerator.h"
#include "graphcontroller.h"
#include "graphdrawer.h"
#include "kernighanlin.h"
#include "analyzer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addVertexButton_clicked();

private:
    Ui::MainWindow *ui;

    //GraphGenerator* _graphGenerator;
    GraphController* _graphController;
    GraphDrawer* _graphDrawer;
    KernighanLin* _kernighanLin;
    Analyzer* _analyzer;

    QStringListModel* _verticesNamesModel;
};

#endif // MAINWINDOW_H
