#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 16
#define MAX_LEN 320
#define MAX_RESULTS 7000

char words[MAX_WORDS][25];
char results[MAX_RESULTS][MAX_LEN];
int result_count = 0;
int N, K;

// Hàm quay lui chọn đúng K từ theo đúng thứ tự
void generate_combinations(int index, int chosen_count, char *current_str) {
    if (chosen_count == K) {
        strcpy(results[result_count++], current_str);
        return;
    }
    
    // Nếu số từ còn lại không đủ để chọn đủ K từ thì dừng nhánh
    if (index + (K - chosen_count) > N) {
        return;
    }

    for (int i = index; i < N; i++) {
        int len = strlen(current_str);
        
        // Thêm từ hiện tại vào chuỗi
        strcat(current_str, words[i]);
        
        // Đệ quy chọn từ tiếp theo
        generate_combinations(i + 1, chosen_count + 1, current_str);
        
        // Backtrack (Khôi phục trạng thái chuỗi cũ)
        current_str[len] = '\0';
    }
}

// Hàm so sánh cho qsort
int compare_strings(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    if (scanf("%d %d", &N, &K) != 2) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }

    char current_str[MAX_LEN] = "";
    
    // Sinh các tổ hợp K từ
    generate_combinations(0, 0, current_str);

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