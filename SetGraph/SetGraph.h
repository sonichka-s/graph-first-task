//
// Created by sonichka on 30.12.2021.
//

#pragma once
#include "../IGraph.h"


class SetGraph : public IGraph {
public:
    SetGraph(int vertices_count);

    SetGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> vertices;
};


