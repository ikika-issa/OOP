//Write a class that represents a WebServer. For each web server we store:
//name (max 30 chars)
//list of web pages (dynamically allocated array of objects of class WebPage.
//For each web page we store:
//url (max 100 characters)
//contents (dynamically allocated array of characters).
//In the class WebPage implement the following functions:
//equal(WebPage wp) - for comparing two web pages by their url
//For the class WebServer implement:
//addPage(WebPage wp) - for adding new web page if it doesn’t exist in the server already. Increase the capacity for +1.
//deletePage(WebPage wp) - for deleting a web page from the server if it exists. The capacity should be decreased for -1.


#include <iostream>
#include <cstring>
using namespace std;

class WebPage{
    char url[100];
    char *contents;

public:
    WebPage(char *url ="a", char *contents ="a"){
        strcpy(this->url, url);
        this->contents = new char[strlen(contents) + 1];
        strcpy(this->contents, contents);
    }

    WebPage(const WebPage &a){
        if(this != &a){
            strcpy(this->url, a.url);
            this->contents = new char[strlen(a.contents) + 1];
            strcpy(this->contents, a.contents);
        }
    }

    ~WebPage(){
        delete [] contents;
    }

    WebPage& operator=(WebPage &wp){
        if(this != &wp){
            strcpy(this->url, wp.url);
            delete [] contents;
            this->contents = new char[strlen(wp.contents) + 1];
            strcpy(this->contents, wp.contents);
        }
        return *this;
    }

    bool equal(WebPage &wp){
        return strcmp(url, wp.url) == 0;
    }

    friend class WebServer;
};

class WebServer{
    char name[30];
    int count;
    WebPage *wp;

public:
    WebServer(char *name = " ", int count = 0, WebPage *wp = 0){
        strcpy(this->name, name);
        this->count = count;
        this->wp = new WebPage[count];
        for(int i = 0; i < count; i++){
            this->wp[i] = wp[i];
        }
    }

    WebServer(const WebServer &a){
        strcpy(this->name, a.name);
        this->count = a.count;
        this->wp = new WebPage[a.count];
        for(int i = 0; i < a.count; i++){
            this->wp[i] = a.wp[i];
        }
    }

    ~WebServer(){
        delete [] wp;
    }

    WebServer& operator=(WebServer &a){
        strcpy(this->name, a.name);
        this->count = a.count;
        delete [] wp;
        this->wp = new WebPage[a.count];
        for(int i = 0; i < a.count; i++){
            this->wp[i] = a.wp[i];
        }
        return *this;
    }

    WebServer& addPage(WebPage webPage){
        WebPage *tmp = new WebPage [count + 1];
        for(int i = 0; i < count; i++){
            tmp[i] = wp[i]; //copying all the elements to tmp
        }

        tmp[count++] = webPage;
        delete[] wp;
        wp = tmp; //move the pointer to the new array
        return *this;
    }

    WebServer& deletePage(WebPage webPage){
        int newCount = 0;
        for(int i = 0; i < count; i++){
            if(!wp[i].equal(webPage)){
                newCount++;
            }
        }

        WebPage* tmp = new WebPage[newCount];
        newCount = 0;
        for(int i = 0; i < count; i++){
            if(!wp[i].equal(webPage)){
                tmp[newCount++] = wp[i];
            }
        }
        delete [] wp;
        wp = tmp;
        count = newCount;

        return *this;
    }

    void listPages() {
        cout << "Number: " << count << endl;
        for(int i = 0; i < count; i++)
            cout << wp[i].contents << "- " << wp[i].url << endl ; // direct access of contents and url
    }
};

int main(){
    WebPage wp1("http://www.google.com", "The search engine");
    WebPage wp2("http://www.meee.com", "Meee");
    WebPage wp3("http://www.me.com", "Me");

    WebServer ws("Server");

    ws.addPage(wp1) ;
    ws.addPage(wp2);
    ws.addPage(wp3) ;

    ws.listPages();

    cout << "\nAfter delete: \n";
    ws.deletePage(wp3);
    ws.listPages();

    return 0;
}
