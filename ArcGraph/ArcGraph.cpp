//
// Created by sonichka on 30.12.2021.
//

#include "ArcGraph.h"

ArcGraph::ArcGraph(int vertices_count) {
    this->verticesCount = vertices_count;
}

ArcGraph::ArcGraph(const IGraph &graph) {
    verticesCount = graph.VerticesCount();

    for (int parent = 0; parent < verticesCount; parent++) {
        std::vector<int> nextVertices = graph.GetNextVertices(parent);
        for (const auto& child : nextVertices)
            AddEdge(parent, child);
    }
}


void ArcGraph::AddEdge(int from, int to) {
    vertices.push_back(std::make_pair(from, to));
}


std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (const auto& [from, to] : vertices) {
        if (vertex == from)
            nextVertices.push_back(to);
    }
    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (const auto& [from, to] : vertices) {
        if (to == vertex)
            prevVertices.push_back(from);
    }
    return prevVertices;
}