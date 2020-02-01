#include "sudoku.h"
#include <iostream>

int main(int argc, char *argv[])
{

    std::string filename;

    if (argc > 1)
        filename = argv[1];
    else
        return -1;


    SudokuGrid grid;
    grid.load_file(filename);
    grid.print_grid();
    // grid.print_boxes();
    // grid.print_rows();
    // grid.print_cols();

    // grid.validate();

    // grid.get_valid_numbers(1);
    grid.solve();

    return 0;
}
