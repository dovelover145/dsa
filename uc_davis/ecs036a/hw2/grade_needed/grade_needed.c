#include <stdio.h>

int main() {
    char grade; // Stores the user's desired grade
    double wantedPercentage; // Stores the desired grade's beginning percentage
    double currentPercentage; // Stores the user's current percentage
    double finalWeightage; // Stores the weight of the final exam
    double finalExamGrade; // Stores the percentage needed on the final to get the desired grade
    
    printf("Enter the grade you want in the class: ");
    scanf(" %c", &grade);
    
    printf("Enter the percent you need to get that grade: ");
    scanf("%lf", &wantedPercentage);

    printf("Enter your current percent in the class: ");
    scanf("%lf", &currentPercentage);

    printf("Enter the weight of the final: ");
    scanf("%lf", &finalWeightage);

    finalExamGrade = (((wantedPercentage / 100) - (1 - (finalWeightage / 100)) * (currentPercentage / 100)) / (finalWeightage / 100)) * 100;

    printf("You need to get at least %.2lf%% on the final to get a %c in the class.\n", finalExamGrade, grade);
}