#include <stdio.h>
#include <stdlib.h>

// Khai báo mảng lớn toàn cục để tránh tràn Stack (n <= 1,000,000)
#define MAX_N 1000005
int a[MAX_N];

// Hàm so sánh dùng cho qsort (sắp xếp tăng dần)
int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sắp xếp mảng với qsort (Độ phức tạp O(n log n))
    qsort(a, n, sizeof(int), compare);
    
    // In kết quả
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}