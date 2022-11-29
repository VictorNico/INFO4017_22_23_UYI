/*
 * graph.h
 */

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "./matrix.h"

/**
 * @brief 
 * This is an implementation of graph
 * We are using the adjacent matrix representation of a graph
 */
class Graph 
{
public:
    /**
     * @brief 
     * construct an instance of a graph
     * @param n int, representing the number of vertex
     */
    Graph(const int n):adjMat(n,n){}

    /**
     * @brief 
     * Add edge to the adj matrix form 
     * @param src int, source vertex index 
     * @param dst int, destination vertex 
     * @param weight int, weight of the vertex
     */
    void addEdge(const int src, const int dst, const int weight = 1)
    {
        if (src < 0 || dst < 0 || weight < 0){
            // call the GUI error handler
        }
        else{
            adjMat.setVal(src,dst,weight);
        }
    }

    /**
     * @brief 
     * Remove edge to the graph knowing 
     * @param src int, source vertex index 
     * @param dst int, destination vertex 
     * 
     */
    void removeEdge(const int src, const int dst)
    {
        if (src < 0 || dst < 0)
        {
            // call the GUI error handler
        }
        else
        {
            adjMat.setVal(src, dst, 0);
        }
    }

    /**
     * @brief 
     * get the weight of edge
     * @param src int, source vertex index 
     * @param dst int, destination vertex 
     * 
     */
    int getWeight(const int src, const int dst)
    {
        if (src < 0 || dst < 0)
        {
            // call the GUI error handler
        }
        else
        {
            return adjMat.getVal(src, dst);
        }
    }

    /**
     * @brief 
     * Prim Algorithm 
     * @param g Graph, with a set og vertex or nodes and a set of edges
     */
    static void Prim

    /**
     * @brief 
     * destructor of an instance
     */
    ~Graph();
private:
    // adj matrix variable 
    Matrix adjMat;
};

#endif