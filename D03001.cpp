#include <stdio.h>
#include <string.h>

// Hàm kiểm tra một xâu S có phải dãy ngoặc đúng không
int isValid(char *s) {
    int n = strlen(s);
    char stack[100005];
    int top = -1; // Khởi tạo stack rỗng

    for (int i = 0; i < n; i++) {
        char c = s[i];
        // Nếu là dấu mở, đưa vào stack
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } 
        // Nếu là dấu đóng
        else if (c == ')' || c == ']' || c == '}') {
            // Nếu stack rỗng hoặc không khớp với đỉnh stack
            if (top == -1) return 0;
            char open = stack[top--];
            if (c == ')' && open != '(') return 0;
            if (c == ']' && open != '[') return 0;
            if (c == '}' && open != '{') return 0;
        }
    }
    // Nếu stack rỗng sau khi duyệt xong thì là đúng
    return top == -1;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        char s[100005];
        scanf("%s", s);
        if (isValid(s)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}