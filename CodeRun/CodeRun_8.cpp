#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(vector<vector<int>>& graph, int v, vector<int>& visited, set<int>& visitedName)
{
    visited[v] = 1;
    visitedName.insert(v);

    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, visitedName);
}

int main()
{
    int vartexCount, edgeCount; // Вершины и ребра
    cin >> vartexCount >> edgeCount;

    vector<vector<int>> graph(vartexCount);

    for (int i = 0; i < edgeCount; i++) // Перевод в список смежности
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(vartexCount);
    vector<set<int>> visitedName(vartexCount);
    int componentCount = 0;
    int tempComponentCount = 0;


    for (int v = 0; v < vartexCount; v++)
    {
        if (!visited[v]) {
            componentCount++;
            dfs(graph, v, visited, visitedName[v]);
        }
    }


    cout << componentCount << endl;;
    for (size_t i = 0; i < visitedName.size(); i++)
    {
        if (visitedName[i].size() != 0)
            cout << visitedName[i].size() << endl;
        else
            continue;
        for (auto item : visitedName[i])
        {
            cout << ++item << endl;
        }
    }

    return 0;
}
