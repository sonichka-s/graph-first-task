//
// Created by sonichka on 30.12.2021.
//

#include "SetGraph.h"

void SetGraph::AddEdge(int from, int to) {
    vertices[from].push_back(to);
}

int SetGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result(vertices[vertex].begin(), vertices[vertex].end());
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (int parent = 0; parent < vertices.size(); parent++) {
        for (auto& child : vertices[parent]) {
            if (child == vertex) {
                result.push_back(parent);
                break;
            }
        }
    }

    return result;
}