//Define a class for Person that is described with name, age and gender.
//Then, define a class Date that keeps data for two people.
//In this class, implement a function bool isSuccess() that should compute the success of the date. 
//The date is successful if the sum of sums of the ASCII values of the names of the people is even number. Also implement a function that will print the mates of the date in format:
//Date between:
//[Name] [Age] [Gender]
//[Name] [Age] [Gender]


#include <iostream>
#include <cstring>
using namespace std;

enum Gender{
    male,
    female,
    other
};

class Person{
private:
    char name[100];
    int age;
    Gender gender;

public:
    Person(){
    }

    Person(char *name, int age, enum Gender gender){
        strcpy(this->name, name);
        this->age = age;
        this->gender = gender;
    }

    ~Person(){
    }

    Gender getGender(){
        cout << gender;
    }

    int getAge(){
        return age;
    }

    char *getName(){
        return name;
    }

    int getNameNumber(){
        int sum = 0;
        char *n = name;

        while(*n){
            sum += *n;
            n++;
        }

        return sum;
    }
};

class Date{
    Person p1;
    Person p2;

public:
    Date(){
    }

    Date(Person& p1, Person& p2){
        this->p1 = p1;
        this->p2 = p2;
    }

    ~Date(){
    }

    void print(){
        cout << "Date between: " << endl;
        cout << p1.getName() << " " << p1.getAge() << " " << p1.getGender() << endl;
        cout << p2.getName() << " " << p2.getAge() << " " << p2.getGender() << endl;
    }

    bool isSuccess(Person per1, Person per2){
        return ((per1.getNameNumber() + per2.getNameNumber()) % 2 == 0);
    }
};

int main(){
    int age;
    char name[20];
    int gender;

    cout<<"Person 1: "<<endl;
    cin>> name;
    cin>> age;
    cin >> gender;
    Person p1(name, age, Gender(gender));

    cout<<"Person 2: "<<endl;
    cin>> name;
    cin>> age;
    cin >> gender;
    Person p2(name, age, Gender(gender));

    Date date(p1, p2);
    date.print();
    if(date.isSuccess(p1, p2)){
        cout << "The date was a success." << endl;
    }else{
        cout << "The date was not a success." << endl;
    }
    return 0;
}

