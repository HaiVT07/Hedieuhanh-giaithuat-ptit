#include <stdio.h>
#include <string.h>

#define MAX_N 105

int dp[MAX_N][MAX_N];

// Hàm tìm giá trị lớn nhất
int max_val(int a, int b) {
    return (a > b) ? a : b;
}

void solve() {
    int n;
    char s[MAX_N];
    
    // Đọc độ dài xâu và xâu S
    if (scanf("%d", &n) != 1) return;
    scanf("%s", s);

    // Khởi tạo lại bảng phương án (rất quan trọng khi có nhiều test case)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Quy hoạch động tính bảng dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Nếu 2 ký tự giống nhau và KHÔNG cùng một vị trí index
            if (s[i - 1] == s[j - 1] && i != j) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Nếu không, lấy giá trị lớn nhất từ 2 trạng thái trước đó
                dp[i][j] = max_val(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // In kết quả
    printf("%d\n", dp[n][n]);
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