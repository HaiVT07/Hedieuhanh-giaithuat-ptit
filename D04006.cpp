#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
} Edge;

Edge edges[100005];
int visited[1005];

typedef struct Node {
    int v;
    int edgeIdx;
    struct Node* next;
} Node;

Node* adj[1005];

void addEdge(int u, int v, int edgeIdx) {
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->v = v;
    newNode1->edgeIdx = edgeIdx;
    newNode1->next = adj[u];
    adj[u] = newNode1;

    Node* newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->v = u;
    newNode2->edgeIdx = edgeIdx;
    newNode2->next = adj[v];
    adj[v] = newNode2;
}

// DFS bỏ qua cạnh có chỉ số removedEdge
void dfs(int u, int removedEdge) {
    visited[u] = 1;
    Node* temp = adj[u];
    while (temp != NULL) {
        if (temp->edgeIdx != removedEdge) {
            int v = temp->v;
            if (!visited[v]) {
                dfs(v, removedEdge);
            }
        }
        temp = temp->next;
    }
}

// Đếm số thành phần liên thông khi bỏ qua cạnh removedEdge
int countConnectedComponents(int n, int removedEdge) {
    for (int i = 1; i <= n; i++) visited[i] = 0;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i, removedEdge);
        }
    }
    return count;
}

// So sánh cạnh để sắp xếp theo thứ tự từ điển
int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    if (e1->u != e2->u) return e1->u - e2->u;
    return e1->v - e2->v;
}

void solve() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return;

    // Reset danh sách kề
    for (int i = 1; i <= n; i++) {
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
        if (u > v) {
            int temp = u; u = v; v = temp;
        }
        edges[i].u = u;
        edges[i].v = v;
        addEdge(u, v, i);
    }

    // Đếm số thành phần liên thông ban đầu (không bỏ cạnh nào => removedEdge = -1)
    int initial_cc = countConnectedComponents(n, -1);

    Edge bridges[10005];
    int bridgeCount = 0;

    // Thử loại bỏ từng cạnh
    for (int i = 0; i < m; i++) {
        int current_cc = countConnectedComponents(n, i);
        if (current_cc > initial_cc) {
            bridges[bridgeCount++] = edges[i];
        }
    }

    // Sắp xếp các cạnh cầu theo thứ tự từ điển
    qsort(bridges, bridgeCount, sizeof(Edge), compareEdges);

    // In danh sách cạnh cầu
    for (int i = 0; i < bridgeCount; i++) {
        printf("%d %d%c", bridges[i].u, bridges[i].v, (i == bridgeCount - 1) ? '\n' : ' ');
    }
    if (bridgeCount == 0) printf("\n");
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