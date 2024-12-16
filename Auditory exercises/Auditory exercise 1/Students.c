//Read from standard input data for unknown number of students (not more then 100). Each row of the data is in following format:
//- first name
//- last name
//- number (format xxyzzzz)
//- four numbers (points for each problem)
//- separated with tab space.

//Write a program that will print list of students, where each row will have: last name, first name, number, and total points sorted by the number of points. 
//BTW the names should be printed with first capital letter.


#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct student{
    char firstName[15];
    char lastName[20];
    int id;
    int points;
};

void upperCaseLetter(char name[0]){
    name[0] = toupper(name[0]);

    for(int i = 1; i < strlen(name); i++){
        name[i] = tolower(name[i]);
    }
}

void sort(struct student students[], int n){
    struct student s;
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n - 1 - i; j++){ //
            if(students[j].points < students[j + 1].points){
                s = students[j];
                students[j] = students[j + 1];
                students[j+1] = s;
            }
        }
    }
}

int main(){
    struct student st[50];
    int n; //number of students

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", &st[i].firstName);
        scanf("%s", &st[i].lastName);
        scanf("%d", &st[i].id);

        st[i].points = 0;
        for(int j = 0; j < 4; j++){
            int zadachaPts;
            scanf("%d", &zadachaPts);
            st[i].points += zadachaPts;
        }

        upperCaseLetter(st[i].firstName);
        upperCaseLetter(st[i].lastName);
    }
    
    sort(st, n);
    for(int i = 0; i < n; i++){
        printf("%d. %s %s \t %d\t%d\n", i + 1, st[i].firstName, st[i].lastName, st[i].id, st[i].points);
    }

    return 0;
}
