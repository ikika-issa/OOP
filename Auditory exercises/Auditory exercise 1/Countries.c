//Write a program that will read from standard input data for countries and will print on the standard output the name of the president of the country whose capital has largest population.
//Data for country: name, president, capital and population.
//Data for city: name and population.
//Data for president: name, political party.


#include <stdio.h>

typedef struct city{
    char name[30];
    long population;
} city;

typedef struct president{
    char name[30];
    char politicalParty[30];
} president;

typedef struct Country{
    char name[30];
    president president1;
    long population;
    city capital;
} country;

void presidentOfBiggestPopulation(country con[], int n){
    int maxi = 0;
    long max = con[0].capital.population;

    for(int i = 0; i < n; i++){
        if(max < con[i].capital.population){
            max = con[i].capital.population;
            maxi = i;
        }
    }

    printf("Name of the president of the country with the largest capital is: %s\n",
           con[maxi].president1.name);
}

int main(){
    country con[20];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %s %s %d %s %d", &con[i].name, &con[i].president1.name, &con[i].president1.politicalParty,
              &con[i].population, &con[i].capital.name, &con[i].capital.population);
    }
    
    presidentOfBiggestPopulation(con, n);
    return 0;
}
