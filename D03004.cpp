#include <stdio.h>
#include <string.h>

int minSwaps(char *s) {
    int n = strlen(s);
    // Nếu độ dài lẻ thì không thể tạo thành dãy ngoặc đúng (đề bài cho độ dài chẵn)
    if (n % 2 != 0) return -1;

    char stack[100005];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            // Nếu có dấu '(' ở đỉnh stack thì khớp cặp và loại bỏ
            if (top != -1 && stack[top] == '(') {
                top--;
            } else {
                stack[++top] = s[i];
            }
        } else {
            stack[++top] = s[i];
        }
    }

    // Đếm số lượng dấu '(' và ')' còn lại trong stack
    int open_brackets = 0;
    int close_brackets = 0;
    
    for (int i = 0; i <= top; i++) {
        if (stack[i] == '(') {
            open_brackets++;
        } else {
            close_brackets++;
        }
    }

    // Công thức tính số lần đổi chiều tối thiểu
    int ans = (open_brackets + 1) / 2 + (close_brackets + 1) / 2;
    return ans;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        char s[100005];
        scanf("%s", s);
        printf("%d\n", minSwaps(s));
    }
    return 0;
}