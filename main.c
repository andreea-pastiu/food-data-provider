#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_TYPE_NAME 10
#define MAX_SPECIFFIC_FOOD_NAME 20
#define MAX_DRINK_NAME 20
#define MAX_LINE 10
void readItem(char * specifficFood);

int main() {
    int noOfFoodTypes;
    printf("Please input number of food types\n");
    scanf("%d",&noOfFoodTypes);
    printf("Please input food types (each on a new line, may contain spaces)\n");
    char ** foodTypes;
    foodTypes = (char**)malloc(noOfFoodTypes * sizeof(char*));
    getchar();
    for(int i=0; i < noOfFoodTypes; i++) {
        foodTypes[i] = (char*)malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
        gets(foodTypes[i]);
    }

    int * noOfSpecificFood = (int*)malloc(noOfFoodTypes * sizeof(int));
    char *** specifficFood = (char***)malloc(noOfFoodTypes * sizeof(char**));
    double ** specifficFoodPrices = (double**)malloc(noOfFoodTypes * sizeof(double*));
    for(int i=0; i < noOfFoodTypes; i++) {
        printf("\nPlease input no of speciffic foods for food \"%s\"\n", foodTypes[i]);
        scanf("%d",&noOfSpecificFood[i]);
        getchar();

        specifficFood[i] = (char**)malloc(noOfSpecificFood[i] * sizeof(char*));
        specifficFoodPrices[i] = (double*)malloc(noOfSpecificFood[i] * sizeof(double));

        printf("Please input \"%s\" speciffic foods &prices: each line in the format <speciffic food> (price):\n", foodTypes[i]);
        for(int j=0; j < noOfSpecificFood[i]; j++){
            specifficFood[i][j] = (char*)malloc(MAX_SPECIFFIC_FOOD_NAME * sizeof(char));
            readItem(specifficFood[i][j]);
            char line[MAX_LINE];
            gets(line);
            sscanf(line, "%lf", &specifficFoodPrices[i][j]);
        }
    }

    int noOfDrinks;
    char ** drinks = (char***)malloc(noOfFoodTypes * sizeof(char*));
    int * drinkPrices = (int*)malloc(noOfFoodTypes * sizeof(int));
    printf("\nPlease input no of drinks\n");
    scanf("%d", &noOfDrinks);
    getchar();
    printf("Please input the drinks: each line in the format <drink> (price):\n");
    for (int i = 0; i < noOfDrinks; i++){
        drinks[i] = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
        readItem(drinks[i]);
        char line[MAX_LINE];
        gets(line);
        sscanf(line, "%d", &drinkPrices[i]);
    }

    printf("\nThe food data is:\n");
    for(int i=0; i < noOfFoodTypes; i++) {
        printf("%s: ", foodTypes[i]);
        for(int j=0; j < noOfSpecificFood[i]; j++) {
            printf("(%s- %.2lf) ", specifficFood[i][j], specifficFoodPrices[i][j]);
        }
        printf("\n");
    }
    printf("The drinks data is:\n");
    printf("drinks: ");
    for(int i=0; i < noOfDrinks; i++){
        printf("%s", drinks[i]);
        if(i < noOfDrinks -1)
            printf(", ");
        else
            printf("\n");
    }
    printf("prices: ");
    for(int i=0; i < noOfDrinks; i++){
        printf("%d", drinkPrices[i]);
        if(i < noOfDrinks -1)
            printf(", ");
    }

    for(int i=0; i < noOfFoodTypes; i++) {
        for(int j=0; j < noOfSpecificFood; j++) {
            free(specifficFood[i][j]);
        }
        free(specifficFood[i]);
        free(specifficFoodPrices[i]);
        free(foodTypes[i]);
    }

    for(int i=0; i < noOfDrinks; i++){
        free(drinks[i]);
    }
    free(drinks);
    free(drinkPrices);
    free(specifficFood);
    free(specifficFoodPrices);
    free(foodTypes);
    free(noOfSpecificFood);

    return 0;
}

void readItem(char * item) {
    char c = getchar();
    int i=0;
    while(c!='(') {
        item[i] = c;
        c = getchar();
        i++;
    }
    item[i] = '\0';
}