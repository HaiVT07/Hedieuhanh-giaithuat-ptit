#include <stdio.h>

#define MOD 1000000007

// Hàm tính (a * b) % MOD tránh tràn số khi nhân hai số nguyên lớn
long long multiply(long long a, long long b) {
    return (a * b) % MOD;
}

// Hàm tính lũy thừa nhị phân: (base^exp) % MOD
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        // Nếu số mũ lẻ, nhân cơ số vào kết quả
        if (exp % 2 == 1) {
            res = multiply(res, base);
        }
        // Bình phương cơ số và giảm số mũ đi một nửa
        base = multiply(base, base);
        exp /= 2;
    }
    return res;
}

void solve() {
    long long n, k;
    if (scanf("%lld %lld", &n, &k) != 2) return;
    
    printf("%lld\n", power(n, k));
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}