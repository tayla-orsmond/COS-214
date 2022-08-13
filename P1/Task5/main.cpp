#include <iostream>
using namespace std;
//Tayla Orsmond u21467456

//5.1
bool increasing = false;
void recursive(int input, const int init){
    if(input == init && increasing){
        cout<<input<<endl;
        increasing = false;
        return;
    }
    cout<<input<<", ";
    if(input <=0 || increasing){
        increasing = true;
        return recursive(input + 7, init);
    }
    else{
        return recursive(input -7, init);
    }
    return;
}

//5.2
int A(int m, int n){
    if(m == 0){
        return n+1;
    }
    else if(m > 0 && n == 0){
        return A(m-1, 1);
    }
    else if(m > 0 && n > 0){
        return A(m-1, A(m, n-1));
    }
    return 1;
}
//main
int main(){
    cout<<"--- Task 5.1 ---\n";
    recursive(20,20);
    recursive(14,14);
    cout<<"\n--- Task 5.2 ---\n"
    <<"The value of A(1,2) is "<<A(1,2)<<endl;
    return 0;
}