#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;

void dfsStack(const vector<vector<int>> &adj_list, int node)
{
    cout << "Visited: ";

    stack<int> stk;
    stk.push(node);
    visited[node] = true;

    while (!stk.empty())
    {
        node = stk.top();
        stk.pop();
        cout << node << " ";

        for (int i = 0; i < adj_list[node].size(); i++)
        {
            if (!visited[adj_list[node][i]])
            {
                stk.push(adj_list[node][i]);
                visited[adj_list[node][i]] = true;
            }
        }
    }
}

void dfsRecursion(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adj_list[node].size(); i++)
        if (visited[adj_list[node][i]] == false)
            dfsRecursion(adj_list[node][i]);
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
    dfsStack(adj_list, 1);
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
