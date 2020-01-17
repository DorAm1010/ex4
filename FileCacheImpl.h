//
// Created by dor on 1/16/20.
//

#ifndef EX4_FILECACHEIMPL_H
#define EX4_FILECACHEIMPL_H

#include <fstream>
#include <unordered_map>
#include "CacheManager.h"

template<typename P, typename S>
class FileCacheManager : public CacheManager<P, S> {
    static int solution_count;
    std::fstream save_file;
    std::unordered_map<std::string , std::string> fileMap;

    FileCacheManager() {
        solution_count = 0;
    }

    bool hasSolution(P p) override {
        std::string key = p.to_string();
        return fileMap.find(key) != fileMap.end();
    }

    S getSolution(P p) override {
        if (!hasSolution(p)) {
            throw "No solution for problem!";
        }
        std::string key = p.to_string();

        S object;
        // exists in file system
        save_file.open("Solution" + solution_count, std::ios::in | std::ios::binary);

        if (!save_file) {
            throw "Unable To Open File At get()";
        }

        save_file.read((char *) &object, sizeof(object));
        save_file.close();

        return object;
    }

    void saveSolution(S solution, P problem) override {
        std::string key = problem.to_string();
        fileMap[key] = "Solution" + solution_count;

        // update in file system
        save_file.open("Solution" + solution_count, std::ios::out | std::ios::binary);
        if (!save_file) {
            throw "Unable To Open File At insert()";
        }
        save_file.write((char*)&solution, sizeof(solution));
        save_file.close();
        solution_count++;
    }
};
#endif //EX4_FILECACHEIMPL_H
