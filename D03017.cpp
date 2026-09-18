#include <stdio.h>
#include <string.h>

typedef struct {
    int r, c, steps;
} Node;

// 8 hướng di chuyển của quân mã
int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void solve() {
    char st[5], en[5];
    if (scanf("%s %s", st, en) != 2) return;

    int start_c = st[0] - 'a';
    int start_r = st[1] - '1';
    int end_c = en[0] - 'a';
    int end_r = en[1] - '1';

    if (start_r == end_r && start_c == end_c) {
        printf("0\n");
        return;
    }

    int visited[8][8] = {0};
    Node queue[100];
    int front = 0, rear = 0;

    // Đẩy ô xuất phát vào Queue
    queue[rear++] = (Node){start_r, start_c, 0};
    visited[start_r][start_c] = 1;

    while (front < rear) {
        Node curr = queue[front++];

        if (curr.r == end_r && curr.c == end_c) {
            printf("%d\n", curr.steps);
            return;
        }

        for (int i = 0; i < 8; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            // Kiểm tra nước đi hợp lệ trên bàn cờ 8x8
            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                queue[rear++] = (Node){nr, nc, curr.steps + 1};
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