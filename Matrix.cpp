//
// Created by dor on 1/15/20.
//

#include "Matrix.h"
using namespace std;
Matrix::Matrix() {
    rows = 0;
    columns = 0;
}

/**
 * add a row to the matrix.
 * @param values vector of values in the new row.
 */
void Matrix::addRow(const std::vector<int>& values) {
    // matrix columns size was initialized
    int row_size = values.size();
    if (!(columns > 0 && row_size > columns)) {
        columns = row_size;
    } else {
        throw "Error in matrix input value";
    }
    rows++;
    matrix.push_back(values);
    for(int i = 0; i < row_size; i++) {
        if (i == row_size - 1) {
            string_representaion += to_string(values.at(i)) + "\n";
        } else {
            string_representaion += to_string(values.at(i)) + ", ";
        }
    }
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

const vector<std::vector<int>> &Matrix::getMatrix() const {
    return matrix;
}

const std::vector<int> &Matrix::getRow(int i) const {
    if (i < rows)
        return matrix.at(i);
    throw "Error accessing row in matrix";
}

const string &Matrix::getStringRepresentaion() const {
    return string_representaion;
}

