//
// Created by sonichka on 30.12.2021.
//

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(const IGraph &graph) {
    vertices = new int* [verticesCount];

    for (int i = 0; i < verticesCount; ++i) {
        vertices[i] = new int[verticesCount];
    }

    for (int i = 0; i < verticesCount; ++i) {
        for (int j = 0; j < verticesCount; ++j) {
            vertices[i][j] = 0;
        }
    }

    for (int i = 0; i < verticesCount; ++i) {
        std::vector<int> result = graph.GetNextVertices(i);

        for (int& next : result) {
            vertices[i][next] = 1;
        }
    }
}

MatrixGraph::MatrixGraph(int vertices_count) {
    vertices = new int *[verticesCount];

    for (int i = 0; i < verticesCount; ++i) {
        vertices[i] = new int[verticesCount];
    }

    for (int i = 0; i < verticesCount; ++i) {
        for (int j = 0; j < verticesCount; ++j) {
            vertices[i][j] = 0;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    vertices[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (int child = 0; child < verticesCount; ++child) {
        if (vertices[vertex][child] != 0)
            result.push_back(child);
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (int parent = 0; parent < verticesCount; parent++) {
        if (vertices[parent][vertex] != 0) {
            result.push_back(parent);
        }
    }

    return result;
}