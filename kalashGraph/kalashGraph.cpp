//
// Created by Kalash on ٠٩/٠٦/٢٠٢٢.
//

#include "kalashGraph.h"
#include "kalashLinkedQueue.cpp"




template<typename GraphItem>
kalashGraph<GraphItem>::kalashGraph(int maxSize): maxSize(maxSize), n(0)
{
    graphVertices = new vertex<GraphItem>[maxSize];
    for (int i=0;i<maxSize;i++)
    {
        //graphVertices[i].item= nullptr;
        graphVertices[i].firstEdge= nullptr;
        graphVertices[i].lastEdge= nullptr;
    }
}

template<typename GraphItem>
kalashGraph<GraphItem>::~kalashGraph()
{
    // deleting edges
    for (int i=0;i<n;i++)
    {
        edge* curr= graphVertices[i].firstEdge;
        edge* prev;
        while (curr)
        {
            prev=curr;
            curr=curr->nextEdge;
            delete prev;
        }
    }

    // deleting Vertices
    delete[] graphVertices;
}

template<typename GraphItem>
void kalashGraph<GraphItem>::DFSHelper(int index, void (*pFunction)(GraphItem), bool isVisited[])
{
    pFunction(graphVertices[index].item);
    isVisited[index]=true;
    // go deeper
    for (edge* temp=graphVertices[index].firstEdge; temp; temp=temp->nextEdge)
    {
        if(!isVisited[temp->endPointIndex])
            DFSHelper(temp->endPointIndex,pFunction,isVisited);
    }

}

template<typename GraphItem>
void kalashGraph<GraphItem>::DFS(int start, void (*pFunction)(GraphItem item))
{
    bool isVisited[this->size];
    for (bool &i:isVisited)
            i=false;

    DFSHelper(start,pFunction,isVisited);

    // visiting the disconnected subGraphs
    for (int i = 0; i < n; ++i)
    {
        if(!isVisited[i])
            DFSHelper(i,pFunction,isVisited);
    }
}

template<typename GraphItem>
void kalashGraph<GraphItem>::BFSHelper(int start, void (*pFunction)(GraphItem item), bool *isVisited)
{
    kalashLinkedQueue<int> queue;
    queue.append(start);
    while (!queue.isEmpty())
    {
        int toBeServed = queue.serve();
        isVisited[toBeServed]= true;
        pFunction(graphVertices[toBeServed].item);

        // adding all adjacency to the Queue
        for (edge* temp=graphVertices[toBeServed].firstEdge; temp; temp=temp->nextEdge)
        {
            if(!isVisited[temp->endPointIndex])
            {
                queue.append(temp->endPointIndex);
                isVisited[temp->endPointIndex]= true;
            }
        }
    }
}

template<typename GraphItem>
void kalashGraph<GraphItem>::BFS(int start, void (*pFunction)(GraphItem item))
{
    bool isVisited[maxSize];
    for (bool &i:isVisited)
        i=false;
    BFSHelper(start,pFunction,isVisited);

    // visiting the disconnected subGraphs
    for (int i = 0; i < n; ++i)
    {
        if(!isVisited[i])
            BFSHelper(i,pFunction,isVisited);
    }

}

template<typename GraphItem>
void kalashGraph<GraphItem>::add(GraphItem item)
{
    graphVertices[n].item=item;
    n++;
}

template<typename GraphItem>
void kalashGraph<GraphItem>::addEdge(int start, int end)
{
    edge* newEdg= new edge(end, nullptr);
    if(!graphVertices[start].firstEdge)
    {
        graphVertices[start].firstEdge=newEdg;
        graphVertices[start].lastEdge= newEdg;
    }
    else
    {
        graphVertices[start].lastEdge->nextEdge =newEdg;
        graphVertices[start].lastEdge= newEdg;
    }
}
