#include <stdio.h>
#include <stdlib.h>

int visited[1005];

// Cấu trúc danh sách kề
typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[1005];

// Thêm cạnh vô hướng (u, v) và chèn có sắp xếp tăng dần
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

void bfs(int start) {
    int queue[1005];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v;
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
}

void solve() {
    int n, m, start;
    if (scanf("%d %d %d", &n, &m, &start) != 3) return;

    // Reset dữ liệu cho mỗi testcase
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

    bfs(start);
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