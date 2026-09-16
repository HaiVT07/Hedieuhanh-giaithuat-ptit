#include <stdio.h>
#include <string.h>

#define MAX_LEN 1005

// Khai báo mảng 2 chiều toàn cục để tránh tràn bộ nhớ Stack
int dp[MAX_LEN][MAX_LEN];
char s1[MAX_LEN], s2[MAX_LEN];

// Hàm tìm giá trị lớn nhất
int max_val(int a, int b) {
    return (a > b) ? a : b;
}

void solve() {
    // Nhập 2 xâu S1 và S2
    scanf("%s", s1);
    scanf("%s", s2);
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Cần reset lại hàng 0 và cột 0 cho mỗi bộ test mới
    for (int i = 0; i <= len1; i++) dp[i][0] = 0;
    for (int j = 0; j <= len2; j++) dp[0][j] = 0;

    // Duyệt quy hoạch động
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Hai ký tự khớp
            } else {
                dp[i][j] = max_val(dp[i - 1][j], dp[i][j - 1]); // Không khớp
            }
        }
    }
    
    // In kết quả là phần tử ở góc dưới cùng bên phải mảng
    printf("%d\n", dp[len1][len2]);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}