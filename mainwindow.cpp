#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sudoku.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QObject::connect(ui->solveButton, SIGNAL(clicked()),this, SLOT(solveClicked()));
    QObject::connect(ui->resetButton, SIGNAL(clicked()),this, SLOT(resetClicked()));
    QObject::connect(ui->exitButton, SIGNAL(clicked()),this, SLOT(exitClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::load_grid(SudokuGrid& tmp_grid)
{
    grid = tmp_grid;
    update_grid();
}

void MainWindow::update_grid(bool show_solution)
{
    int n;
    QString labels[81];
    for (int i = 0; i < 81; ++i)
    {
        if (show_solution)
            n = grid.get_solution(i);
        else
            n = grid.get_entry(i);

        if (n != 0)
            labels[i] = QString::number(n);
        else
            labels[i] = " ";
    }

    ui->grid_00->setText(labels[0]);
    ui->grid_01->setText(labels[1]);
    ui->grid_02->setText(labels[2]);

    ui->grid_03->setText(labels[3]);
    ui->grid_04->setText(labels[4]);
    ui->grid_05->setText(labels[5]);

    ui->grid_06->setText(labels[6]);
    ui->grid_07->setText(labels[7]);
    ui->grid_08->setText(labels[8]);

    ui->grid_09->setText(labels[9]);
    ui->grid_10->setText(labels[10]);
    ui->grid_11->setText(labels[11]);

    ui->grid_12->setText(labels[12]);
    ui->grid_13->setText(labels[13]);
    ui->grid_14->setText(labels[14]);

    ui->grid_15->setText(labels[15]);
    ui->grid_16->setText(labels[16]);
    ui->grid_17->setText(labels[17]);

    ui->grid_18->setText(labels[18]);
    ui->grid_19->setText(labels[19]);
    ui->grid_20->setText(labels[20]);

    ui->grid_21->setText(labels[21]);
    ui->grid_22->setText(labels[22]);
    ui->grid_23->setText(labels[23]);

    ui->grid_24->setText(labels[24]);
    ui->grid_25->setText(labels[25]);
    ui->grid_26->setText(labels[26]);
    ui->grid_27->setText(labels[27]);
    ui->grid_28->setText(labels[28]);
    ui->grid_29->setText(labels[29]);

    ui->grid_30->setText(labels[30]);
    ui->grid_31->setText(labels[31]);
    ui->grid_32->setText(labels[32]);

    ui->grid_33->setText(labels[33]);
    ui->grid_34->setText(labels[34]);
    ui->grid_35->setText(labels[35]);

    ui->grid_36->setText(labels[36]);
    ui->grid_37->setText(labels[37]);
    ui->grid_38->setText(labels[38]);

    ui->grid_39->setText(labels[39]);
    ui->grid_40->setText(labels[40]);
    ui->grid_41->setText(labels[41]);

    ui->grid_42->setText(labels[42]);
    ui->grid_43->setText(labels[43]);
    ui->grid_44->setText(labels[44]);

    ui->grid_45->setText(labels[45]);
    ui->grid_46->setText(labels[46]);
    ui->grid_47->setText(labels[47]);

    ui->grid_48->setText(labels[48]);
    ui->grid_49->setText(labels[49]);
    ui->grid_50->setText(labels[50]);

    ui->grid_51->setText(labels[51]);
    ui->grid_52->setText(labels[52]);
    ui->grid_53->setText(labels[53]);

    ui->grid_54->setText(labels[54]);
    ui->grid_55->setText(labels[55]);
    ui->grid_56->setText(labels[56]);

    ui->grid_57->setText(labels[57]);
    ui->grid_58->setText(labels[58]);
    ui->grid_59->setText(labels[59]);

    ui->grid_60->setText(labels[60]);
    ui->grid_61->setText(labels[61]);
    ui->grid_62->setText(labels[62]);

    ui->grid_63->setText(labels[63]);
    ui->grid_64->setText(labels[64]);
    ui->grid_65->setText(labels[65]);

    ui->grid_66->setText(labels[66]);
    ui->grid_67->setText(labels[67]);
    ui->grid_68->setText(labels[68]);

    ui->grid_69->setText(labels[69]);
    ui->grid_70->setText(labels[70]);
    ui->grid_71->setText(labels[71]);

    ui->grid_72->setText(labels[72]);
    ui->grid_73->setText(labels[73]);
    ui->grid_74->setText(labels[74]);

    ui->grid_75->setText(labels[75]);
    ui->grid_76->setText(labels[76]);
    ui->grid_77->setText(labels[77]);

    ui->grid_78->setText(labels[78]);
    ui->grid_79->setText(labels[79]);
    ui->grid_80->setText(labels[80]);
}

void MainWindow::solveClicked()
{
    grid.solve();
    update_grid(true);
}

void MainWindow::resetClicked()
{
    update_grid();
}

void MainWindow::exitClicked()
{
    close();
    qApp->quit();
}
