//Define a class Team that is described with name, year of founding and the city. 
//Define a class Game that keeps information for the host and the guest (objects of class Team), goals scored by the host and goals scored by the guest.
//Define a function rematch that as arguments accepts two objects of class Game and checks if one of them is a rematch of the other. 
//A match is a rematch if the host of the first game is a guest in the second game, and vice versa. 
//If the match is a rematch, return the aggregate winner of the fixture (the one that scored more goals on aggregate).


#include <iostream>
#include <cstring>
using namespace std;

class Team{
    char name[100];
    int yearFounded;
    char city[100];

public:
    Team(const char *name = " ", const int year = 0, const char *city = ""){
        strcpy(this->name, name);
        this->yearFounded = year;
        strcpy(this->city, city);
    }

    Team(char *name, int year, char *city){
        strcpy(this->name, name);
        this->yearFounded = year;
        strcpy(this->city, city);
    }

    ~Team(){}

    char *getName(){
        return name;
    }

    void print() {
        cout << name << " " << yearFounded << endl;
    }

};

class Game{
    Team host;
    Team guest;
    int hostGoals;
    int guestGoals;

public:
    Game(const Team host = Team(), const Team guest = Team(), const int hostH = 0, const int hostG = 0){
        this->host = host;
        this->guest = guest;
        this->hostGoals = hostH;
        this->guestGoals = hostG;
    }

    ~Game(){}

    Team getHost() const{
        return host;
    }

    Team getGuest() const{
        return guest;
    }

    int getHostG(){
        return hostGoals;
    }

    int getGuestG(){
        return guestGoals;
    }

};

Team winner(Game game1, Game game2){
    if((strcmp((game1.getHost().getName()), game2.getGuest().getName()) == 0) &&
            (strcmp((game2.getHost().getName()), game1.getGuest().getName()) == 0)){
        int goalH = game1.getHostG() + game2.getGuestG();
        int goalG = game1.getGuestG() + game2.getHostG();

        if(goalG >= goalH){
            return game1.getGuest();
        }else{
            return game1.getHost();
        }
    }
    return Team();
}

int main(){
    char name[100];
    int year;
    char city[100];

    cout << "Team 1: " << endl;
    cin >> name;
    cin >> year;
    cin >> city;

    Team t1(name, year, city);

    cout << "Team 2: " << endl;
    cin >> name;
    cin >> year;
    cin >> city;

    Team t2(name, year, city);
    int hG;
    int gG;

    cout << "Team 1 goals in first game: ";
    cin >> hG;

    cout << "Team 2 goals in first game: ";
    cin >> gG;

    Game g1(t1, t2, hG, gG);

    cout << "Team 1 goals in second game: ";
    cin >> hG;

    cout << "Team 2 goals in second game: ";
    cin >> gG;

    Game g2(t2, t1, hG, gG);

    Team w = winner(g1, g2);

    w.print();
    return 0;
}
