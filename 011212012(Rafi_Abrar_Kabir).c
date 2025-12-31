#include <stdio.h>
#include <string.h>


int FindingMinimum(int a, int b, int c);

void Process(char FirstString[], char SecondString[]);

int main() {
    char FirstString[]="RAFI";
    char SecondString[]="ABRAR";
    Process(FirstString, SecondString);
    return 0;
}

void Process(char FirstString[], char SecondString[]){
    int x = strlen(FirstString);
    printf("%d\n",x);
    int y = strlen(SecondString);
    printf("%d\n",y);
    int Table[x+1][y+1];
    for (int i = 0; i <= x; i++) {
        Table[i][0] = i;
    }
    for (int j = 0; j <= y; j++) {
        Table[0][j] = j;
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (FirstString[i-1] != SecondString[j-1]) {
                    Table[i][j] = 1 + FindingMinimum(Table[i-1][j], Table[i][j-1], Table[i-1][j-1]);
            }
            else{
                Table[i][j] = Table[i-1][j-1];
            }
        }
    }
    printf("Edit Distance:%d", Table[x][y]);
}

int FindingMinimum(int a, int b, int c) {
    if((a<b) && (a<c)){
        return a;
    }
    else if((b<a) && (b<c)){
        return b;
    }
    else if((c<a) && (c<b)){
        return c;
    }
}
