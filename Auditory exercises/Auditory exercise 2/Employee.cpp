//Write a class that will represent an employee with following attributes:
//name
//salary
//working position (employee, manager or owner).
//Write a main function where from SI you will read data for N employees, and then print a list of employees sorted in descending order by the salary.


#include <iostream>
#include <string.h>
using namespace std;

enum position{
    employee, manager, owner
};

class Person{
private:
    char name[100];
    int salary;
    position pos;
public:
    Person(){
    }

    Person(char *name, int salary, position pos){
        strcpy(this->name, name);
        this->salary = salary;
        this->pos = pos;
    }

    ~Person(){
    }

    void setName( char const *name){
        strcpy(this->name, name);
    }

    void setSalary(int const salary){
        this->salary = salary;
    }

    void setPosition(position p){
        this->pos = p;
    }

    char *getName() {
        return name;
    }

    int getSalary(){
        return salary;
    }

    int getPosition(){
        return pos;
    }
};

void sort(Person a[], int n){
    Person p;
  
    for(int i = 0; i < n - 1; i++){
        for(int j = i; j < n; j++){
            if(a[i].getSalary() < a[j].getSalary()){
                p = a[j];
                a[j] = a[i];
                a[i] = p;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << a[i].getName() << "\t"
             << a[i].getSalary() << "\t"
             << a[i].getPosition() << endl;
    }
}

int main(){
    Person employees[100];
    int salary;
    int n, pos;
    char name[100];
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> name;
        cin >> salary;
        cin >> pos;

        employees[i].setName(name);
        employees[i].setSalary(salary);
        employees[i].setPosition((position) pos);
    }

    sort(employees, n);
    return 0;
}
