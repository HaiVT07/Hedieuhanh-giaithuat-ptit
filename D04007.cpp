#include <stdio.h>
#include <stdlib.h>

int visited[1005];

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[1005];

void addEdge(int u, int v) {
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->v = v;
    newNode1->next = adj[u];
    adj[u] = newNode1;

    Node* newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->v = u;
    newNode2->next = adj[v];
    adj[v] = newNode2;
}

// Hàm DFS phát hiện chu trình
int dfs(int u, int parent) {
    visited[u] = 1;

    Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->v;
        if (!visited[v]) {
            if (dfs(v, u)) return 1;
        } else if (v != parent) {
            // Đã thăm và không phải là đỉnh cha -> Có chu trình
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void solve() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return;

    // Reset dữ liệu bộ test
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        Node* curr = adj[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        adj[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int hasCycle = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, 0)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}