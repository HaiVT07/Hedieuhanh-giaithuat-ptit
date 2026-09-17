#include <stdio.h>
#include <string.h>

void solve() {
    char s[105];
    if (scanf("%s", s) != 1) return;
    int n = strlen(s);
    
    int open_count = 0; // Đếm số dấu '(' đang chờ ghép cặp
    int valid_pairs = 0; // Đếm số cặp ngoặc () đúng
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            open_count++;
        } else if (s[i] == ')') {
            if (open_count > 0) {
                valid_pairs++;
                open_count--;
            }
        }
    }
    
    // Mỗi cặp đúng có độ dài là 2
    printf("%d\n", valid_pairs * 2);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}