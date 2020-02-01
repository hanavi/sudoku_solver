#include "mainwindow.h"
#include "sudoku.h"

#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{
    if (argc == 1)
        exit(-1);

    std::string filename = argv[1];

    QApplication a(argc, argv);
    MainWindow w;

    SudokuGrid grid;
    grid.load_file(filename);

    w.load_grid(grid);
    w.show();
    return a.exec();
}
