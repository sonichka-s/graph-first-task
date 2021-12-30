#include "iostream"
#include "IGraph.h"
#include "ListGraph.h"
#include "vector"

using namespace std;

void dfs_aux(const IGraph& graph, int vertex, std::vector<bool>& visited, void (*callback)(int v)) {
    visited[vertex] = true;
    callback(vertex);

    std::vector<int> children = graph.GetNextVertices(vertex);
    for (auto& child : children) {
        if (!visited[child])
            dfs_aux(graph, child, visited, callback);
    }
}

void dfs(const IGraph& graph, void (*callback)(int v)) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int vertex = 0; vertex < graph.VerticesCount(); ++vertex) {
        if (!visited[vertex]) {
            dfs_aux(graph, vertex, visited, callback);
        }
    }
}

int main(int arc, const char* argv[]) {
    IGraph* graph = new ListGraph(7);
    graph->AddEdge(0, 1);
    graph->AddEdge(1, 5);
    graph->AddEdge(6, 0);
    graph->AddEdge(1, 2);
    graph->AddEdge(2, 3);
    graph->AddEdge(2, 3);
    graph->AddEdge(3, 4);
    graph->AddEdge(4, 2);

    dfs(*graph, [](int v) {
        std::cout << v << std::endl;
    });

    delete graph;
}