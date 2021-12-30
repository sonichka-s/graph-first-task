//
// Created by sonichka on 28.12.2021.
//

#include "ListGraph.h"


void ListGraph::AddEdge(int from, int to) {
    vertices[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return vertices.size();
}

ListGraph::ListGraph(int vertices_count) {
    vertices.resize(vertices_count);
}

ListGraph::ListGraph(const IGraph &graph) {

}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    std::vector<int> result(vertices[vertex].begin(), vertices[vertex].end());
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
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

