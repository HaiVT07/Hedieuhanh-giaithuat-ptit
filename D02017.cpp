#include <stdio.h>

#define MAX_N 505

// Dùng double để so sánh số thực an toàn và chính xác hơn float
double a[MAX_N], b[MAX_N];
int dp[MAX_N];

// Hàm tìm giá trị lớn nhất của 2 số nguyên
int max_val(int x, int y) {
    return (x > y) ? x : y;
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    
    // Nhập dữ liệu và khởi tạo mảng dp
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &a[i], &b[i]);
        dp[i] = 1; // Mỗi phần tử tự tạo thành 1 dãy độ dài 1
    }
    
    int max_len = 0; // Biến lưu kết quả cuối cùng
    
    // Duyệt quy hoạch động
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Kiểm tra điều kiện: A tăng ngặt VÀ B giảm ngặt
            if (a[j] < a[i] && b[j] > b[i]) {
                dp[i] = max_val(dp[i], dp[j] + 1);
            }
        }
        // Liên tục cập nhật giá trị lớn nhất tìm được
        max_len = max_val(max_len, dp[i]);
    }
    
    // In kết quả
    printf("%d\n", max_len);
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