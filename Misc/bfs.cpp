#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;

void bfsQueue(const vector<vector<int>> &adj_list, int node)
{
    cout << "Visited: ";

    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < adj_list[node].size(); i++)
        {
            if (!visited[adj_list[node][i]])
            {
                q.push(adj_list[node][i]);
                visited[adj_list[node][i]] = true;
            }
        }
    }
}

void initialize()
{
    for (int i = 0; i < visited.size(); i++)
        visited[i] = false;
}

int main()
{
    int nodes, edges, u, v;
    cin >> nodes;
    cin >> edges;

    adj_list.resize(nodes + 1);
    visited.resize(nodes + 1);

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    initialize();
    bfsQueue(adj_list, 1);
    cout << endl;
}

// Number of nodes = 6
// Number of edges = 7

// 6 7
// 1 2
// 1 4
// 4 5
// 2 4
// 2 3
// 3 6
// 4 6
// Visited: 1 4 6 3 5 2
