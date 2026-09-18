#include <stdio.h>
#include <stdlib.h>

int visited[1005];
int visitedCount = 0;

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

void dfs(int u) {
    visited[u] = 1;
    visitedCount++;

    Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->v;
        if (!visited[v]) {
            dfs(v);
        }
        temp = temp->next;
    }
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    // Reset dữ liệu bộ test
    visitedCount = 0;
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

    // Đồ thị có N-1 cạnh
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Duyệt DFS xuất phát từ đỉnh 1
    dfs(1);

    // Nếu duyệt qua đủ N đỉnh thì đồ thị liên thông -> là Cây
    if (visitedCount == n) {
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