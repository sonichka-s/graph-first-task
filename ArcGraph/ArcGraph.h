//
// Created by sonichka on 30.12.2021.
//

#pragma once
#include "../IGraph.h"

class ArcGraph : public IGraph {
public:
    ArcGraph(int vertices_count);

    ArcGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override {
        return verticesCount;
    }

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int verticesCount;
    std::vector<std::pair<int, int>> vertices;
};

