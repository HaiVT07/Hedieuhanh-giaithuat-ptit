#include <stdio.h>

void solve() {
    int n, s;
    if (scanf("%d %d", &n, &s) != 2) return;

    // Kiểm tra điều kiện không thể tạo được
    if (s > 9 * n || (s == 0 && n > 1)) {
        printf("-1 -1\n");
        return;
    }
    if (s == 0 && n == 1) {
        printf("0 0\n");
        return;
    }

    char smallest[105], largest[105];
    smallest[n] = '\0';
    largest[n] = '\0';

    // 1. Tìm số nhỏ nhất
    int temp_s = s - 1;
    for (int i = n - 1; i > 0; i--) {
        if (temp_s > 9) {
            smallest[i] = '9';
            temp_s -= 9;
        } else {
            smallest[i] = '0' + temp_s;
            temp_s = 0;
        }
    }
    smallest[0] = '1' + temp_s;

    // 2. Tìm số lớn nhất
    temp_s = s;
    for (int i = 0; i < n; i++) {
        if (temp_s > 9) {
            largest[i] = '9';
            temp_s -= 9;
        } else {
            largest[i] = '0' + temp_s;
            temp_s = 0;
        }
    }

    printf("%s %s\n", smallest, largest);
}

int main() {
    solve();
    return 0;
}