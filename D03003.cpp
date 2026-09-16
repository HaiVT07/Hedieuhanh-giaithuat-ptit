#include <stdio.h>
#include <string.h>

// Hàm kiểm tra một biểu thức có ngoặc dư thừa không
int checkRedundantBrackets(char *s) {
    int n = strlen(s);
    char stack[100];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] != ')') {
            // Đẩy tất cả các ký tự khác dấu ')' vào stack
            stack[++top] = s[i];
        } else {
            // Gặp dấu ')', ta pop các phần tử ra để kiểm tra bên trong cặp ngoặc
            int hasOperator = 0;
            int innerElements = 0;

            while (top != -1 && stack[top] != '(') {
                char c = stack[top--];
                // Kiểm tra xem có toán tử bên trong không
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    hasOperator = 1;
                }
                // Đếm số lượng phần tử bên trong (bỏ qua khoảng trắng nếu có)
                if (c != ' ') {
                    innerElements++;
                }
            }

            // Bỏ dấu '(' ra khỏi stack
            if (top != -1) {
                top--;
            }

            // Nếu không có toán tử bên trong, hoặc bên trong chỉ chứa đúng 1 phần tử đơn lẻ
            if (!hasOperator || innerElements <= 1) {
                return 1; // Phát hiện ngoặc dư thừa
            }
        }
    }
    return 0; // Không có ngoặc dư thừa
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    getchar(); // Đọc ký tự xuống dòng sau số lượng test
    while (t--) {
        char s[105];
        fgets(s, sizeof(s), stdin);
        // Xóa ký tự xuống dòng cuối chuỗi nếu có
        s[strcspn(s, "\n")] = 0;
        
        if (checkRedundantBrackets(s)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}