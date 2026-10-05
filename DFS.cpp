#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<vector<int>>& graph, int src)
{
    int V = graph.size();

    vector<bool> visited(V, false);
    vector<int> res;
    stack<int> st;

    visited[src] = true;
    res.push_back(src);
    st.push(src);

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();

        for (int i : graph[curr])
        {
            if (!visited[i])
            {
                visited[i] = true;
                res.push_back(i);
                st.push(i);
            }
        }
    }

    cout << "DFS Traversal: ";
    for (int i : res)
        cout << i << " ";
}

int main()
{
    vector<vector<int>> graph = {
        {1, 2},       
        {0, 3, 4},    
        {0, 5},       
        {1},          
        {1},          
        {2}           
    };

    int src = 0;

    DFS(graph, src);

    return 0;
}
