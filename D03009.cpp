#include <stdio.h>

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    
    long long h[100005];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &h[i]);
    }
    
    int stack[100005];
    int top = -1;
    long long max_area = 0;
    
    int i = 0;
    while (i < n) {
        // Nếu stack rỗng hoặc chiều cao cột hiện tại lớn hơn/bằng cột trên đỉnh stack
        if (top == -1 || h[i] >= h[stack[top]]) {
            stack[++top] = i++;
        } else {
            // Lấy cột đỉnh stack ra làm chiều cao
            int tp = stack[top--];
            
            // Tính chiều rộng
            long long width = (top == -1) ? i : (i - stack[top] - 1);
            long long area = h[tp] * width;
            
            if (area > max_area) {
                max_area = area;
            }
        }
    }
    
    // Rút hết các phần tử còn lại trong stack
    while (top != -1) {
        int tp = stack[top--];
        long long width = (top == -1) ? i : (i - stack[top] - 1);
        long long area = h[tp] * width;
        
        if (area > max_area) {
            max_area = area;
        }
    }
    
    printf("%lld\n", max_area);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}