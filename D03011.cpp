#include <stdio.h>
#include <string.h>

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    // Tăng kích thước queue lên 20005 để không bị tràn mảng
    char queue[20005][20];
    int front = 0, rear = 0;

    // Push "1" vào queue
    strcpy(queue[rear++], "1");

    for (int i = 0; i < n; i++) {
        // Lấy phần tử ở đầu queue
        char s[20];
        strcpy(s, queue[front++]);

        // In ra kết quả
        printf("%s%c", s, (i == n - 1) ? '\n' : ' ');

        // Tạo 2 xâu mới bằng cách nối trực tiếp ký tự '0' và '1'
        int len = strlen(s);
        
        // Push s + "0"
        strcpy(queue[rear], s);
        queue[rear][len] = '0';
        queue[rear][len + 1] = '\0';
        rear++;

        // Push s + "1"
        strcpy(queue[rear], s);
        queue[rear][len] = '1';
        queue[rear][len + 1] = '\0';
        rear++;
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