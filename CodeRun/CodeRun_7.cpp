#include <iostream>
#include <vector>
#include <set>

using namespace std;

// ��� ����������������� ����, ��������, � ������� � �������� �������.
// ���������� ��������� ���������� ���������, ���������� ������� � ������� 1.

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
    int vartexCount, edgeCount; // ������� � �����
    cin >> vartexCount >> edgeCount;

    vector<vector<int>> graph(vartexCount);

    for (int i = 0; i < edgeCount; i++) // ������� � ������ ���������
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(vartexCount); // ��� �� �� ������ �������
    set<int> visitedName; // ��� �� ����� �������-����� ���� ������

    dfs(graph, 0, visited, visitedName); // ��� ������� ������ ���� ������� �� 1, ������� � ���� �� 0, ���� � � ������ ������� ������� � ������� 1.

    cout << visitedName.size() << endl;
    for (auto item : visitedName)
    {
        cout << ++item << endl;
    }
    return 0;
}
