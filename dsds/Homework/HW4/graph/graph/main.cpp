#include<iostream>
using namespace std;
#include"../../../../Graph/graph.h"

int main() {
    Graph A(6);

    A.addEdge(0, 1);
    A.addEdge(0, 2);
    A.addEdge(0, 3);
    A.addEdge(1, 2);
    A.addEdge(1, 4);
    A.addEdge(2, 4);
    A.addEdge(3, 5);
   

    cout << "BFS: ";
    A.BFS(0);
    cout << endl;

    cout << "DFS: ";
    A.DFS(0);
    cout << endl << endl;;

    Graph B(9);

    B.addEdge(0, 1);
    B.addEdge(0, 3);
    B.addEdge(1, 4);
    B.addEdge(1, 5);
    B.addEdge(2, 3);
    B.addEdge(3, 4);
    B.addEdge(4, 5);
    B.addEdge(4, 8);
    B.addEdge(5, 6);
    B.addEdge(5, 7);
    B.addEdge(6, 7);
    B.addEdge(6, 8);
   

    B.dijkstra(0);
    B.prim();

    return 0;
}