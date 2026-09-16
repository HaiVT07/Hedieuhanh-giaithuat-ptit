#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// N < 16, độ dài mỗi từ <= 20
// Ghép tối đa 15 từ -> độ dài xâu kết quả tối đa là 15 * 20 = 300
#define MAX_WORDS 16
#define MAX_LEN 320
#define MAX_RESULTS 33000

char words[MAX_WORDS][25];
char results[MAX_RESULTS][MAX_LEN];
int result_count = 0;
int N;

// Hàm quay lui duyệt tập con
void generate_subsets(int index, char *current_str) {
    if (index == N) {
        return;
    }

    // Lựa chọn 1: Không chọn words[index]
    generate_subsets(index + 1, current_str);

    // Lựa chọn 2: Chọn words[index]
    int len = strlen(current_str);
    strcat(current_str, words[index]);
    
    // Lưu xâu kết quả mới tạo thành
    strcpy(results[result_count++], current_str);

    // Tiếp tục duyệt các từ tiếp theo
    generate_subsets(index + 1, current_str);

    // Backtrack (Khôi phục trạng thái cũ)
    current_str[len] = '\0';
}

// Hàm so sánh cho qsort
int compare_strings(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    if (scanf("%d", &N) != 1) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }

    char current_str[MAX_LEN] = "";
    
    // Sinh tất cả các tập con
    generate_subsets(0, current_str);

    // Sắp xếp các xâu thu được theo thứ tự từ điển
    qsort(results, result_count, sizeof(results[0]), compare_strings);

    // In ra kết quả và loại bỏ xâu trùng lặp
    for (int i = 0; i < result_count; i++) {
        if (i == 0 || strcmp(results[i], results[i - 1]) != 0) {
            printf("%s\n", results[i]);
        }
    }

    return 0;
}