#include <stdio.h>
#include <string.h>

#define MAX 20005

typedef struct {
    int val;
    int steps;
} Node;

void solve() {
    int s, t;
    if (scanf("%d %d", &s, &t) != 2) return;

    // Nếu S >= T thì chỉ có thể dùng thao tác trừ (S - T bước)
    if (s >= t) {
        printf("%d\n", s - t);
        return;
    }

    // Mảng đánh dấu các giá trị đã thăm
    int visited[MAX] = {0};
    
    // Khởi tạo Queue cho BFS
    Node queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = (Node){s, 0};
    visited[s] = 1;

    while (front < rear) {
        Node curr = queue[front++];

        if (curr.val == t) {
            printf("%d\n", curr.steps);
            return;
        }

        // Thao tác (b): S * 2
        if (curr.val * 2 < MAX && !visited[curr.val * 2]) {
            visited[curr.val * 2] = 1;
            queue[rear++] = (Node){curr.val * 2, curr.steps + 1};
        }

        // Thao tác (a): S - 1
        if (curr.val - 1 > 0 && !visited[curr.val - 1]) {
            visited[curr.val - 1] = 1;
            queue[rear++] = (Node){curr.val - 1, curr.steps + 1};
        }
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