#include <stdio.h>

#define MAX_N 10005

int dp[MAX_N];

// Hàm tìm giá trị nhỏ nhất
int min_val(int a, int b) {
    return (a < b) ? a : b;
}

// Hàm tính trước kết quả cho mọi N từ 1 đến 10000
void precompute() {
    dp[0] = 0; // Cơ sở quy hoạch động

    for (int i = 1; i <= 10000; i++) {
        // Trường hợp xấu nhất là tổng của i số 1 (ví dụ 5 = 1+1+1+1+1)
        dp[i] = i; 
        
        // Thử trừ đi các bình phương j*j nhỏ hơn hoặc bằng i
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min_val(dp[i], dp[i - j * j] + 1);
        }
    }
}

int main() {
    // Tính toán trước toàn bộ bảng DP để tăng tốc cho tất cả các test
    precompute();

    int t;
    if (scanf("%d", &t) != 1) return 0;
    
    while (t--) {
        int n;
        scanf("%d", &n);
        // Trả kết quả trực tiếp với độ phức tạp O(1)
        printf("%d\n", dp[n]);
    }
    
    return 0;
}