#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r, c, steps;
} Node;

void solve() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return;

    int a[1005][1005];
    int visited[1005][1005] = {0};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Khởi tạo Queue bằng mảng động
    Node* queue = (Node*)malloc(m * n * sizeof(Node));
    int front = 0, rear = 0;

    // Đẩy ô bắt đầu (0, 0) vào queue
    queue[rear++] = (Node){0, 0, 0};
    visited[0][0] = 1;

    int ans = -1;

    while (front < rear) {
        Node curr = queue[front++];

        // Nếu đã đến đích A[M-1][N-1]
        if (curr.r == m - 1 && curr.c == n - 1) {
            ans = curr.steps;
            break;
        }

        int k = a[curr.r][curr.c];
        if (k == 0) continue; // Tránh vướng ô có giá trị 0 không di chuyển được

        // Di chuyển sang phải: (r, c + k)
        if (curr.c + k < n && !visited[curr.r][curr.c + k]) {
            visited[curr.r][curr.c + k] = 1;
            queue[rear++] = (Node){curr.r, curr.c + k, curr.steps + 1};
        }

        // Di chuyển xuống dưới: (r + k, c)
        if (curr.r + k < m && !visited[curr.r + k][curr.c]) {
            visited[curr.r + k][curr.c] = 1;
            queue[rear++] = (Node){curr.r + k, curr.c, curr.steps + 1};
        }
    }

    free(queue);
    printf("%d\n", ans);
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