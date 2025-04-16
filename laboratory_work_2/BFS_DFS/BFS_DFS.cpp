#include <iostream>

using namespace std;

const int V = 10;
bool adjMatrix[V][V];
int edgeList[V * (V - 1) / 2][2];
int adjList[V][V];
int edgeCount = 0;

void initGraph() {
    // Матрица 
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            adjMatrix[i][j] = false;
        }
    }

    // Список смежности
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            adjList[i][j] = -1;
        }
    }
}
// Добавление рёбер
void addEdge(int u, int v) {
    adjMatrix[u][v] = true;
    adjMatrix[v][u] = true;

    edgeList[edgeCount][0] = u;
    edgeList[edgeCount][1] = v;
    edgeCount++;

    for (int i = 0; i < V; ++i) {
        if (adjList[u][i] == -1) {
            adjList[u][i] = v;
            break;
        }
    }
    for (int i = 0; i < V; ++i) {
        if (adjList[v][i] == -1) {
            adjList[v][i] = u;
            break;
        }
    }
}

void BFS(int start) {
    bool visited[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    int queue[V];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    cout << "BFS: ";
    while (front != rear) {
        int v = queue[front++];
        cout << v + 1 << " ";
        for (int u = 0; u < V; ++u) {
            if (adjMatrix[v][u] && !visited[u]) {
                visited[u] = true;
                queue[rear++] = u;
            }
        }
    }
    cout << endl;
}

void DFS(int start) {
    bool visited[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    int stack[V];
    int top = 0;

    stack[top++] = start;

    cout << "DFS: ";
    while (top > 0) {
        int v = stack[--top];

        if (!visited[v]) {
            cout << v + 1 << " ";
            visited[v] = true;
        }
        for (int u = V - 1; u >= 0; --u) {
            if (adjMatrix[v][u] && !visited[u]) {
                stack[top++] = u;
            }
        }
    }
    cout << endl;
}

void printGraph() {
    cout << "Матрица смежности:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Список рёбер:" << endl;
    for (int i = 0; i < edgeCount; ++i) {
        cout << edgeList[i][0] + 1 << " - " << edgeList[i][1] + 1 << endl;
    }
    cout << endl;

    cout << "Список смежности:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i + 1 << ": ";
        for (int j = 0; j < V && adjList[i][j] != -1; ++j) {
            cout << adjList[i][j] + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    initGraph();

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 6);
    addEdge(1, 7);
    addEdge(4, 5);
    addEdge(6, 7);
    addEdge(2, 7);
    addEdge(3, 5);
    addEdge(3, 8);
    addEdge(5, 8);
    addEdge(8, 9);

    BFS(0);
    DFS(0);
    cout << endl;

    printGraph();

    return 0;
}