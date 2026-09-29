#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool visited[1000];
vector<pair<int, int>> adj[1000];

int maxSpanningTree(int start)
{
    // Priority queue for maximum weight first
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    int totalWeight = 0;

    vector<pair<int, int>> mstEdges;

    while (!pq.empty())
    {
        auto [weight, node] = pq.top();
        pq.pop();

        if (!visited[node])
        {
            visited[node] = true;
            totalWeight += weight;

            if (weight != 0)
                mstEdges.push_back({node, weight});
        }

        for (auto it : adj[node])
        {
            int w = it.first;
            int neighbor = it.second;
            if (!visited[neighbor])
            {
                pq.push({w, neighbor});
            }
        }
    }

    cout << "Maximum Spanning Tree edges:\n";
    for (auto e : mstEdges)
    {
        cout << "Node " << e.first << " with edge weight " << e.second << endl;
    }

    return totalWeight;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    cout << "Total Maximum Spanning Tree Weight: " << maxSpanningTree(1) << endl;
}
