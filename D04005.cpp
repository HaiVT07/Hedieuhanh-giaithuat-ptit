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

// Đếm số thành phần liên thông hiện tại của đồ thị
int countConnectedComponents(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }
    return count;
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

    // Đếm số thành phần liên thông ban đầu
    int initial_cc = countConnectedComponents(n);

    // Kiểm tra từng đỉnh xem có phải là đỉnh trụ không
    int isFirst = 1;
    for (int i = 1; i <= n; i++) {
        // Reset mảng visited
        for (int j = 1; j <= n; j++) visited[j] = 0;

        // Loại bỏ đỉnh i bằng cách đánh dấu đã thăm trước
        visited[i] = 1;

        // Đếm số thành phần liên thông sau khi loại bỏ đỉnh i
        int current_cc = countConnectedComponents(n);

        // Nếu số TPLT tăng lên thì i là đỉnh trụ
        if (current_cc > initial_cc) {
            if (!isFirst) printf(" ");
            printf("%d", i);
            isFirst = 0;
        }
    }
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