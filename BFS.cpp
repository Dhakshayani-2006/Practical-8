#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> &adj)
{
    int V = adj.size();

    vector<bool> visited(V, false);
    vector<int> res;

    int src = 0;

    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        res.push_back(curr);

        for (int i : adj[curr])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    for (int i : res)
        cout << i << " ";
}

int main()
{
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3},
        {0, 4},
        {1},
        {2}
    };

    BFS(adj);

    return 0;
}
