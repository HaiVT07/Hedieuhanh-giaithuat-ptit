#include <stdio.h>
#include <stdlib.h>

int head[1005];
int visited[1005];

// Cấu trúc danh sách kề dạng Danh sách liên kết
typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[1005];

// Hàm thêm cạnh vô hướng (u, v) và giữ danh sách kề tăng dần
void addEdge(int u, int v) {
    // Thêm v vào adj[u]
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->v = v;
    newNode1->next = NULL;

    if (adj[u] == NULL || adj[u]->v > v) {
        newNode1->next = adj[u];
        adj[u] = newNode1;
    } else {
        Node* curr = adj[u];
        while (curr->next != NULL && curr->next->v < v) {
            curr = curr->next;
        }
        newNode1->next = curr->next;
        curr->next = newNode1;
    }

    // Thêm u vào adj[v]
    Node* newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->v = u;
    newNode2->next = NULL;

    if (adj[v] == NULL || adj[v]->v > u) {
        newNode2->next = adj[v];
        adj[v] = newNode2;
    } else {
        Node* curr = adj[v];
        while (curr->next != NULL && curr->next->v < u) {
            curr = curr->next;
        }
        newNode2->next = curr->next;
        curr->next = newNode2;
    }
}

void dfs(int u) {
    visited[u] = 1;
    printf("%d ", u);

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
    int n, m, start;
    if (scanf("%d %d %d", &n, &m, &start) != 3) return;

    // Reset dữ liệu cho mỗi testcase
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        // Giải phóng bộ nhớ danh sách kề cũ
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

    dfs(start);
    printf("\n");
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