#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <map>
#include <string>

#include "sudoku.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void load_grid(SudokuGrid& grid);
    void update_grid(bool show_solution = false);

public slots:
  void solveClicked();
  void exitClicked();
  void resetClicked();

  void gridClicked();

private:
  void setUpGridButtons();
  Ui::MainWindow *ui;
  SudokuGrid grid;

  std::map<std::string, QPushButton *> grid_buttons;

  QPushButton *current_grid_button = nullptr;

protected:
  void keyPressEvent(QKeyEvent *);

};
#endif // MAINWINDOW_H
