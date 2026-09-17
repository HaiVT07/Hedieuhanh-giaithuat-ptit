#include <stdio.h>
#include <string.h>
#include <ctype.h>

int evaluatePrefix(char* exp) {
    int stack[100];
    int top = -1;
    int len = strlen(exp);

    // Duyệt chuỗi từ phải sang trái
    for (int i = len - 1; i >= 0; i--) {
        // Nếu là chữ số, chuyển char thành int và push vào stack
        if (isdigit(exp[i])) {
            stack[++top] = exp[i] - '0';
        } 
        // Nếu là toán tử, pop 2 toán hạng
        else {
            int op1 = stack[top--]; // Toán hạng thứ nhất
            int op2 = stack[top--]; // Toán hạng thứ hai
            
            switch (exp[i]) {
                case '+': stack[++top] = op1 + op2; break;
                case '-': stack[++top] = op1 - op2; break;
                case '*': stack[++top] = op1 * op2; break;
                case '/': stack[++top] = op1 / op2; break; // Lấy phần nguyên
            }
        }
    }
    return stack[top];
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    
    while (T--) {
        char exp[25];
        scanf("%s", exp);
        printf("%d\n", evaluatePrefix(exp));
    }
    
    return 0;
}