//Compare two dates and print how many days are between them
//Example: //21.11.2003 05.12.2010 -> 2569 days

#include <stdio.h>
#include <math.h>

struct date{
    int year;
    int month;
    int day;
};

typedef date date;

int compare(date d1, date d2){
    if(d1.year > d2.year) return 1;
    else if(d1.year < d2.year) return -1;
    else{
        if(d1.month > d2.month) return 1;
        else if(d1.month < d2.month) return -1;
        else{
            if(d1.day > d2.day) return 1;
            else if(d1.day < d2.day) return -1;
            else return 0;
        }
    }
}

int days(date d1, date d2){
    int days = d1.day - d2.day;
    days += (d1.month - d2.month) * 30;
    days += (d1.year - d2.year) * 365;

    return abs(days);
}

void read(date *d){
    scanf("%d.%d.%d", &d->day, &d->month, &(*d).year);
}

void print(date *d){
    printf("%02d.%02d.%d", d->day, d->month, d->year);
}

int main(){
    date d1;
    date d2;

    read(&d1);
    read(&d2);

    int result = compare(d1, d2);
    if(result == 0){
        printf("Dates are equal.");
    }
    else{
        printf("The difference between the dates is %d days.\n", days(d1,d2));
    }
}
