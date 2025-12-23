#include <stdio.h>

#define M 100   // 2-digit address space

void insert(int hashTable[], int key) {
    int index = key % M;
    while (hashTable[index] != -1)
        index = (index + 1) % M;
    hashTable[index] = key;
}

void display(int hashTable[]) {
    for (int i = 0; i < M; i++) {
        if (hashTable[i] != -1)
            printf("Address %02d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;
    int hashTable[M];

    for (int i = 0; i < M; i++)
        hashTable[i] = -1;
    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter 4-digit key: ");
        scanf("%d", &key);
        insert(hashTable, key);
    }

    printf("\nHash Table:\n");
    display(hashTable);

    return 0;
}

