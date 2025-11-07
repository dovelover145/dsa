/* 
Estimates the value of pi through random number generations (coordinates) that fall within a circle and outside the circle.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double rand_double(double low, double high);
bool insideCircle(double x, double y);

int main() {
    int seed;
    int numIterations;
    double x;
    double y;
    int circlePoints = 0;
    int totalPoints = 0;
    
    printf("Enter the seed for the random number generator: ");
    scanf("%d", &seed);

    srand(seed);

    printf("Enter the number of iterations to run: ");
    scanf("%d", &numIterations);

    for (int i = 0; i < numIterations; i++) {
        x = rand_double(-1.0, 1.0);
        y = rand_double(-1.0, 1.0);
        if (insideCircle(x, y)) {
            circlePoints++;
        }
        totalPoints++;
    }

    printf("The value of pi is %.2lf.\n",  ((double) circlePoints / (double) totalPoints) * 4.0);

    return 0;
}

/*
generate a random double between low and high inclusive
@low: the lowest possible double that can be generated
@high: the highest possible double that can be generated
@returns: a random number between low and high
*/
double rand_double(double low, double high) {
    return low + ((double) rand()) / (((double) RAND_MAX / (high - low)));
}

// finds whether a point is within the unit circle whose center is (0, 0)
// param double x is the x coordinate and double y is the y coordinate of the point (x,y)
// it returns true if inside the circle and false otherwise
bool insideCircle(double x, double y) {
    double x2 = x * x;
    double y2 = y * y;
    double radius = sqrt(x2 + y2);
    return radius <= 1.00;
}