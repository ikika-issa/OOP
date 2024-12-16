//Write a class for geometric figure triangle. In the class implement methods for computing the area and perimeter of the triangle.
//Then, write a main function where you will instantiate one object of this class with values read from SI. 
//Call the methods of this object for computing area and perimeter.


#include <iostream>
#include <cmath>
using namespace std;

class Triangle{
private:
    int a, b, c;
public:
    //Constructor
    Triangle(int x, int y, int z){
        a = x;
        b = y;
        c = z;
    }
    //Destructor:
    ~Triangle(){
    }
    
    int perimetar(){
        return a + b + c;
    }
    
    float area(){
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    Triangle t(a,b,c);
    
    cout<< "Area: " << t.area() << endl;
    cout << "Perimeter: " << t.perimetar() << endl;
    
    return 0;
}
