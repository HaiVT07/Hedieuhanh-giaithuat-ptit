#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solve() {
    char s[100005];
    scanf("%s", s);
    int n = strlen(s);
    
    // Mảng stack lưu trữ chỉ số ký tự
    int stack[100005];
    int top = -1;
    
    // Đưa mốc cơ sở -1 vào stack
    stack[++top] = -1;
    int max_len = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--; // Lấy dấu mở ra tương ứng với dấu đóng hiện tại
            if (top != -1) {
                // Nếu stack còn phần tử, cập nhật độ dài ngoặc đúng
                int current_len = i - stack[top];
                max_len = max(max_len, current_len);
            } else {
                // Nếu stack rỗng, gán mốc cơ sở mới là vị trí hiện tại
                stack[++top] = i;
            }
        }
    }
    return max_len;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        printf("%d\n", solve());
    }
    return 0;
}