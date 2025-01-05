#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Дан неориентированный граф, возможно, с петлями и кратными ребрами.
// Необходимо построить компоненту связности, содержащую вершину с номером 1.

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

    vector<int> visited(vartexCount); // Что бы не ходить кругами
    set<int> visitedName; // Что бы знать индексы-имена всех вершин

    dfs(graph, 0, visited, visitedName); // Все индексы вершин были снижены на 1, поэтому и ищем от 0, хоть и в задаче требуют вершину с номером 1.

    cout << visitedName.size() << endl;
    for (auto item : visitedName)
    {
        cout << ++item << endl;
    }
    return 0;
}
