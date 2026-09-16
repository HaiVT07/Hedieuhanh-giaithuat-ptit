#include <stdio.h>

long long F[93];

// Hàm khởi tạo độ dài các xâu Fibonacci
void precompute() {
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= 92; i++) {
        F[i] = F[i - 2] + F[i - 1];
    }
}

// Hàm đệ quy tìm ký tự ở vị trí i trong G(n)
char findChar(int n, long long i) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    
    // Nếu i nằm trong nửa đầu G(n-2)
    if (i <= F[n - 2]) {
        return findChar(n - 2, i);
    } else {
        // Nếu i nằm trong nửa sau G(n-1)
        return findChar(n - 1, i - F[n - 2]);
    }
}

void solve() {
    int n;
    long long i;
    if (scanf("%d %lld", &n, &i) != 2) return;
    
    printf("%c\n", findChar(n, i));
}

int main() {
    precompute();
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}