#include <stdio.h>

// Hàm hoán đổi 2 số nguyên
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    // Đọc số lượng phần tử N
    if (scanf("%d", &n) != 1) return 0;
    
    int a[105];
    // Đọc N phần tử của mảng
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Thuật toán Sắp xếp chọn
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        
        // Tìm vị trí của phần tử nhỏ nhất trong đoạn từ i+1 đến n-1
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        
        // Đưa phần tử nhỏ nhất tìm được về vị trí i
        swap(&a[i], &a[min_idx]);
        
        // In ra mảng sau mỗi bước hoán đổi
        printf("Buoc %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d", a[k]);
            if (k < n - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}