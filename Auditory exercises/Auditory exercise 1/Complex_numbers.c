//Write a struct for representing complex numbers. 
//Then implement functions for addition, subtraction and multiplication of two complex numbers. 
//Test the functions in a main program where you read two complex numbers from standard input.


#include <stdio.h>
#include <math.h>

//2 + 3i : 2 -> real; 3i -> imaginary

typedef struct complex_number{
    float real;
    float imaginary;
} comp;

void print(comp a){
    if(a.imaginary >= 0){
        printf("%.f + %.fi\n", a.real, a.imaginary);
    }else{
        printf("%.f - %.fi\n", a.real, abs(a.imaginary));
    }
}

void add(comp a, comp b){
    comp c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    printf("a + b:\n");
    print(c);
}

void subtract(comp a, comp b){
    comp c;
    c.real = a.real - b.real;
    c.imaginary = a.imaginary - b.imaginary;
    printf("a - b:\n");
    print(c);
}

void multiply(comp *a, comp *b){
    comp c;
    c.real = a->real* b->real;
    c.imaginary = a->imaginary * b->imaginary;
    printf("a * b:\n");
    print(c);
}

int main(){
  comp a, b; //a -> first complex number, b -> second complex number
  scanf("%f %f %f %f", &a.real, &a.imaginary, &b.real, &b.imaginary);
  add(a, b);
  subtract(a, b);
  multiply(&a, &b);

  return 0;
}
