////
//// Created by dor on 1/15/20.
////
//
//#include "MyClientHandler.h"
//
//using namespace std;
//
//void MyClientHandler::handleClient(int socket) {
//    string output;
//    char buffer[1024];
//    char* input_info;
//    vector<int> matrix_rows;
//    Matrix matrix;
//    bool row_defined = false;
//    int start_x = 0, start_y = 0, end_x = 0, end_y = 0;
//
//    // read from client
//    int valread = read(socket, buffer, 1024);
//    if (valread == -1)
//        cout << "Could Not Read Client Input" << endl;
//
//    // drop \n char
//    input_info = strtok(buffer, " ,\n");
//
//    while (strcmp(input_info, "end") != 0) {
//        while (input_info != nullptr) {
//            input_info = strtok(nullptr, " ,");
//            try {
//                matrix_rows.push_back(atoi(input_info));
//            } catch (exception e) {
//                cout << "Error converting to integer at MyClientHandler";
//                cout << e.what() << endl;
//                return;
//            }
//        }
//
//        if (matrix_rows.size() > 2) {
//            // add another row to matrix
//            matrix.addRow(matrix_rows);
//        } else {
//            // get start and end points, meaning we now know matrix_tows contains
//            // (start_point_i, start_point_j), and next values will be
//            // (end_point-i, end_point_j)
//
//            start_x = matrix_rows.at(0);
//            start_y = matrix_rows.at(1);
//
//            valread = read(socket, buffer, 1024);
//            if (valread == -1)
//                cout << "Could Not Read Client Input" << endl;
//
//            input_info = strtok(buffer, " ,\n");
//            end_x = atoi(input_info);
//
//            input_info = strtok(nullptr, " ,");
//            end_y = atoi(input_info);
//        }
//
//        valread = read(socket, buffer, 1024);
//        if (valread == -1)
//            cout << "Could Not Read Client Input" << endl;
//
//        input_info = strtok(buffer, " ,\n");
//    }
//
//    MatrixProblem matrixProblem(matrix, Point(start_x, start_y), Point(end_x, end_y));
//
//    Solution solution;
//    if (!cacheManager->hasSolution(matrixProblem)) {
//        solution = solver->solve(matrixProblem);
//        cacheManager->saveSolution(solution, matrixProblem);
//    } else {
//        solution = cacheManager->getSolution(matrixProblem);
//    }
//}
//
