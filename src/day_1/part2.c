#include<stdio.h>
#include<stdlib.h>

int calculateFileSize(FILE *fp) {
    int len = 0; // Initialize len to avoid undefined behavior
    char buffer[256]; // Allocate memory for the buffer

    while (fgets(buffer, 256, fp) != NULL){
        len++;
    }
    rewind(fp); // Reset the file pointer
    return len;
}

void sortArray(int* arr, int len){
    for (int i=0; i<len; i++){
        for (int j=0; j<i; j++){
            if (arr[i] < arr[j]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
};

int main(){
    int part = 1; // Must initialise;
    char fname[12];
    snprintf(fname, sizeof(fname), "part%d.txt", part);
    printf("Printing to %s\n", fname);

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen(fname, "w");
    if (input == NULL || output == NULL) {
        perror("Error opening file");
        return 1;
    }

    int numLines = calculateFileSize(input);
    printf("Found %d lines in the file\n", numLines);

    int arr1[numLines], arr2[numLines];
    int tmp1, tmp2;
    int count = 0;
    while (fscanf(input, "%d %d", &tmp1, &tmp2) == 2){
        arr1[count] = tmp1;
        arr2[count] = tmp2;
        count++;
    };

    sortArray(arr1, numLines);
    sortArray(arr2, numLines);

    int simScore=0;
    for (int i=0; i<numLines; i++){
        int multiples=0;
        for (int j=0; j<numLines; j++){
            if (arr1[i] == arr2[j]){
                multiples++;
            }
        }
        simScore += multiples * arr1[i];
    }
    printf("%d\n",simScore);
    return 0;
}