//
// Created by dor on 1/16/20.
//

#ifndef EX4_FILECACHEIMPL_H
#define EX4_FILECACHEIMPL_H

#include <fstream>
#include <unordered_map>
#include "CacheManager.h"

template<typename P, typename S>
/**
 * cache manager that saves solutions into files.
 */
class FileCacheManager : public CacheManager<P, S> {
    std::hash<std::string> hash;
    std::unordered_map<std::string , std::string> fileMap;

    bool hasSolution(P p) override {
        std::ifstream save_file;
        std::string key = p.toString();
        std::string filename = "Solution" + std::to_string(hash(key)) + ".txt";
        save_file.open(filename, std::ios::in | std::ios::binary);
        if(!save_file) {
            return false;
        }
        return true;
    }

    S getSolution(P p) override {
        if (!hasSolution(p)) {
            throw "No solution for problem!";
        }
        std::ifstream save_file;
        std::string key = p.toString();
        std::string filename = "Solution" + std::to_string(hash(key)) + ".txt";
        S object;
        size_t size;
        // exists in file system
        save_file.open(filename, std::ifstream::in | std::ifstream::binary);

        if (!save_file.is_open()) {
            throw "Unable To Open File At get()";
        }

        // read the size
        save_file.read(reinterpret_cast<char *>(&size), sizeof(size)  );

        // Allocate a string, make it large enough to hold the input
        object.resize(size);

        // read the text into the string
        save_file.read(&object[0],  object.size());
        save_file.close();

        return object;
    }

    void saveSolution(S solution, P problem) override {
        std::ofstream save_file;
        std::string key = problem.toString();
        std::string filename = "Solution" + std::to_string(hash(key)) + ".txt";
        fileMap.insert({key, filename});
        size_t size = solution.size();

        // update in file system
        save_file.open(filename, std::ofstream::binary | std::ofstream::out);
        if (!save_file.is_open()) {
            throw "Unable To Open File At insert()";
        }

        save_file.write(reinterpret_cast<char *>(&size), sizeof(size));
        save_file.write(solution.c_str(), solution.size());
        save_file.close();
    }


public:
    FileCacheManager<P, S>* clone() override {
        return new FileCacheManager<P, S>();
    }
};
#endif //EX4_FILECACHEIMPL_H
