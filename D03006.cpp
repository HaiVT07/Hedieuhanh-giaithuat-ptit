#include <stdio.h>
#include <string.h>

#define MAX 1000005

char s[MAX];
char leftStack[MAX];
char rightStack[MAX];

void solve() {
    if (scanf("%s", s) != 1) return;
    int n = strlen(s);

    int topL = -1; // Đỉnh stack trái
    int topR = -1; // Đỉnh stack phải

    for (int i = 0; i < n; i++) {
        if (s[i] == '<') {
            if (topL >= 0) {
                rightStack[++topR] = leftStack[topL--];
            }
        } else if (s[i] == '>') {
            if (topR >= 0) {
                leftStack[++topL] = rightStack[topR--];
            }
        } else if (s[i] == '-') {
            if (topL >= 0) {
                topL--;
            }
        } else {
            leftStack[++topL] = s[i];
        }
    }

    // In ra kết quả từ stack trái (từ đáy đến đỉnh)
    for (int i = 0; i <= topL; i++) {
        putchar(leftStack[i]);
    }
    // In ra kết quả từ stack phải (từ đỉnh đến đáy)
    for (int i = topR; i >= 0; i--) {
        putchar(rightStack[i]);
    }
    putchar('\n');
}

int main() {
    solve();
    return 0;
}