#include <stdio.h>

#define INF 1000000000
#define MAX_A 105
#define MAX_B 10005

int dp[MAX_A][MAX_B];

// Hàm tính trước bảng Quy hoạch động cho mọi trường hợp
void precompute() {
    // Khởi tạo mảng DP với giá trị vô cùng (INF)
    for (int i = 0; i < MAX_A; i++) {
        for (int j = 0; j < MAX_B; j++) {
            dp[i][j] = INF;
        }
    }
    
    // Cơ sở quy hoạch động: 0 chữ số thì tổng = 0, tổng bình phương = 0
    dp[0][0] = 0;

    // Duyệt tính DP
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 10000; j++) {
            // Thử thêm chữ số d từ 1 đến 9
            for (int d = 1; d <= 9; d++) {
                if (i >= d && j >= d * d) {
                    if (dp[i - d][j - d * d] != INF && dp[i - d][j - d * d] + 1 < dp[i][j]) {
                        dp[i][j] = dp[i - d][j - d * d] + 1;
                    }
                }
            }
        }
    }
}

void solve() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return;

    // Kiểm tra tính hợp lệ: Không tìm được cách ghép hoặc độ dài > 100
    if (a <= 0 || a > 100 || b <= 0 || b > 10000 || dp[a][b] == INF || dp[a][b] > 100) {
        printf("-1\n");
        return;
    }

    int curr_a = a;
    int curr_b = b;
    int len = dp[a][b];

    // Truy vết tham lam: Ưu tiên chọn chữ số nhỏ nhất từ trái sang phải
    for (int pos = 0; pos < len; pos++) {
        for (int d = 1; d <= 9; d++) {
            if (curr_a >= d && curr_b >= d * d && dp[curr_a - d][curr_b - d * d] == len - pos - 1) {
                printf("%d", d);
                curr_a -= d;
                curr_b -= d * d;
                break; // Chọn xong cho vị trí này, dừng để sang vị trí tiếp theo
            }
        }
    }
    printf("\n");
}

int main() {
    // Tiền xử lý tính toán DP 1 lần duy nhất cho toàn bộ chương trình
    precompute();
    
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}