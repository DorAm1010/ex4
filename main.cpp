
#include "FileCacheImpl.h"
#include "MyClientHandler.h"
#include "AStar.h"
#include "bestFirstSearch.h"
#include "DFS.h"
#include "breadthFirstSearch.h"
#include "SolveSearchAdapter.h"
#include "MySerialServer.h"
#include "MyParallelServer.h"

/** TODO
 * insert Parallel server.
 * @return
 */
int main(int argc, char* argv[]) {
    int port = 5400;

    if(argc > 1) {
        port = atoi(argv[1]);
    }

    //BestFirstSearch<Point, std::string> searcher;
    //BFS<Point, std::string> searcher;
    //DFS<Point, std::string> searcher;
    AStarSearcher<Point, std::string> searcher;
    SolveSearchAdapter<MatrixProblem,std::string, Point> adapter(&searcher);
    FileCacheManager<MatrixProblem, std::string> cacheManager;
    MyClientHandler<MatrixProblem, std::string> myClientHandler(&cacheManager, &adapter);
    MyParallelServer<MatrixProblem, std::string> parallelServer;
    //MySerialServer<MatrixProblem, std::string> serialServer;

    try {
        parallelServer.open(port,  &myClientHandler);
        //serialServer.open(5400, &myClientHandler);
    } catch (const char* e) {
        std::cout << e << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    parallelServer.stop();

    return 0;
}
