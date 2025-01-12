#include <stdio.h>
#include <stdlib.h>

void Time();
void Length();
void Temperature();
void Mass();
void printHistory();
FILE *history;

int main(){
    int selection;
    FILE *logo;
    char logoString[100];
    logo = fopen("logoArt.txt", "r+");
    if(logo == NULL){
        printf("Error opening logo file. \n");
        exit(1);
    }
    while(fgets(logoString, sizeof(logoString), logo) != NULL){
        printf("%s", logoString);
    }
    printf("\n");
    do{
        printf("\n************************************************");
        printf("\n\t  The Universal Unit Converter \n");
        printf("************************************************\n");
        printf("[1] Time \n");
        printf("[2] Length \n");
        printf("[3] Temperature \n");
        printf("[4] Mass \n");
        printf("[5] Print Conversion History \n");
        printf("[6] Exit \n");
        printf("************************************************\n");
        printf("Please select an option: ");
        scanf("%d", &selection);
        printf("************************************************\n");
        printf("\n");
        switch(selection){
        case 1: 
            Time();
            break;
        case 2:
            Length();
            break;
        case 3:
            Temperature();
            break;
        case 4:
            Mass();
            break;
        case 5:
            printHistory();
            break;
        case 6:
            printf("************************************************\n");
            printf("You have exited the application. All conversions have been saved in the history.txt file. \n");
            printf("************************************************\n");
            break;
        default: 
            printf("************************************************\n");
            printf("Please choose one of the listed choices. \n");
            printf("************************************************\n");
            break;
        }
    }while(selection != 6);
    fclose(logo);
    return 0;
}

void printHistory(){
    history = fopen("history.txt", "a+");
    if(history == NULL){
        printf("Error opening history file. \n");
        exit(1);
    }
    char hist[100];
    int isEmpty = 1;
    printf("\n************************************************");
    printf("\n\t       Conversion History \n");
    printf("************************************************\n");
    while(fgets(hist, sizeof(hist), history) != NULL){
        printf("%s", hist);
        isEmpty = 0;
    }
    if(isEmpty){
        printf("There is no Conversion History. \n");
    }
    printf("************************************************\n");
    fclose(history);
}

void Time(){
    history = fopen("history.txt", "a+");
    if(history == NULL){
        printf("Error opening history file. \n");
        exit(1);
    }
    float unit1, unit2, num1, num2, repeat;
    printf("************************************************\n");
    printf("[1] Seconds \n"); 
    printf("[2] Minutes \n");
    printf("[3] Hours \n"); 
    printf("[4] Days \n");
    do{
        printf("************************************************\n");
        printf("Please enter the value of the number you are converting: ");
        scanf("%f", &num1);
        printf("Please enter the unit you wish to convert from: ");
        scanf("%f", &unit1);
        printf("Please enter the unit you wish to convert to: ");
        scanf("%f", &unit2);
        printf("************************************************\n");
        if(unit1 > 4 || unit1 < 1 || unit2 > 4 || unit2 < 1 || unit1 == unit2){
            repeat = 1;
            printf("\n************************************************\n");
            printf("Please choose one of the listed choices. \n");
            printf("************************************************\n\n");
        } else{
            repeat = 0;
        }
    }while(repeat == 1);
    printf("\n************************************************\n");
    if(unit1 == 1 && unit2 == 2){
        num2 = num1/60;
        printf("%.2f Second(s) is %.2f Minute(s) \n", num1, num2);
        fprintf(history, "%.2f Second(s) is %.2f Minute(s) \n", num1, num2);
    }else if(unit1 == 1 && unit2 == 3){
        num2 = num1/3600;
        printf("%.2f Second(s) is %.2f Hour(s) \n", num1, num2);
        fprintf(history, "%.2f Second(s) is %.2f Hour(s) \n", num1, num2);
    }else if(unit1 == 1 && unit2 == 4){
        num2 = num1/86400;
        printf("%.2f Second(s) is %.2f Day(s) \n", num1, num2);
        fprintf(history, "%.2f Second(s) is %.2f Day(s) \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 1){
        num2 = num1*60;
        printf("%.2f Minute(s) is %.2f Second(s) \n", num1, num2);
        fprintf(history, "%.2f Minute(s) is %.2f Second(s) \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 3){
        num2 = num1/60;
        printf("%.2f Minute(s) is %.2f Hour(s) \n", num1, num2);
        fprintf(history, "%.2f Minute(s) is %.2f Hour(s) \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 4){
        num2 = num1/1440;
        printf("%.2f Minute(s) is %.2f Day(s) \n", num1, num2);
        fprintf(history, "%.2f Minute(s) is %.2f Day(s) \n", num1, num2);
    }else if(unit1 == 3 && unit2 == 1){
        num2 = num1*3600;
        printf("%.2f Hour(s) is %.2f Second(s) \n", num1, num2);
        fprintf(history, "%.2f Hour(s) is %.2f Second(s) \n", num1, num2);
    }else if(unit1 == 3 && unit2 == 2){
        num2 = num1*60;
        printf("%.2f Hour(s) is %.2f Minute(s) \n", num1, num2);
        fprintf(history, "%.2f Hour(s) is %.2f Minute(s) \n", num1, num2);
    }else if(unit1 == 3 && unit2 == 4){
        num2 = num1/24;
        printf("%.2f Hour(s) is %.2f Day(s) \n", num1, num2);
        fprintf(history, "%.2f Hour(s) is %.2f Day(s) \n", num1, num2);
    }else if(unit1 == 4 && unit2 == 1){
        num2 = num1*86400;
        printf("%.2f Day(s) is %.2f Second(s) \n", num1, num2);
        fprintf(history, "%.2f Day(s) is %.2f Second(s) \n", num1, num2);
    }else if(unit1 == 4 && unit2 == 2){
        num2 = num1*1440;
        printf("%.2f Day(s) is %.2f Minute(s) \n", num1, num2);
        fprintf(history, "%.2f Day(s) is %.2f Minute(s) \n", num1, num2);
    }else if(unit1 == 4 && unit2 == 3){
        num2 = num1*24;
        printf("%.2f Day(s) is %.2f Hour(s) \n", num1, num2);
        fprintf(history, "%.2f Day(s) is %.2f Hour(s) \n", num1, num2);
    }
    printf("************************************************\n");
    fclose(history);
}

void Length(){
    history = fopen("history.txt", "a+");
    if(history == NULL){
        printf("Error opening history file. \n");
        exit(1);
    }
    float unit1, unit2, num1, num2, repeat;
    printf("************************************************\n");
    printf("[1] Centimeters \n"); 
    printf("[2] Meters \n");
    printf("[3] Kilometers \n"); 
    printf("[4] Inches \n"); 
    printf("[5] Feet \n"); 
    printf("[6] Yards \n");
    printf("[7] Miles \n");
    do{
        printf("************************************************\n");
        printf("Please enter the value of the number you are converting: ");
        scanf("%f", &num1);
        printf("Please enter the unit you wish to convert from: ");
        scanf("%f", &unit1);
        printf("Please enter the unit you wish to convert to: ");
        scanf("%f", &unit2);
        printf("************************************************\n");
        if(unit1 > 7 || unit1 < 1 || unit2 > 7 || unit2 < 1 || unit1 == unit2){
            repeat = 1;
            printf("\n************************************************\n");
            printf("Please choose one of the listed choices. \n");
            printf("************************************************\n\n");
        } else{
            repeat = 0;
        }
    }while(repeat == 1);
    printf("\n************************************************\n");
    if(unit1 == 1 && unit2 == 2){
        num2 = num1/100;
        printf("%.2f Centimeter(s) is %.2f Meter(s) \n", num1, num2);
        fprintf(history, "%.2f Centimeter(s) is %.2f Meter(s) \n", num1, num2);
    }else if(unit1 == 1 && unit2 == 3){
        num2 = num1/100000;
        printf("%.2f Centimeter(s) is %.2f Kilometer(s) \n", num1, num2);
        fprintf(history, "%.2f Centimeter(s) is %.2f Kilometer(s) \n", num1, num2);
    }else if(unit1 == 1 && unit2 == 4){
        num2 = num1/2.54;
        printf("%.2f Centimeter(s) is %.2f Inch(es) \n", num1, num2);
        fprintf(history, "%.2f Centimeter(s) is %.2f Inch(es) \n", num1, num2);
    }else if(unit1 == 1 && unit2 == 5){
        num2 = num1/30.48;
        printf("%.2f Centimeter(s) is %.2f Foot/Feet \n", num1, num2);
        fprintf(history, "%.2f Centimeter(s) is %.2f Foot/Feet \n", num1, num2);
    }else if(unit1 == 1 && unit2 == 6){
        num2 = num1/91.44;
        printf("%.2f Centimeter(s) is %.2f Yard(s) \n", num1, num2);
        fprintf(history, "%.2f Centimeter(s) is %.2f Yard(s) \n", num1, num2);
    }else if(unit1 == 1 && unit2 == 7){
        num2 = num1/160900;
        printf("%.2f Centimeter(s) is %.2f Mile(s) \n", num1, num2);
        fprintf(history, "%.2f Centimeter(s) is %.2f Mile(s) \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 1){
        num2 = num1*100;
        printf("%.2f Meter(s) is %.2f Centimeter(s) \n", num1, num2);
        fprintf(history, "%.2f Meter(s) is %.2f Centimeter(s) \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 3){
        num2 = num1/1000;
        printf("%.2f Meter(s) is %.2f Kilometer(s) \n", num1, num2);
        fprintf(history, "%.2f Meter(s) is %.2f Kilometer(s) \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 4){
        num2 = num1*39.37;
        printf("%.2f Meter(s) is %.2f Inch(es) \n", num1, num2);
        fprintf(history, "%.2f Meter(s) is %.2f Inch(es) \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 5){
        num2 = num1*3.281;
        printf("%.2f Meter(s) is %.2f Foot/Feet \n", num1, num2);
        fprintf(history, "%.2f Meter(s) is %.2f Foot/Feet \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 6){
        num2 = num1*1.094;
        printf("%.2f Meter(s) is %.2f Yard(s) \n", num1, num2);
        fprintf(history, "%.2f Meter(s) is %.2f Yard(s) \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 7){
        num2 = num1/1609;
        printf("%.2f Meter(s) is %.2f Mile(s) \n", num1, num2);
        fprintf(history, "%.2f Meter(s) is %.2f Mile(s) \n", num1, num2);
    }else if(unit1 == 3 && unit2 == 1){
        num2 = num1*100000;
        printf("%.2f Kilometer(s) is %.2f Centimeter(s) \n", num1, num2);
        fprintf(history, "%.2f Kilometer(s) is %.2f Centimeter(s) \n", num1, num2);
    }else if(unit1 == 3 && unit2 == 2){
        num2 = num1*1000;
        printf("%.2f Kilometer(s) is %.2f Meter(s) \n", num1, num2);
        fprintf(history, "%.2f Kilometer(s) is %.2f Meter(s) \n", num1, num2);
    }else if(unit1 == 3 && unit2 == 4){
        num2 = num1*39370;
        printf("%.2f Kilometer(s) is %.2f Inch(es) \n", num1, num2);
        fprintf(history, "%.2f Kilometer(s) is %.2f Inch(es) \n", num1, num2);
    }else if(unit1 == 3 && unit2 == 5){
        num2 = num1*3281;
        printf("%.2f Kilometer(s) is %.2f Foot/Feet \n", num1, num2);
        fprintf(history, "%.2f Kilometer(s) is %.2f Foot/Feet \n", num1, num2);
    }else if(unit1 == 3 && unit2 == 6){
        num2 = num1*1094;
        printf("%.2f Kilometer(s) is %.2f Yard(s) \n", num1, num2);
        fprintf(history, "%.2f Kilometer(s) is %.2f Yard(s) \n", num1, num2);
    }else if(unit1 == 3 && unit2 == 7){
        num2 = num1/1.609;
        printf("%.2f Kilometer(s) is %.2f Mile(s) \n", num1, num2);
        fprintf(history, "%.2f Kilometer(s) is %.2f Mile(s) \n", num1, num2);
    }else if(unit1 == 4 && unit2 == 1){
        num2 = num1*2.54;
        printf("%.2f Inch(es) is %.2f Centimeter(s) \n", num1, num2);
        fprintf(history, "%.2f Inch(es) is %.2f Centimeter(s) \n", num1, num2);
    }else if(unit1 == 4 && unit2 == 2){
        num2 = num1/39.37;
        printf("%.2f Inch(es) is %.2f Meter(s) \n", num1, num2);
        fprintf(history, "%.2f Inch(es) is %.2f Meter(s) \n", num1, num2);
    }else if(unit1 == 4 && unit2 == 3){
        num2 = num1/39370;
        printf("%.2f Inch(es) is %.2f Kilometer(s) \n", num1, num2);
        fprintf(history, "%.2f Inch(es) is %.2f Kilometer(s) \n", num1, num2);
    }else if(unit1 == 4 && unit2 == 5){
        num2 = num1/12;
        printf("%.2f Inch(es) is %.2f Foot/Feet \n", num1, num2);
        fprintf(history, "%.2f Inch(es) is %.2f Foot/Feet \n", num1, num2);
    }else if(unit1 == 4 && unit2 == 6){
        num2 = num1/36;
        printf("%.2f Inch(es) is %.2f Yard(s) \n", num1, num2);
        fprintf(history, "%.2f Inch(es) is %.2f Yard(s) \n", num1, num2);
    }else if(unit1 == 4 && unit2 == 7){
        num2 = num1/63360;
        printf("%.2f Inch(es) is %.2f Mile(s) \n", num1, num2);
        fprintf(history, "%.2f Inch(es) is %.2f Mile(s) \n", num1, num2);
    }else if(unit1 == 5 && unit2 == 1){
        num2 = num1*30.48;
        printf("%.2f Foot/Feet is %.2f Centimeter(s) \n", num1, num2);
        fprintf(history, "%.2f Foot/Feet is %.2f Centimeter(s) \n", num1, num2);
    }else if(unit1 == 5 && unit2 == 2){
        num2 = num1/3.281;
        printf("%.2f Foot/Feet is %.2f Meter(s) \n", num1, num2);
        fprintf(history, "%.2f Foot/Feet is %.2f Meter(s) \n", num1, num2);
    }else if(unit1 == 5 && unit2 == 3){
        num2 = num1/3281;
        printf("%.2f Foot/Feet is %.2f Kilometer(s) \n", num1, num2);
        fprintf(history, "%.2f Foot/Feet is %.2f Kilometer(s) \n", num1, num2);
    }else if(unit1 == 5 && unit2 == 4){
        num2 = num1*12;
        printf("%.2f Foot/Feet is %.2f Inch(es) \n", num1, num2);
        fprintf(history, "%.2f Foot/Feet is %.2f Inch(es) \n", num1, num2);
    }else if(unit1 == 5 && unit2 == 6){
        num2 = num1/3;
        printf("%.2f Foot/Feet is %.2f Yard(s) \n", num1, num2);
        fprintf(history, "%.2f Foot/Feet is %.2f Yard(s) \n", num1, num2);
    }else if(unit1 == 5 && unit2 == 7){
        num2 = num1/5280;
        printf("%.2f Foot/Feet is %.2f Mile(s) \n", num1, num2);
        fprintf(history, "%.2f Foot/Feet is %.2f Mile(s) \n", num1, num2);
    }else if(unit1 == 6 && unit2 == 1){
        num2 = num1*91.44;
        printf("%.2f Yard(s) is %.2f Centimeter(s) \n", num1, num2);
        fprintf(history, "%.2f Yard(s) is %.2f Centimeter(s) \n", num1, num2);
    }else if(unit1 == 6 && unit2 == 2){
        num2 = num1/1.094;
        printf("%.2f Yard(s) is %.2f Meter(s) \n", num1, num2);
        fprintf(history, "%.2f Yard(s) is %.2f Meter(s) \n", num1, num2);
    }else if(unit1 == 6 && unit2 == 3){
        num2 = num1/1094;
        printf("%.2f Yard(s) is %.2f Kilometer(s) \n", num1, num2);
        fprintf(history, "%.2f Yard(s) is %.2f Kilometer(s) \n", num1, num2);
    }else if(unit1 == 6 && unit2 == 4){
        num2 = num1*36;
        printf("%.2f Yard(s) is %.2f Inch(es) \n", num1, num2);
        fprintf(history, "%.2f Yard(s) is %.2f Inch(es) \n", num1, num2);
    }else if(unit1 == 6 && unit2 == 5){
        num2 = num1*3;
        printf("%.2f Yard(s) is %.2f Foot/Feet \n", num1, num2);
        fprintf(history, "%.2f Yard(s) is %.2f Foot/Feet \n", num1, num2);
    }else if(unit1 == 6 && unit2 == 7){
        num2 = num1/1760;
        printf("%.2f Yard(s) is %.2f Mile(s) \n", num1, num2);
        fprintf(history, "%.2f Yard(s) is %.2f Mile(s) \n", num1, num2);
    }else if(unit1 == 7 && unit2 == 1){
        num2 = num1*160900;
        printf("%.2f Mile(s) is %.2f Centimeter(s) \n", num1, num2);
        fprintf(history, "%.2f Mile(s) is %.2f Centimeter(s) \n", num1, num2);
    }else if(unit1 == 7 && unit2 == 2){
        num2 = num1*1609;
        printf("%.2f Mile(s) is %.2f Meter(s) \n", num1, num2);
        fprintf(history, "%.2f Mile(s) is %.2f Meter(s) \n", num1, num2);
    }else if(unit1 == 7 && unit2 == 3){
        num2 = num1*1.609;
        printf("%.2f Mile(s) is %.2f Kilometer(s) \n", num1, num2);
        fprintf(history, "%.2f Mile(s) is %.2f Kilometer(s) \n", num1, num2);
    }else if(unit1 == 7 && unit2 == 4){
        num2 = num1*63360;
        printf("%.2f Mile(s) is %.2f Inch(es) \n", num1, num2);
        fprintf(history, "%.2f Mile(s) is %.2f Inch(es) \n", num1, num2);
    }else if(unit1 == 7 && unit2 == 5){
        num2 = num1*5280;
        printf("%.2f Mile(s) is %.2f Foot/Feet \n", num1, num2);
        fprintf(history, "%.2f Mile(s) is %.2f Foot/Feet \n", num1, num2);
    }else if(unit1 == 7 && unit2 == 6){
        num2 = num1*1760;
        printf("%.2f Mile(s) is %.2f Yard(s) \n", num1, num2);
        fprintf(history, "%.2f Mile(s) is %.2f Yard(s) \n", num1, num2);
    }
    printf("************************************************\n");
    fclose(history);
}

void Temperature(){
    history = fopen("history.txt", "a+");
    if(history == NULL){
        printf("Error opening history file. \n");
        exit(1);
    }
    float unit1, unit2, num1, num2, repeat;
    printf("************************************************\n");
    printf("[1] Celsius \n"); 
    printf("[2] Fahrenheit \n"); 
    do{
        printf("************************************************\n");
        printf("Please enter the value of the number you are converting: ");
        scanf("%f", &num1);
        printf("Please enter the unit you wish to convert from: ");
        scanf("%f", &unit1);
        printf("Please enter the unit you wish to convert to: ");
        scanf("%f", &unit2);
        printf("************************************************\n");
        if(unit1 > 2 || unit1 < 1 || unit2 > 2 || unit2 < 1 || unit1 == unit2){
            repeat = 1;
            printf("\n************************************************\n");
            printf("Please choose one of the listed choices. \n");
            printf("************************************************\n\n");
        } else{
            repeat = 0;
        }
    }while(repeat == 1);
    printf("\n************************************************\n");
    if(unit1 == 1 && unit2 == 2){
        num2 = ((num1*9)/5) + 32;
        printf("%.2f degree(s) Celsius is %.2f degree(s) Fahrenheit \n", num1, num2);
        fprintf(history, "%.2f degree(s) Celsius is %.2f degree(s) Fahrenheit \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 1){
        num2 = ((num1 - 32)*5)/9;
        printf("%.2f degree(s) Fahrenheit is %.2f degree(s) Celsius \n", num1, num2);
        fprintf(history, "%.2f degree(s) Fahrenheit is %.2f degree(s) Celsius \n", num1, num2);
    }
    printf("************************************************\n");
    fclose(history);
}

void Mass(){
    history = fopen("history.txt", "a+");
    if(history == NULL){
        printf("Error opening history file. \n");
        exit(1);
    }
    float unit1, unit2, num1, num2, repeat;
    printf("************************************************\n");
    printf("[1] Pounds \n"); 
    printf("[2] Kilograms \n");
    do{
        printf("************************************************\n");
        printf("Please enter the value of the number you are converting: ");
        scanf("%f", &num1);
        printf("Please enter the unit you wish to convert from: ");
        scanf("%f", &unit1);
        printf("Please enter the unit you wish to convert to: ");
        scanf("%f", &unit2);
        printf("************************************************\n");
        if(unit1 > 2 || unit1 < 1 || unit2 > 2 || unit2 < 1 || unit1 == unit2){
            repeat = 1;
            printf("\n************************************************\n");
            printf("Please choose one of the listed choices. \n");
            printf("************************************************\n\n");
        } else{
            repeat = 0;
        }
    }while(repeat == 1);
    printf("\n************************************************\n");
    if(unit1 == 1 && unit2 == 2){
        num2 = num1/2.205;
        printf("%.2f Pound(s) is %.2f Kilogram(s) \n", num1, num2);
        fprintf(history, "%.2f Pound(s) is %.2f Kilogram(s) \n", num1, num2);
    }else if(unit1 == 2 && unit2 == 1){
        num2 = num1*2.205;
        printf("%.2f Kilogram(s) is %.2f Pound(s) \n", num1, num2);
        fprintf(history, "%.2f Kilogram(s) is %.2f Pound(s) \n", num1, num2);
    }
    printf("************************************************\n");
    fclose(history);
}