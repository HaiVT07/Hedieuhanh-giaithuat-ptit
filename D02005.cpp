#include <stdio.h>

// Mảng các mệnh giá tiền giảm dần
int coins[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
int num_coins = 10;

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    
    int total_notes = 0;
    for (int i = 0; i < num_coins; i++) {
        if (n >= coins[i]) {
            total_notes += n / coins[i]; // Số tờ tiền mệnh giá coins[i]
            n %= coins[i];               // Số tiền còn lại sau khi đổi
        }
    }
    
    printf("%d\n", total_notes);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}