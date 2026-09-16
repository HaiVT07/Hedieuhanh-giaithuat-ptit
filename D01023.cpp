#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 16
#define MAX_LEN 140
#define MAX_RESULTS 33000

char numbers[MAX_N][15];
char results[MAX_RESULTS][MAX_LEN];
int result_count = 0;
int N;

// Hàm quay lui sinh tập con
void generate_subsets(int index, char *current_str) {
    if (index == N) {
        return;
    }

    // Lựa chọn 1: Không chọn numbers[index]
    generate_subsets(index + 1, current_str);

    // Lựa chọn 2: Chọn numbers[index]
    int len = strlen(current_str);
    strcat(current_str, numbers[index]);

    // Lưu kết quả xâu vừa tạo thành
    strcpy(results[result_count++], current_str);

    // Tiếp tục xét phần tử tiếp theo
    generate_subsets(index + 1, current_str);

    // Backtrack (Khôi phục lại chuỗi cũ)
    current_str[len] = '\0';
}

// Hàm so sánh cho qsort
int compare_strings(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    if (scanf("%d", &N) != 1) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", numbers[i]);
    }

    char current_str[MAX_LEN] = "";
    
    // Sinh các tập con
    generate_subsets(0, current_str);

    // Sắp xếp kết quả theo thứ tự từ điển
    qsort(results, result_count, sizeof(results[0]), compare_strings);

    // In kết quả và loại bỏ các xâu trùng lặp
    for (int i = 0; i < result_count; i++) {
        if (i == 0 || strcmp(results[i], results[i - 1]) != 0) {
            printf("%s\n", results[i]);
        }
    }

    return 0;
}