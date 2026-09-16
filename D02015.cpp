#include <stdio.h>

// Hàm tìm giá trị lớn nhất của 2 số long long
long long max_val(long long a, long long b) {
    return (a > b) ? a : b;
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    
    long long prev2 = 0; // Tương đương dp[i-2]
    long long prev1 = 0; // Tương đương dp[i-1]
    
    // Duyệt qua từng ngôi nhà (đọc dữ liệu trực tiếp on-the-fly)
    for (int i = 0; i < n; i++) {
        long long val;
        scanf("%lld", &val);
        
        // Tính dp hiện tại: max của (bỏ qua nhà này, trộm nhà này + dp[i-2])
        long long current_dp = max_val(prev1, prev2 + val);
        
        // Cập nhật lại 2 biến cho bước tiếp theo
        prev2 = prev1;
        prev1 = current_dp;
    }
    
    // Kết quả lớn nhất nằm ở biến prev1
    printf("%lld\n", prev1);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}