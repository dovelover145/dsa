/*
Prints Pascal's triangle with the specified number of levels.
*/

#include <stdio.h>

void printTriangle(int levels);

int main() {
    int levels;
    
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &levels);

    printTriangle(levels);

    return 0;
}

/*
Prints Pascal's triangle.
@param levels: The number of levels of Pascal's triangle to print.
@return: void.
*/
void printTriangle(int levels) {
    int pTriangle[levels];

    pTriangle[0] = 1;
    pTriangle[1] = 1;

    if (levels == 1) {
        printf("%d\n", pTriangle[0]);
    } else if (levels >= 2) {
        printf("%d\n", pTriangle[0]);
        printf("%d %d\n", pTriangle[0], pTriangle[1]);
    }
    
    if (levels > 2) {
        int prev = pTriangle[0]; // Always a 1
        int temp;
        
        for (int i = 2; i < levels; i++) {
            for (int j = 1; j <= i; j++) {
                temp = pTriangle[j];
                pTriangle[j] = pTriangle[j] + prev;
                prev = temp;
            }
            
            pTriangle[i] = 1;
            
            for (int j = 0; j <= i; j++) {
                printf("%d ", pTriangle[j]);
            }
            printf("\n");

            prev = pTriangle[0]; // Always a 1
        }
    }
}