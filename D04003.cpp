#include <stdio.h>
#include <stdlib.h>

int visited[1005];
int parent[1005];

// Cấu trúc danh sách kề dạng Danh sách liên kết
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

void bfs(int s, int t) {
    int queue[1005];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int u = queue[front++];

        if (u == t) break; // Đã tìm thấy đường đi tới t

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v;
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
}

void solve() {
    int n, m, s, t;
    if (scanf("%d %d %d %d", &n, &m, &s, &t) != 4) return;

    // Reset dữ liệu bộ test
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        parent[i] = 0;
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

    bfs(s, t);

    // Nếu không có đường đi tới t
    if (!visited[t]) {
        printf("-1\n");
        return;
    }

    // Truy vết đường đi từ t trở về s
    int path[1005];
    int count = 0;
    int curr = t;

    while (curr != 0) {
        path[count++] = curr;
        curr = parent[curr];
    }

    // In đường đi từ s đến t
    for (int i = count - 1; i >= 0; i--) {
        printf("%d%c", path[i], (i == 0) ? '\n' : ' ');
    }
}

int main() {
    int T;
    if (scanf("%d", &T) == 1) {
        while (T--) {
            solve();
        }
    }
    return 0;
}