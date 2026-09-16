#include <stdio.h>

#define MOD 1000000007
#define MAX_N 100005

long long dp[MAX_N];

void solve() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return;

    dp[0] = 1;
    long long current_sum = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = current_sum;
        
        // Thêm giá trị mới vào tổng cửa sổ trượt
        current_sum = (current_sum + dp[i]) % MOD;

        // Nếu cửa sổ vượt quá kích thước K, loại bỏ phần tử cũ ra khỏi tổng
        if (i >= k) {
            current_sum = (current_sum - dp[i - k] + MOD) % MOD;
        }
    }

    printf("%lld\n", dp[n]);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}