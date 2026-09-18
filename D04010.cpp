#include <stdio.h>
#include <stdlib.h>

#define MAXN 1005
#define MAXM 2005

int n, m;
int ue[MAXM], ve[MAXM];   // danh sach canh doc vao
int deg[MAXN];            // bac cua moi dinh
int *adj[MAXN];           // danh sach ke
int fillPos[MAXN];        // vi tri dien tiep theo khi xay dung adj

int dfsVisited[MAXN], dfsParent[MAXN];
int bfsVisited[MAXN], bfsParent[MAXN];

int pathBuf[MAXN];

// ----- DFS (de quy, giu dung thu tu duyet nhu de bai) -----
void dfs(int u) {
    dfsVisited[u] = 1;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!dfsVisited[v]) {
            dfsParent[v] = u;
            dfs(v);
        }
    }
}

// ----- BFS tu dinh 1 -----
void bfs(int start) {
    int queue[MAXN];
    int head = 0, tail = 0;
    queue[tail++] = start;
    bfsVisited[start] = 1;
    bfsParent[start] = 0;
    while (head < tail) {
        int u = queue[head++];
        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (!bfsVisited[v]) {
                bfsVisited[v] = 1;
                bfsParent[v] = u;
                queue[tail++] = v;
            }
        }
    }
}

// In duong di theo DFS: tu 1 den node
void printDFSPath(int node) {
    if (!dfsVisited[node]) {
        printf("-1\n");
        return;
    }
    int cnt = 0;
    int cur = node;
    while (cur != 0) {
        pathBuf[cnt++] = cur;
        cur = dfsParent[cur];
    }
    // pathBuf dang chua node -> ... -> 1, can in nguoc lai: 1 -> ... -> node
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d", pathBuf[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}

// In duong di theo BFS: tu node ve 1
void printBFSPath(int node) {
    if (!bfsVisited[node]) {
        printf("-1\n");
        return;
    }
    int cur = node;
    int first = 1;
    while (cur != 0) {
        if (!first) printf(" ");
        printf("%d", cur);
        first = 0;
        cur = bfsParent[cur];
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &ue[i], &ve[i]);
        deg[ue[i]]++;
        deg[ve[i]]++;
    }

    // Cap phat mang ke cho tung dinh
    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(sizeof(int) * (deg[i] > 0 ? deg[i] : 1));
        fillPos[i] = 0;
    }

    // Dien danh sach ke, giu dung thu tu cac canh nhap vao
    for (int i = 0; i < m; i++) {
        int a = ue[i], b = ve[i];
        adj[a][fillPos[a]++] = b;
        adj[b][fillPos[b]++] = a;
    }

    dfs(1);
    bfs(1);

    for (int node = 2; node <= n; node++) {
        printDFSPath(node);
        printBFSPath(node);
    }

    for (int i = 1; i <= n; i++) free(adj[i]);

    return 0;
}