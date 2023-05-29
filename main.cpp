#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 5; // maximum number of vertices

int V, E, S; // number of vertices, number of edges, source vertex
vector<int> adj[MAXN]; // adjacency list

int dist[MAXN]; // shortest distance from S to each vertex
bool visited[MAXN]; // whether a vertex has been visited
int count[MAXN]; // number of shortest paths to each vertex

void bfs() {
    queue<int> q;
    q.push(S);
    dist[S] = 0;
    visited[S] = true;
    count[S] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                count[v] = count[u];
                q.push(v);
            } else if (dist[v] == dist[u] + 1) {
                count[v] += count[u];
            }
        }
    }
}

int main() {
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> S;

    bfs();

    bool found = false;

    for (int i = 1; i <= V; i++) {
        if (count[i] > 1) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}