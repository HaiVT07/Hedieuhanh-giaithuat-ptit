#include <stdio.h>

int main() {
    int n;
    // Đọc số lượng phần tử N
    if (scanf("%d", &n) != 1) return 0;
    
    int a[105];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Bước 0: In ra phần tử đầu tiên khi coi như dãy con dài 1 đã được sắp xếp
    printf("Buoc 0: %d\n", a[0]);
    
    // Thuật toán Sắp xếp chèn
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        
        // Dịch chuyển các phần tử lớn hơn key sang phải
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        
        // Chèn key vào vị trí đúng
        a[j + 1] = key;
        
        // In ra trạng thái mảng từ 0 đến i sau bước chèn
        printf("Buoc %d: ", i);
        for (int k = 0; k <= i; k++) {
            printf("%d", a[k]);
            if (k < i) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}