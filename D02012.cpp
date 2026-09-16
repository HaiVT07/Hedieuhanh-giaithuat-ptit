#include <stdio.h>

#define MAX_M 5005

// Mảng 1 chiều lưu trữ kết quả bài toán cái túi
int dp[MAX_M];

// Hàm tìm giá trị lớn nhất giữa 2 số
int max_val(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, M;
    // Đọc số lượng đồ vật (n) và sức chứa của túi (M)
    if (scanf("%d %d", &n, &M) != 2) return 0;
    
    // Duyệt qua từng món hàng
    for (int i = 0; i < n; i++) {
        int weight, value;
        scanf("%d %d", &weight, &value);
        
        // Cập nhật mảng dp[] theo chiều ngược từ M về weight
        // Việc duyệt ngược đảm bảo mỗi món hàng chỉ được chọn 1 lần
        for (int j = M; j >= weight; j--) {
            dp[j] = max_val(dp[j], dp[j - weight] + value);
        }
    }
    
    // Kết quả lớn nhất nằm ở dp[M] (khi sử dụng tối đa sức chứa M)
    printf("%d\n", dp[M]);
    
    return 0;
}