//
// Created by dor on 1/15/20.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H


#include <vector>
#include <string>

class Matrix {
private:
    int rows, columns;

    std::vector<std::vector<int>> matrix;

    std::string string_representaion;

public:
    Matrix();

    void addRow(const std::vector<int>&);

    int getRows() const;

    int getColumns() const;

    const std::vector<std::vector<int>> &getMatrix() const;

    const std::vector<int>& getRow(int) const;

    const std::string &getStringRepresentaion() const;

};


#endif //EX4_MATRIX_H
