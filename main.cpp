#include "sudoku.h"

int main(int argc, char *argv[])
{

    SudokuGrid grid;

    grid.print_grid();
    // grid.print_boxes();
    // grid.print_rows();
    // grid.print_cols();

    // grid.validate();

    // grid.get_valid_numbers(1);
    grid.solve();

    return 0;
}
