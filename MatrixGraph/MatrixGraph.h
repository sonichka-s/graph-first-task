//
// Created by sonichka on 30.12.2021.
//

#pragma once

#include "vector"
#include "../IGraph.h"

using namespace std;

class MatrixGraph : public IGraph {
public:
    MatrixGraph(int vertices_count);

    MatrixGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int** vertices;
    int verticesCount;
};

