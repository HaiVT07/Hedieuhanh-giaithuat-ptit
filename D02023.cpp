#include <stdio.h>

void bubbleSort(int a[], int n) {
    int step = 1;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        // Thực hiện nổi bọt cho từng phần tử chưa đúng vị trí
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Đổi chỗ hai phần tử
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        
        // Nếu trong vòng lặp này có sự thay đổi, in ra bước thực hiện
        if (swapped) {
            printf("Buoc %d:", step++);
            for (int k = 0; k < n; k++) {
                printf(" %d", a[k]);
            }
            printf("\n");
        } else {
            // Nếu mảng đã có thứ tự từ trước, không cần tiếp tục
            break;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    bubbleSort(a, n);
    return 0;
}