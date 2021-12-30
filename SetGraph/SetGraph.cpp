//
// Created by sonichka on 30.12.2021.
//

#include "SetGraph.h"

SetGraph::SetGraph(int vertices_count) {
    vertices = new std::set<int>[verticesCount];
}

SetGraph::SetGraph(const IGraph &graph) {
    vertices = new std::set<int>[verticesCount];

    for (int parent = 0; parent < verticesCount; ++parent) {
        std::vector<int> nextVertices = graph.GetNextVertices(parent);
        for (const auto& child : nextVertices)
            AddEdge(parent, child);
    }
}

void SetGraph::AddEdge(int from, int to) {
    vertices[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (int next : vertices[vertex]) {
        result.push_back(next);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (int parent = 0; parent < verticesCount; parent++) {
        auto child = vertices[parent].find(vertex);
        if (child != vertices[parent].end()) {
            result.push_back(parent);
        }
    }

    return result;
}