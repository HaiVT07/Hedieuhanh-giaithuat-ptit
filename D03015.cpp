#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int val;
    int step;
} Node;

// Cấu trúc bảng băm đơn giản (Hash Set) để đánh dấu các số đã visited
#define HASH_SIZE 100003

typedef struct HashNode {
    int val;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[HASH_SIZE];

int isVisited(int val) {
    int idx = val % HASH_SIZE;
    if (idx < 0) idx += HASH_SIZE;
    HashNode* curr = hashTable[idx];
    while (curr != NULL) {
        if (curr->val == val) return 1;
        curr = curr->next;
    }
    return 0;
}

void markVisited(int val) {
    int idx = val % HASH_SIZE;
    if (idx < 0) idx += HASH_SIZE;
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->val = val;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

void clearHash() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* curr = hashTable[i];
        while (curr != NULL) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    clearHash();

    // Khởi tạo Queue
    Node* queue = (Node*)malloc(1000000 * sizeof(Node));
    int front = 0, rear = 0;

    queue[rear++] = (Node){n, 0};
    markVisited(n);

    int ans = 0;

    while (front < rear) {
        Node top = queue[front++];

        if (top.val == 1) {
            ans = top.step;
            break;
        }

        // Thao tác (a): N - 1
        if (top.val - 1 >= 1 && !isVisited(top.val - 1)) {
            markVisited(top.val - 1);
            queue[rear++] = (Node){top.val - 1, top.step + 1};
        }

        // Thao tác (b): max(u, v) với u * v = N chính là u / i
        int limit = (int)sqrt(top.val);
        for (int i = 2; i <= limit; i++) {
            if (top.val % i == 0) {
                int next_val = top.val / i;
                if (!isVisited(next_val)) {
                    markVisited(next_val);
                    queue[rear++] = (Node){next_val, top.step + 1};
                }
            }
        }
    }

    free(queue);
    printf("%d\n", ans);
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