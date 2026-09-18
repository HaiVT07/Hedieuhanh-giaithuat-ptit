#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, steps;
} Node;

// 4 hướng di chuyển: Lên, Trái, Xuống, Phải
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    char grid[105][105];
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a == c && b == d) {
        printf("0\n");
        return;
    }

    int visited[105][105] = {0};
    Node queue[10005];
    int front = 0, rear = 0;

    // Đẩy điểm xuất phát vào Queue
    queue[rear++] = (Node){a, b, 0};
    visited[a][b] = 1;

    while (front < rear) {
        Node curr = queue[front++];

        if (curr.x == c && curr.y == d) {
            printf("%d\n", curr.steps);
            return;
        }

        // Loang theo 4 hướng
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            // Đi liên tục trên cùng 1 hàng/cột cho đến khi gặp mép bảng hoặc vật cản 'X'
            while (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 'X') {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    queue[rear++] = (Node){nx, ny, curr.steps + 1};
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
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