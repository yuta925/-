#include <iostream>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

void djkstra() {
    int minv;
    int d[MAX], color[MAX];

    for (int i=0; i<n; i++) {
        d[i] = INFTY;
        color[i] = WHITE;
    }

    d[0] = 0;   
    color[0] = GRAY;
    while(1) {
        minv = INFTY;
        int u = -1;
        for (int i=0; i<n; i++) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }
        if (u == -1) break;
        color[u] = BLACK;
        for (int v=0; v<n; v++) {
            if (color[v] != BLACK && M[u][v] != INFTY) {
                if (d[v] > d[u] + M[u][v]) {
                    d[v] = d[u] + M[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int e;
            cin >> e;
            M[i][j] = (e == -1) ? INFTY : e;
        }
    }

    djkstra();

    return 0;
}