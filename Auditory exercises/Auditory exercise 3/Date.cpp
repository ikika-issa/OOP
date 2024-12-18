//Write two classes for a boy and a girl then write a third class that keeps the data for a boy and a girl.
//The classes must have: a constructor, destructor, print function. 
//The date class has to have a isMatch() function to determine if they are a match (their difference in age is less than 5).

#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

class Boy{
    char name[20];
    char surname[30];
    int age;
public:
    Boy(){
    }

    Boy(char *name, char *surname, int age){
        strcpy(this->name, name);
        strcpy(this->surname, surname);
        this->age = age;
    }

    ~Boy(){
    }

    int getAge(){
        return age;
    }

    void print(){
        cout << "Boy: " << name << " " << surname << " " << age << endl;
    }
};

class Girl{
    char name[20];
    char surname[30];
    int age;
public:
    Girl(){
    }

    Girl(char *name, char *surname, int age){
        strcpy(this->name, name);
        strcpy(this->surname, surname);
        this->age = age;
    }

    ~Girl(){
    }

    int getAge(){
        return age;
    }

    void print(){
        cout << "Girl: " << name << " " << surname << " " << age << endl;
    }
};

class Date{
    Boy boy;
    Girl girl;

public:
    Date(){
    }

    Date(const Boy boy, const Girl girl){
        this->boy = boy;
        this->girl = girl;
    }

    ~Date(){
    }

    void print(){
        cout << "Date: " << endl;
        boy.print();
        girl.print();
    }

    void isMatch(){
        if(abs(boy.getAge() - girl.getAge()) < 5){
            cout << "It's a match!" << endl;
        }else{
            cout << "It's not a match!" << endl;
        }
    }
};

int main(){
    int age;
    char name[20], surname[30];

    cout << "Boy: " << endl;
    cin >> name;
    cin >> surname;
    cin >> age;
    Boy boy (name, surname, age);

    cout << "Girl" << endl;
    cin >> name;
    cin >> surname;
    cin >> age;
    Girl girl(name, surname, age);

    Date date(boy, girl);
    date.print();
    date.isMatch();
}
