#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
#include <memory>
#include <vector>

class SudokuGrid
{
public:

    SudokuGrid();
    ~SudokuGrid(){};

    void load_file(std::string filename);

    int get_row(int n);
    int get_column(int n);
    int get_box(int n);

    std::unique_ptr<std::vector<int>> get_elements_col(int n);
    std::unique_ptr<std::vector<int>> get_elements_row(int n);
    std::unique_ptr<std::vector<int>> get_elements_box(int n);

    void print_grid();
    void print_boxes();
    void print_rows();
    void print_cols();
    void validate();

    int get_entry(int n);
    int get_solution(int n);

    std::unique_ptr<std::vector<int>> get_valid_numbers(int n);
    void solve(int i = 0);


private:
    std::vector<int> grid;
    std::vector<int> solved_grid;

    bool finished = false;

};

#endif
