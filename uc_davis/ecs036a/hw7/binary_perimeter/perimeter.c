/*
Calculates the perimeter of an arbitrary, convex shape by reading the vertices of the shape from a binary file.
*/

#include <stdio.h>
#include <math.h>

void printPerimeter(FILE* inFile);

struct Point {
    int x;
    int y;
};

int main(int argc, char* argv[]) {
    FILE* inFile;

    inFile = fopen(argv[1], "rb");
    if (inFile == NULL) {
        return -1;
    }

    printPerimeter(inFile);

    return 0;
}

/*
Prints the perimeter given a binary file's contents.
@param: inFile: Pointer to the file structure.
@return: void.
*/
void printPerimeter(FILE* inFile) {
    int vertices;
    struct Point startingPoint;
    struct Point previousPoint;
    struct Point currentPoint;
    double perimeter = 0.0;

    fread(&vertices, sizeof(int), 1, inFile); // Read in the number of points that make up the shape

    fread(&startingPoint.x, sizeof(int), 1, inFile);
    fread(&startingPoint.y, sizeof(int), 1, inFile);

    previousPoint.x = startingPoint.x;
    previousPoint.y = startingPoint.y;

    for (int i = 1; i < vertices; i++) {
        fread(&currentPoint.x, sizeof(int), 1, inFile);
        fread(&currentPoint.y, sizeof(int), 1, inFile);

        perimeter += sqrt(pow(currentPoint.x - previousPoint.x, 2) + pow(currentPoint.y - previousPoint.y, 2));

        previousPoint.x = currentPoint.x;
        previousPoint.y = currentPoint.y;
    }

    perimeter += sqrt(pow(startingPoint.x - currentPoint.x, 2) + pow(startingPoint.y - currentPoint.y, 2));

    printf("The perimeter is %.2lf\n", perimeter);
}