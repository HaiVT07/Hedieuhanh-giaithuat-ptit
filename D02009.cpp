#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10005
long long a[MAX_N];

// Hàm so sánh cho qsort (sắp xếp tăng dần)
int compare(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// Hàm tìm giá trị lớn nhất giữa các số long long
long long max_val(long long a, long long b) {
    return (a > b) ? a : b;
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    // Sắp xếp mảng tăng dần
    qsort(a, n, sizeof(long long), compare);
    
    // Các ứng viên tích lớn nhất có thể của 2 hoặc 3 phần tử
    long long opt1 = a[n - 1] * a[n - 2];                // Hai số lớn nhất
    long long opt2 = a[0] * a[1];                        // Hai số nhỏ nhất (âm * âm)
    long long opt3 = a[n - 1] * a[n - 2] * a[n - 3];      // Ba số lớn nhất
    long long opt4 = a[0] * a[1] * a[n - 1];               // Hai số nhỏ nhất * số lớn nhất
    
    // Tìm giá trị lớn nhất trong tất cả các ứng viên
    long long max_product = opt1;
    max_product = max_val(max_product, opt2);
    max_product = max_val(max_product, opt3);
    max_product = max_val(max_product, opt4);
    
    printf("%lld\n", max_product);
}

int main() {
    solve();
    return 0;
}