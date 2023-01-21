//
// Created by Kalash on ٠٩/٠٦/٢٠٢٢.
//

#ifndef DATA_STRUCTURES_KALASHGRAPH_H
#define DATA_STRUCTURES_KALASHGRAPH_H


class edge
{
public:
    int endPointIndex;
    edge* nextEdge;
    edge(int endPointIndex,edge* nextEdge):
            endPointIndex(endPointIndex),nextEdge(nextEdge){}
    edge() =delete;

};

template<typename GraphItem>
class vertex
{
public:
    GraphItem item;
    edge* firstEdge;
    edge* lastEdge;
};

template<typename GraphItem>
class kalashGraph
{

    int maxSize;
    int n;

    vertex<GraphItem>* graphVertices;
    // helper funs
    void DFSHelper(int index, void (*pFunction)(GraphItem item), bool isVisited[]);
    void BFSHelper(int index, void (*pFunction)(GraphItem item),bool isVisited[]);
public:
    kalashGraph()=delete;
    explicit kalashGraph(int maxSize);
    ~kalashGraph();
    void addEdge(int start, int end);
    void add(GraphItem item);
    void DFS(int start, void (*pFunction)(GraphItem item));
    void BFS(int start, void (*pFunction)(GraphItem item));
    //void BuildFromAdjacency(int n, bool [n][n]);

};



#endif //DATA_STRUCTURES_KALASHGRAPH_H
