#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state[6];
    int steps;
} Node;

// Hash Table đơn giản để đánh dấu các trạng thái đã đi qua (6 số từ 1-6 có tối đa 6! = 720 hoán vị)
#define HASH_SIZE 10007

typedef struct HashNode {
    int key;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[HASH_SIZE];

int stateToInt(int a[]) {
    int num = 0;
    for (int i = 0; i < 6; i++) {
        num = num * 10 + a[i];
    }
    return num;
}

int isVisited(int key) {
    int idx = key % HASH_SIZE;
    HashNode* curr = hashTable[idx];
    while (curr != NULL) {
        if (curr->key == key) return 1;
        curr = curr->next;
    }
    return 0;
}

void markVisited(int key) {
    int idx = key % HASH_SIZE;
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
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

// Quay hình vuông bên trái
void rotateLeft(int src[], int dest[]) {
    dest[0] = src[3];
    dest[1] = src[0];
    dest[2] = src[2];
    dest[3] = src[4];
    dest[4] = src[1];
    dest[5] = src[5];
}

// Quay hình vuông bên phải
void rotateRight(int src[], int dest[]) {
    dest[0] = src[0];
    dest[1] = src[4];
    dest[2] = src[1];
    dest[3] = src[3];
    dest[4] = src[5];
    dest[5] = src[2];
}

void solve() {
    int start[6], target[6];
    for (int i = 0; i < 6; i++) scanf("%d", &start[i]);
    for (int i = 0; i < 6; i++) scanf("%d", &target[i]);

    int targetKey = stateToInt(target);
    int startKey = stateToInt(start);

    if (startKey == targetKey) {
        printf("0\n");
        return;
    }

    clearHash();

    Node queue[1000];
    int front = 0, rear = 0;

    Node startNode;
    for (int i = 0; i < 6; i++) startNode.state[i] = start[i];
    startNode.steps = 0;

    queue[rear++] = startNode;
    markVisited(startKey);

    while (front < rear) {
        Node curr = queue[front++];

        int currKey = stateToInt(curr.state);
        if (currKey == targetKey) {
            printf("%d\n", curr.steps);
            return;
        }

        // Thao tác 1: Quay trái
        Node nextL;
        rotateLeft(curr.state, nextL.state);
        nextL.steps = curr.steps + 1;
        int keyL = stateToInt(nextL.state);
        if (!isVisited(keyL)) {
            markVisited(keyL);
            queue[rear++] = nextL;
        }

        // Thao tác 2: Quay phải
        Node nextR;
        rotateRight(curr.state, nextR.state);
        nextR.steps = curr.steps + 1;
        int keyR = stateToInt(nextR.state);
        if (!isVisited(keyR)) {
            markVisited(keyR);
            queue[rear++] = nextR;
        }
    }
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