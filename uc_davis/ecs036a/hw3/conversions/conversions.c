/*
Converts from user for temperature or distance calculation from F, C, and K, or I, F, Y, and M respectively into another unit
from the same list. It doesn't allow invalid inputs. 
*/

#include <stdio.h>
#include <stdlib.h> // for exit()
#include <ctype.h> // for toupper()

void checkFormatError();
void checkUnknownConversion(char dimension);
void checkInvalidUnit(char startingUnit, char dimension);
void convert(char dimension, char startingUnit, double startingValue, char endingUnit);

int main() {    
    char dimension = '\0'; // Stores the dimension of the conversion
    double startingValue = 0.0; // Value in startingUnit units
    char startingUnit = '\0'; // Stores the unit to convert from
    char endingUnit = '\0'; // Stores the unit to convert to
    
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");

    printf("Enter your choice: ");
    scanf(" %c", &dimension);

    dimension = toupper(dimension);

    checkFormatError(); // Check that a newline character is after the character; if not, then format is invalid
    checkUnknownConversion(dimension); // Check if character received is valid; skip leading whitespace

    if (dimension == 'T') {
        printf("Enter the temperature followed by its suffix (F, C, or K): ");
        if (scanf(" %lf", &startingValue) == 0) {
            printf("Invalid formatting. Ending program.\n");
            exit(0);
        }
        scanf(" %c", &startingUnit);

        startingUnit = toupper(startingUnit);

        checkFormatError();
        checkInvalidUnit(startingUnit, dimension);

        printf("Enter the new unit type (F, C, or K): ");
        scanf(" %c", &endingUnit);

        endingUnit = toupper(endingUnit);

        checkFormatError();
        checkInvalidUnit(endingUnit, dimension);

        convert(dimension, startingUnit, startingValue, endingUnit);
    } else { // dimension is 'D'
        printf("Enter the distance followed by its suffix (I,F,Y,M): ");
        if (scanf(" %lf", &startingValue) == 0) {
            printf("Invalid formatting. Ending program.\n");
            exit(0);
        }
        scanf(" %c", &startingUnit);

        startingUnit = toupper(startingUnit);

        checkFormatError();
        checkInvalidUnit(startingUnit, dimension);

        printf("Enter the new unit type (I,F,Y,M): ");
        scanf(" %c", &endingUnit);

        endingUnit = toupper(endingUnit);

        checkFormatError();
        checkInvalidUnit(endingUnit, dimension);

        convert(dimension, startingUnit, startingValue, endingUnit);
    }

    return 0; 
}

/*
Makes sure that the dimension (temperature or distance) is given validly and not another character other than
T or D. (t or d is capitalized and assumed before).
Parameter dimension is the character representing the temperature or distance.
No return value.
*/
void checkUnknownConversion(char dimension) {
    if (dimension != 'T' && dimension != 'D') {
        printf("Unknown conversion type %c chosen. Ending program.\n", dimension);
        exit(0);
    }
}

/*
Makes sure that the format is correct and that a newline character is after extracted input. Assume input has been
extracted and checks for newline after, if not then there's an invalid format in the user response.
No parameter.
No return value.
*/
void checkFormatError() {
    char ch;
    scanf("%c", &ch);
    if (ch != '\n') {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
}

/*
Makes sure that the unit (of temperature or distance) is given validly and not another character other than
F, C, or K for temperature and I, F, Y, M for distance. (Capitalizations are done prior to handle lowercases.)
Parameter dimension is the character representing the starting unit of temperature or distance along with its dimension (T for temp. or D for dist.).
No return value.
*/
void checkInvalidUnit(char startingUnit, char dimension) {
    if (dimension == 'T') {
        if (startingUnit != 'F' && startingUnit != 'C' && startingUnit != 'K') {
            printf("%c is not a valid temperature type. Ending program.\n", startingUnit);
            exit(0);
        }
    } else { // dimension is 'D'
        if (startingUnit != 'I' && startingUnit != 'F' && startingUnit != 'Y' && startingUnit != 'M') {
            printf("%c is not a valid distance type. Ending program.\n", startingUnit);
            exit(0);
        }
    }
}

/*
Converts from a certain unit and its value to another and prints.
dimension is T for temperature and D for distance
startingUnit is the unit to convert from of temp. (F,C,K) or distance (I,F,Y,M)
startingValue is the starting value in starting units
endingUnit is the unit to end at in same units of temp. and dist.
No return value.
*/
void convert(char dimension, char startingUnit, double startingValue, char endingUnit) {
    double endingValue = startingValue;
    if (dimension == 'T') {
        // Convert to Fahrenheit
        if (startingUnit == 'F') {
            
        } else if (startingUnit == 'C') {
            endingValue = startingValue * (9.0 / 5.0) + 32.0;
        } else { // startingUnit is 'K'
            endingValue = (endingValue - 273.15) * (9.0 / 5.0) + 32.0;
        }
        // Convert from Fahrenheit to desired unit
        if (endingUnit == 'F') {

        } else if (endingUnit == 'C') {
            endingValue = (endingValue - 32.0) * (5.0 / 9.0);
        } else { // endingUnit is 'K'
            endingValue = (endingValue - 32.0) * (5.0 / 9.0) + 273.15;
        }
    } else { // dimension is 'D'
        // Convert to inches
        if (startingUnit == 'I') {

        } else if (startingUnit == 'F') {
            endingValue = endingValue * 12.0;
        } else if (startingUnit == 'Y') {
            endingValue = endingValue * 36.0;
        } else { // startingUnit is 'M'
            endingValue = endingValue * 63360.0;
        }
        // Convert from inches to desired unit
        if (endingUnit == 'I') {

        } else if (endingUnit == 'F') {
            endingValue = endingValue / 12.0;
        } else if (endingUnit == 'Y') {
            endingValue = endingValue / 36.0;
        } else { // startingUnit is 'M'
            endingValue = endingValue / 63360.0;
        }
    }
    printf("%.2lf%c is %.2lf%c\n", startingValue, startingUnit, endingValue, endingUnit);
}