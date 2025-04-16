#include <iostream>
using namespace std;

const int INF = 1000000;
const int N = 9; 

int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[N][N], int start) {
    int dist[N];
    bool visited[N];

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[start] = 0;

    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Расстояния от вершины " << char('A' + start) << " до других вершин:\n";
    for (int i = 0; i < N; i++) {
        if (dist[i] == INF) {
            cout << char('A' + i) << ": недостижимо\n";
        }
        else {
            cout << char('A' + i) << ": " << dist[i] << "\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int graph[N][N] = {
      //  A    B    C    D    E    F    G    H    I
        {  0,   7,  10, INF, INF, INF, INF, INF, INF}, // A
        {  7,   0, INF, INF, INF,   9,  27, INF, INF}, // B
        { 10, INF,   0, INF,  31,   8, INF, INF, INF}, // C
        {INF, INF, INF,   0, 32, INF, INF,  17,  21}, // D
        {INF, INF,  31, 32,   0,  INF, INF, INF, INF}, // E
        {INF,   9,   8, INF,  INF,   0, INF,  11, INF}, // F
        {INF,  27, INF, INF, INF, INF,   0, INF,  15}, // G
        {INF, INF, INF,  17, INF,  11, INF,   0,  15}, // H
        {INF, INF, INF,  21, INF, INF,  15,  15,   0}  // I
    };

    char start_char;
    cout << "Введите стартовую вершину (A - I): ";
    cin >> start_char;

    // Преобразуем символ в индекс
    int start = start_char - 'A';

    if (start < 0 || start >= N) {
        cout << "Неверный ввод. Пожалуйста, введите букву от A до I.\n";
        return 1;
    }

    dijkstra(graph, start);

    return 0;
}