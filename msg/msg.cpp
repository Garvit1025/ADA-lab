#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back({src, dest, weight});
    }
};

void multiStageGraph(Graph g)
{
    cout << "Enter the source vertex: ";
    int src;
    cin >> src;

    cout << "Enter the destination vertex: ";
    int dest;
    cin >> dest;

    vector<int> dist(g.V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < g.V - 1; i++)
    {
        for (auto edge : g.edges)
        {
            if (dist[edge.src] != INT_MAX && dist[edge.dest] > dist[edge.src] + edge.weight)
                dist[edge.dest] = dist[edge.src] + edge.weight;
        }
    }

    cout << "The minimum distance from " << src << " to " << dest << " is " << dist[dest] << endl;
}

int main()
{
    cout << "Enter the number of vertices: ";
    int V;
    cin >> V;

    cout << "Enter the number of edges: ";
    int E;
    cin >> E;

    Graph g(V, E);

    for (int i = 0; i < E; i++)
    {
        cout << "Enter source, destination and weight for edge " << i + 1 << ": ";
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    multiStageGraph(g);
}