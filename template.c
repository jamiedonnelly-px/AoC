#include<stdio.h>

int main(){
    int part; // Must initialise;
    char fname[12];
    snprintf(fname, sizeof(fname), "part%d.txt", part);
    FILE *input, *output;
    input = fopen("input.txt", "r");
    return 0;
}