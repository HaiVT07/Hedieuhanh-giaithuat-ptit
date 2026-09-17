#include <stdio.h>

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    int a[100005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int stack[100005];
    int top = -1;
    int b[100005];

    for (int i = 0; i < n; i++) {
        // Loại bỏ các phần tử nhỏ hơn hoặc bằng a[i] khỏi stack
        while (top != -1 && a[stack[top]] <= a[i]) {
            top--;
        }

        // Tính nhịp chứng khoán
        if (top == -1) {
            b[i] = i + 1;
        } else {
            b[i] = i - stack[top];
        }

        // Push chỉ số hiện tại vào stack
        stack[++top] = i;
    }

    // In kết quả
    for (int i = 0; i < n; i++) {
        printf("%d%c", b[i], (i == n - 1) ? '\n' : ' ');
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