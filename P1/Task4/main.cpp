#include <iostream>
using namespace std;
//Tayla Orsmond u21467456

//4.2 
int countEven(int* arr, int size){
    if(size == 0 || sizeof(arr) == 0) return 0;//empty array
    int count = 0;
    for(int i = 0; i < size; i++){
        if(*(arr + i) % 2 == 0){//even
            count++;
        }
    }
    return count;
}
//4.3
double * maximum(double * a, int size){
    if(size == 0 || sizeof(a) == 0) return NULL;
    double * max = a;
    for(int i = 0; i < size; i++){
        if(*(a+i) > *max){
            max = &*(a+i);
        }
    }
    return max;
}

int main(){
    int a[10] = {24,6,33,4,25,9,100,12,6,7};
    int * arr = a;
    cout<<"Array: ";
    for(int i = 0; i < 10; i++){
        cout<<*(arr+i)<<", ";
    }
    cout<<*(arr+ 10)<<endl
    << "Even count: "<< countEven(arr, 10)
    <<"\n ---------- \n";

    double m[10] = {22.4,345.5,345.78,67.99,98.78,345.3,22.33,90.9,12,10.54};
    double * mArr = m;
    cout<<"Array: ";
    for(int i = 0; i < 10; i++){
        cout<<*(mArr+i)<<", ";
    }
    cout<<*(mArr+ 10)<<endl
    << "Maximum: "<< *(maximum(mArr, 10))
    <<"\n ---------- \n";
    return 0;
}