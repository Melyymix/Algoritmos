#include <stdio.h>
#include <string.h>

#define MAX 10000

typedef struct {
    char transaction_id[20];
    int amount;
} Transaction;

int exists(char seen[][20], int size, char *id) {
    for (int i = 0; i < size; i++) {
        if (strcmp(seen[i], id) == 0) {
            return 1;
        }
    }
    return 0;
}

int removeDuplicates(Transaction input[], int n, Transaction output[]) {
    char seen[MAX][20];
    int seen_count = 0;
    int out_index = 0;

    for (int i = 0; i < n; i++) {
        if (!exists(seen, seen_count, input[i].transaction_id)) {
            strcpy(seen[seen_count++], input[i].transaction_id);
            output[out_index++] = input[i];
        }
    }

    return out_index;
}

int main() {
    FILE *file = fopen("transaction_data.csv", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    Transaction input[MAX];
    int count = 0;
    char line[100];

    // Saltar encabezado
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%d", input[count].transaction_id, &input[count].amount);
        count++;
    }

    fclose(file);

    Transaction output[MAX];
    int new_size = removeDuplicates(input, count, output);

    printf("Total original: %d\n", count);
    printf("Sin duplicados: %d\n\n", new_size);

    // 🔥 AHORA IMPRIME TODO
    for (int i = 0; i < new_size; i++) {
        printf("%s - %d\n", output[i].transaction_id, output[i].amount);
    }

    return 0;
}