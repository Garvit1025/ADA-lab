#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct node
{
    int vertex;
    int distance;
    struct node *next;
};

class PriorityQueue
{
private:
    node *head;

public:
    PriorityQueue()
    {
        head = NULL;
    }

    int enqueue(int vertex, int priority)
    {
        node *temp, *p;
        temp = new node;
        temp->vertex = vertex;
        temp->distance = priority;
        if (head == NULL || head->distance > priority)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL && p->next->distance <= priority)
            {
                p = p->next;
            }
            temp->next = p->next;
            p->next = temp;
        }
        return vertex;
    }

    int dequeue()
    {
        node *temp;
        int vertex;
        if (head == NULL)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        temp = head;
        vertex = head->vertex;
        head = head->next;
        delete temp;
        return vertex;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};

class Graph
{
private:
    vector<node *> adjList;
    int numVertices;

public:
    Graph(int n)
    {
        numVertices = n;
        adjList.resize(numVertices, NULL);
    }

    void addEdge(int src, int dest, int distance)
    {
        node *newNode = new node;
        newNode->vertex = dest;
        newNode->distance = distance;
        newNode->next = adjList[src];
        adjList[src] = newNode;
    }

    void dijkstra(int start)
    {
        PriorityQueue pq;
        vector<int> dist(numVertices, numeric_limits<int>::max());
        dist[start] = 0;
        vector<bool> visited(numVertices, false);

        pq.enqueue(start, 0);

        while (!pq.isEmpty())
        {
            int u = pq.dequeue();
            visited[u] = true;

            node *temp = adjList[u];
            while (temp != NULL)
            {
                int v = temp->vertex;
                int distance = temp->distance;
                if (!visited[v] && dist[u] + distance < dist[v])
                {
                    dist[v] = dist[u] + distance;
                    pq.enqueue(v, dist[v]);
                }
                temp = temp->next;
            }
        }

        cout << "Shortest distances from vertex " << start << ":\n";
        for (int i = 0; i < numVertices; i++)
        {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }
};

int main()
{
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    Graph g(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;
    cout << "Enter source vertex , destination vertex, distance between the vertices:\n";
    for (int i = 0; i < numEdges; i++)
    {
        int src, dest, distance;
        cin >> src >> dest >> distance;
        g.addEdge(src, dest, distance);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;
    g.dijkstra(startVertex);

    return 0;
}
