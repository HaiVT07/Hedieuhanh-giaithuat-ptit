#include <stdio.h>

#define MAX_N 1005

int a[MAX_N];
int b[MAX_N]; // Mảng B lưu các phần tử đuôi nhỏ nhất của dãy con tăng

// Hàm tìm kiếm nhị phân tìm vị trí đầu tiên trong mảng arr có giá trị >= key
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= key) {
            right = mid - 1; // Tiếp tục tìm về phía bên trái để lấy vị trí đầu tiên
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n;
    // Đọc số lượng phần tử N
    if (scanf("%d", &n) != 1) return 0;
    
    // Đọc các phần tử của dãy A
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int len = 0; // Biến lưu độ dài của dãy con tăng dài nhất
    
    for (int i = 0; i < n; i++) {
        // Tìm vị trí thích hợp để chèn hoặc thay thế a[i] trong mảng b
        int pos = binarySearch(b, 0, len - 1, a[i]);
        
        // Cập nhật giá trị đuôi nhỏ nhất tại vị trí pos
        b[pos] = a[i];
        
        // Nếu a[i] lớn hơn tất cả các phần tử hiện tại trong b, dãy con được mở rộng
        if (pos == len) {
            len++;
        }
    }

    // In ra độ dài của dãy con tăng dài nhất
    printf("%d\n", len);

    return 0;
}