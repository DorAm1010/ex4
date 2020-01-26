//
// Created by dor on 1/14/20.
//
//
#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H
template <typename P, typename S>
/**
 * Class that in charge of managing all the solutions
 * we got. Cache manager need to be able to save, upload
 * and find a solution for a problem.
 */
class CacheManager {
public:
    /**
     * gets a problem, and return true if the solution
     * is already saved in cache.
     */
    virtual bool hasSolution(P) = 0;
    /**
     * gets a problem and return the solution for that problem.
     * if solution is not exict, throws an exception.
     */
    virtual S getSolution(P) = 0;
    /**
     * saves a solution for a problem.
     */
    virtual void saveSolution(S, P) = 0;
    /**
     * creating a deep copy of a cache manger object.
     */
    virtual CacheManager<P,S>* clone() = 0;
};
#endif //EX4_CACHEMANAGER_H
