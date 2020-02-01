#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sudoku.h"

#include <iostream>
#include <QPushButton>
#include <QPalette>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setUpGridButtons();


    QObject::connect(ui->solveButton, SIGNAL(clicked()),this, SLOT(solveClicked()));
    QObject::connect(ui->resetButton, SIGNAL(clicked()),this, SLOT(resetClicked()));
    QObject::connect(ui->exitButton, SIGNAL(clicked()),this, SLOT(exitClicked()));

    char tbuff[20] = {0};
    std::string buff;
    for (int i = 0; i < 81; ++i)
    {
        sprintf(tbuff, "grid_%02d", i);
        buff = tbuff;
        QObject::connect(grid_buttons[buff], SIGNAL(clicked()),this, SLOT(gridClicked()));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

    if(!current_grid_button)
        return;

    int n = e->key();
    if ((n < 48) || (n > 58))
        return;

    n -= 48;

    int k = atoi(current_grid_button->objectName().toStdString().substr(5,7).c_str());

    grid.set_entry(k, n);

    update_grid();

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

    char tbuff[20] = {0};
    std::string buff;
    for (int i = 0; i < 81; ++i)
    {
        sprintf(tbuff, "grid_%02d", i);
        buff = tbuff;
        grid_buttons[buff]->setText(labels[i]);
    }

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

void MainWindow::gridClicked()
{
    QObject *senderObj = sender(); // This will give Sender object
    QString senderObjName = senderObj->objectName();

    QPalette pal = palette();
    // pal.setColor(QPalette::Button, Qt::cyan);
    pal.setColor(QPalette::Button, QColor(0, 191, 255,255));

    if(current_grid_button)
    {
        current_grid_button->setAutoFillBackground(false);
        current_grid_button->update();
    }

    current_grid_button = grid_buttons[senderObjName.toStdString()];
    current_grid_button->setAutoFillBackground(true);
    current_grid_button->setPalette(pal);
    current_grid_button->update();

}

void MainWindow::setUpGridButtons()
{

    grid_buttons["grid_00"] = ui->grid_00;
    grid_buttons["grid_01"] = ui->grid_01;
    grid_buttons["grid_02"] = ui->grid_02;
    grid_buttons["grid_03"] = ui->grid_03;
    grid_buttons["grid_04"] = ui->grid_04;
    grid_buttons["grid_05"] = ui->grid_05;
    grid_buttons["grid_06"] = ui->grid_06;
    grid_buttons["grid_07"] = ui->grid_07;
    grid_buttons["grid_08"] = ui->grid_08;
    grid_buttons["grid_09"] = ui->grid_09;
    grid_buttons["grid_10"] = ui->grid_10;
    grid_buttons["grid_11"] = ui->grid_11;
    grid_buttons["grid_12"] = ui->grid_12;
    grid_buttons["grid_13"] = ui->grid_13;
    grid_buttons["grid_14"] = ui->grid_14;
    grid_buttons["grid_15"] = ui->grid_15;
    grid_buttons["grid_16"] = ui->grid_16;
    grid_buttons["grid_17"] = ui->grid_17;
    grid_buttons["grid_18"] = ui->grid_18;
    grid_buttons["grid_19"] = ui->grid_19;
    grid_buttons["grid_20"] = ui->grid_20;
    grid_buttons["grid_21"] = ui->grid_21;
    grid_buttons["grid_22"] = ui->grid_22;
    grid_buttons["grid_23"] = ui->grid_23;
    grid_buttons["grid_24"] = ui->grid_24;
    grid_buttons["grid_25"] = ui->grid_25;
    grid_buttons["grid_26"] = ui->grid_26;
    grid_buttons["grid_27"] = ui->grid_27;
    grid_buttons["grid_28"] = ui->grid_28;
    grid_buttons["grid_29"] = ui->grid_29;
    grid_buttons["grid_30"] = ui->grid_30;
    grid_buttons["grid_31"] = ui->grid_31;
    grid_buttons["grid_32"] = ui->grid_32;
    grid_buttons["grid_33"] = ui->grid_33;
    grid_buttons["grid_34"] = ui->grid_34;
    grid_buttons["grid_35"] = ui->grid_35;
    grid_buttons["grid_36"] = ui->grid_36;
    grid_buttons["grid_37"] = ui->grid_37;
    grid_buttons["grid_38"] = ui->grid_38;
    grid_buttons["grid_39"] = ui->grid_39;
    grid_buttons["grid_40"] = ui->grid_40;
    grid_buttons["grid_41"] = ui->grid_41;
    grid_buttons["grid_42"] = ui->grid_42;
    grid_buttons["grid_43"] = ui->grid_43;
    grid_buttons["grid_44"] = ui->grid_44;
    grid_buttons["grid_45"] = ui->grid_45;
    grid_buttons["grid_46"] = ui->grid_46;
    grid_buttons["grid_47"] = ui->grid_47;
    grid_buttons["grid_48"] = ui->grid_48;
    grid_buttons["grid_49"] = ui->grid_49;
    grid_buttons["grid_50"] = ui->grid_50;
    grid_buttons["grid_51"] = ui->grid_51;
    grid_buttons["grid_52"] = ui->grid_52;
    grid_buttons["grid_53"] = ui->grid_53;
    grid_buttons["grid_54"] = ui->grid_54;
    grid_buttons["grid_55"] = ui->grid_55;
    grid_buttons["grid_56"] = ui->grid_56;
    grid_buttons["grid_57"] = ui->grid_57;
    grid_buttons["grid_58"] = ui->grid_58;
    grid_buttons["grid_59"] = ui->grid_59;
    grid_buttons["grid_60"] = ui->grid_60;
    grid_buttons["grid_61"] = ui->grid_61;
    grid_buttons["grid_62"] = ui->grid_62;
    grid_buttons["grid_63"] = ui->grid_63;
    grid_buttons["grid_64"] = ui->grid_64;
    grid_buttons["grid_65"] = ui->grid_65;
    grid_buttons["grid_66"] = ui->grid_66;
    grid_buttons["grid_67"] = ui->grid_67;
    grid_buttons["grid_68"] = ui->grid_68;
    grid_buttons["grid_69"] = ui->grid_69;
    grid_buttons["grid_70"] = ui->grid_70;
    grid_buttons["grid_71"] = ui->grid_71;
    grid_buttons["grid_72"] = ui->grid_72;
    grid_buttons["grid_73"] = ui->grid_73;
    grid_buttons["grid_74"] = ui->grid_74;
    grid_buttons["grid_75"] = ui->grid_75;
    grid_buttons["grid_76"] = ui->grid_76;
    grid_buttons["grid_77"] = ui->grid_77;
    grid_buttons["grid_78"] = ui->grid_78;
    grid_buttons["grid_79"] = ui->grid_79;
    grid_buttons["grid_80"] = ui->grid_80;
}
