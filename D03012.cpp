#include <stdio.h>
#include <string.h>

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    // Queue lưu các chuỗi số tạo bởi '0' và '9'
    char queue[10000][100];
    int front = 0, rear = 0;

    // Đẩy phần tử đầu tiên "9" vào queue
    strcpy(queue[rear++], "9");

    while (front < rear) {
        char s[100];
        strcpy(s, queue[front++]);

        // Tính số dư của chuỗi s cho N
        long long rem = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            rem = (rem * 10 + (s[i] - '0')) % n;
        }

        // Nếu chia hết cho N, in ra kết quả và kết thúc
        if (rem == 0) {
            printf("%s\n", s);
            return;
        }

        // Tạo 2 xâu mới s + "0" và s + "9" rồi push vào queue
        int len = strlen(s);

        // Push s + "0"
        strcpy(queue[rear], s);
        queue[rear][len] = '0';
        queue[rear][len + 1] = '\0';
        rear++;

        // Push s + "9"
        strcpy(queue[rear], s);
        queue[rear][len] = '9';
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