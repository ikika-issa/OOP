//Write a class that defines an e-mail message. The class should implement method for showing the contents of the message on the screen.
//Then write a main function where the parameters of the message are read from SI and an object of this class is instantiated. 
//Then call the method for printing the message. The validity of the e-mail address should be checked with existence of the @ character.

#include <iostream>
#include <cstring>
using namespace std;

class Email{
    char to[100];
    char from[100];
    char subject[200];
    char body[1000];
public:
    Email(char *to, char *from, char *subject, char *body){
        strcpy(this->to, to);
        strcpy(this->from, from);
        strcpy(this->subject, subject);
        strcpy(this->body, body);
        to[99] = subject[199] = 0;
    }

    ~Email(){
    }

    void setTo(char const *n){
        strcpy(this->to, n);
    }

    void setFrom(char const *n){
        strcpy(this->from, n);
    }

    void setSubject(char const *n){
        strcpy(this->subject, n);
    }

    void setBody(char const *n){
        strcpy(this->body, n);
    }

    const char *getTo(){
        return to;
    }

    const char *getFrom(){
        return from;
    }

    const char *getSubject(){
        return subject;
    }

    const char *getBody(){
        return body;
    }

    void print(){
        cout << "To: " << to << endl;
        cout << "From: " << from << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
    }
};

bool checkEmail(char *address){
    while(*address != 0){
        if('@' == *address++){
            return true;
        }
    }
    return false;
}

int main(){
    char to[100];
    cout << "To: " << endl;
    cin >> to;
    if(checkEmail(to)){
        char from[100], subject[200], body[1000];
        cout << "From: " << endl;
        cin >> from;
        cout << "Subject: " << endl;
        cin >> subject;
        cout << "Body: " << endl;
        cin >> body;

        Email email(to, from, subject, body);

        cout << "Sent: " << endl;
        email.print();
    }else{
        cout << "Invalid email address!" << endl;
    }

    return 0;
}
