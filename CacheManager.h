//
// Created by dor on 1/14/20.
//
//
#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H
template <typename P, typename S>
class CacheManager {
public:
    virtual bool hasSolution(P) = 0;
    virtual S getSolution(P) = 0;
    virtual void saveSolution(S, P) = 0;
    virtual CacheManager<P,S>* clone() = 0;
};
#endif //EX4_CACHEMANAGER_H
