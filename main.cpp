#include "mainwindow.h"
#include "sudoku.h"

#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{

    SudokuGrid grid;

    if (argc > 1)
    {
        std::string filename = argv[1];
        grid.load_file(filename);
    }

    QApplication a(argc, argv);
    MainWindow w;

    w.load_grid(grid);
    w.show();
    return a.exec();
}
