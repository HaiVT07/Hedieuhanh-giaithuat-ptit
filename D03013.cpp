#include <stdio.h>
#include <string.h>

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    // Kích thước queue và res tối đa cho N < 15: 2^15 - 2 = 32766 phần tử
    char res[35000][20];
    int count = 0;

    char queue[35000][20];
    int front = 0, rear = 0;

    // Đẩy 2 số ban đầu "6" và "8" vào queue
    strcpy(queue[rear++], "6");
    strcpy(queue[rear++], "8");

    while (front < rear) {
        char s[20];
        strcpy(s, queue[front++]);

        // Lưu vào mảng kết quả
        strcpy(res[count++], s);

        int len = strlen(s);
        // Nếu độ dài chưa đạt N, tiếp tục sinh các số tiếp theo
        if (len < n) {
            // Push s + "6"
            strcpy(queue[rear], s);
            queue[rear][len] = '6';
            queue[rear][len + 1] = '\0';
            rear++;

            // Push s + "8"
            strcpy(queue[rear], s);
            queue[rear][len] = '8';
            queue[rear][len + 1] = '\0';
            rear++;
        }
    }

    // In số lượng kết quả
    printf("%d\n", count);

    // In danh sách các số lộc phát theo thứ tự tăng dần
    for (int i = 0; i < count; i++) {
        printf("%s%c", res[i], (i == count - 1) ? '\n' : ' ');
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