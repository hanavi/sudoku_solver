#include "sudoku.h"

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>



SudokuGrid::SudokuGrid()
{
    // for (int i = 0; i < 9; ++i)
    // {
    //     for( int j = 0; j < 9; ++j )
    //     {
    //         grid.push_back( get_box(i*9 + j));
    //     }
    // }

    grid = { 6, 0, 0, 0, 3, 0, 0, 4, 0,
             0, 0, 0, 0, 0, 2, 7, 0, 8,
             0, 0, 0, 1, 0, 0, 0, 6, 0,
             0, 0, 5, 6, 0, 0, 0, 9, 0,
             8, 0, 0, 0, 7, 0, 0, 0, 4,
             0, 7, 0, 0, 0, 1, 3, 0, 0,
             0, 2, 0, 0, 0, 7, 0, 0, 0,
             9, 0, 3, 4, 0, 0, 0, 0, 0,
             0, 8, 0, 0, 2, 0, 0, 0, 9 };

    // grid = { 0, 0, 0, 0, 0, 1, 0, 0, 2,
    //          0, 0, 3, 0, 0, 0, 0, 4, 0,
    //          0, 5, 0, 0, 6, 0, 7, 0, 0,
    //          0, 0, 0, 8, 0, 0, 0, 7, 0,
    //          0, 0, 7, 0, 0, 3, 8, 0, 0,
    //          9, 0, 0, 0, 5, 0, 0, 0, 1,
    //          0, 0, 6, 0, 8, 0, 2, 0, 0,
    //          0, 4, 0, 6, 0, 0, 0, 0, 7,
    //          2, 0, 0, 0, 0, 9, 0, 6, 0 };
}

int SudokuGrid::get_row(int n)
{
    return (n / 9) ;
}

int SudokuGrid::get_column(int n)
{
    return (n % 9);
}

int SudokuGrid::get_box(int n)
{
    int row = get_row(n);
    int col = get_column(n);

    return ((row / 3)*3 + col / 3);
}

std::unique_ptr<std::vector<int>> SudokuGrid::get_elements_col(int n)
{
    auto v = std::make_unique<std::vector<int>>();

    for (int i = 0; i < 81; ++i)
    {
        if (get_column(i) == n)
            v->push_back(grid[i]);
    }

    return v;
}

std::unique_ptr<std::vector<int>> SudokuGrid::get_elements_row(int n)
{
    auto v = std::make_unique<std::vector<int>>();

    for (int i = 0; i < 81; ++i)
    {
        if (get_row(i) == n)
            v->push_back(grid[i]);
    }

    return v;
}

std::unique_ptr<std::vector<int>> SudokuGrid::get_elements_box(int n)
{
    auto v = std::make_unique<std::vector<int>>();

    for (int i = 0; i < 81; ++i)
    {
        if (get_box(i) == n)
            v->push_back(grid[i]);
    }

    return v;
}

void SudokuGrid::print_grid()
{
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            std::cout << " " << grid[i*9 + j] ;
            if (((i*9+j) % 3) == 2)
                std::cout << " ";

        }
        std::cout << std::endl;
        if ((i % 3) == 2)
            std::cout << std::endl;
    }
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;

}

void SudokuGrid::print_boxes()
{
    std::cout << std::endl;
    std::cout << "Boxes" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    for (int i = 0; i < 9; ++i)
    {
        auto v = get_elements_box(i);

        std::cout << "Box " << i << ": ";

        for (auto v0 : *v)
            std::cout << v0 << " ";

        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;
}

void SudokuGrid::print_rows()
{
    std::cout << std::endl;
    std::cout << "Rows" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    for (int i = 0; i < 9; ++i)
    {
        auto v = get_elements_row(i);

        std::cout << "row " << i << ": ";

        for (auto v0 : *v)
            std::cout << v0 << " ";

        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;
}

void SudokuGrid::print_cols()
{
    std::cout << std::endl;
    std::cout << "Columns" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    for (int i = 0; i < 9; ++i)
    {
        auto v = get_elements_col(i);

        std::cout << "col " << i << ": ";

        for (auto v0 : *v)
            std::cout << v0 << " ";

        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;
}


void SudokuGrid::validate()
{
    std::cout << std::endl;
    std::cout << "Validating" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    for (int i = 0; i < 9; ++i)
    {
        auto row = get_elements_row(i);
        for (auto elem: *row)
        {
            if (elem == 0)
                continue;

            int n = std::count(row->begin(), row->end(), elem);
            if (n > 1)
            {
                std::cout << "Invalid row: " << i << std::endl;
                break;
            }
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        auto col = get_elements_col(i);
        for (auto elem: *col)
        {
            if (elem == 0)
                continue;

            int n = std::count(col->begin(), col->end(), elem);
            if (n > 1)
            {
                std::cout << "Invalid column: " << i << std::endl;
                break;
            }
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        auto box = get_elements_box(i);
        for (auto elem: *box)
        {
            if (elem == 0)
                continue;

            int n = std::count(box->begin(), box->end(), elem);
            if (n > 1)
            {
                std::cout << "Invalid Box: " << i << std::endl;
                break;
            }
        }
    }
    std::cout << "-----------------------------------------" << std::endl;
}

std::unique_ptr<std::vector<int>> SudokuGrid::get_valid_numbers(int n)
{
    auto out = std::make_unique<std::vector<int>>();

    auto row = get_elements_row(get_row(n));
    auto col = get_elements_col(get_column(n));
    auto box = get_elements_box(get_box(n));

    int r = 0;
    int c = 0;
    int b = 0;

    for (int i = 1; i < 10; ++i)
    {
        r = std::count(row->begin(), row->end(), i);
        c = std::count(col->begin(), col->end(), i);
        b = std::count(box->begin(), box->end(), i);

        if ( r+b+c  == 0)
            out->push_back(i);

    }

    return out;
}

void SudokuGrid::solve(int i)
{
    if (finished)
        return;

    // std::cout << "working on : " << i << std::endl;

    if (i == 81)
    {
        finished = true;
        print_grid();
        return;
    }

    if (grid[i] != 0)
        solve(i + 1);

    else
    {
        auto valid = get_valid_numbers(i);

        if (valid->size() == 0)
            return;
        else
        {
            for (auto elem : *valid)
            {
                grid[i] = elem;
                solve(i + 1);
            }
            grid[i] = 0;
        }
    }
}
