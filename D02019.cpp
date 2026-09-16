#include <stdio.h>

// Hàm đệ quy chia để trị tìm số thứ K
long long find_val(int n, long long k) {
    // Tìm vị trí phần tử chính giữa: 2^(n-1). 
    // Dùng 1LL để đảm bảo dịch bit trên kiểu 64-bit, tránh tràn số học.
    long long mid = 1LL << (n - 1); 
    
    // Nếu K nằm ngay chính giữa
    if (k == mid) {
        return n;
    } 
    // Nếu K nằm ở nửa bên trái
    else if (k < mid) {
        return find_val(n - 1, k);
    } 
    // Nếu K nằm ở nửa bên phải
    else {
        return find_val(n - 1, k - mid);
    }
}

void solve() {
    int n;
    long long k;
    if (scanf("%d %lld", &n, &k) != 2) return;
    
    printf("%lld\n", find_val(n, k));
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