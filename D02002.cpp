#include <stdio.h>

#define MAX_N 100005
int a[MAX_N];

// Hàm tìm kiếm nhị phân, trả về vị trí (1-based) hoặc -1 nếu không tìm thấy
int binarySearch(int n, int k) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == k) {
            return mid + 1; // Vị trí trong đề bài tính từ 1
        } else if (a[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void solve() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int result = binarySearch(n, k);
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}