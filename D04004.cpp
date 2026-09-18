#include <stdio.h>
#include <stdlib.h>

int visited[1005];

// Cấu trúc danh sách kề dạng Danh sách liên kết
typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[1005];

// Hàm thêm cạnh vô hướng (u, v)
void addEdge(int u, int v) {
    // Thêm v vào adj[u]
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->v = v;
    newNode1->next = adj[u];
    adj[u] = newNode1;

    // Thêm u vào adj[v]
    Node* newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->v = u;
    newNode2->next = adj[v];
    adj[v] = newNode2;
}

// Duyệt DFS để đánh dấu tất cả các đỉnh trong cùng 1 thành phần liên thông
void dfs(int u) {
    visited[u] = 1;

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

    int count = 0;

    // Đếm số thành phần liên thông
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }

    printf("%d\n", count);
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