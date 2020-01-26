# ex4
this project runs a parallel server able to recieve up to 10 clients where each client is delivering an nxn(square matrix) maze from a client, where each cell of that maze contains the cost of stepping into it and each cell is comma seperated and each row is separated by newline character, a starting point indicated as i,j then newline character sequented by an end point indicated the same and returning the best path to get out of the maze.

## Installation
in order to run this program you need a c++(g++) compiler.

## Compilation
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

## Run
you could run this program with an argument in the terminal indicating desired port to run on, however if you want the program to run on its default port, 5400, just run ./a.out.
afterwards you will need to insert the 3 arguments specified above.
you could choose which algorithm you want the program to search with from one of the following options most commented out in main:
(1) AStar Algorithm
(2) BestFirstSearch Algorithm
(3) BFS Algorithm
(4) DFS Algorithm
and compare results.

You could also get the program to run a serial server instead of a parallel, up to you to uncomment it at main.cpp.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
