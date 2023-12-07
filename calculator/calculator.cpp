#include <iostream>
#include <cmath>

using std::cout, std::cin;


int main(){   
    double num1;
    double num2;
    double r;
    char op;
    cout<<"********************CALCULATOR 1.0********************";
    cout<<"\n";
m: 
    cout<<"Number 1: ";
    cin>>num1;
    cout<<"Number 2: ";
    cin>>num2;
    cout<<"Choose The Operation from '+,-,*,/' : ";
    cin >> op;
    switch(op){
        case '+':
            r = num1 + num2;
            cout<<r;
            break;
        case '-':
            r = num1 - num2;
            cout<<r;
            break;
        case '*':
            r = num1 * num2;
            cout<<r;
            break;
        case '/':
            r = num1 / num2;
            cout<<r;
            break;
        default:
            cout<<"Invalid Operation!";
    }
    cout<<"\n";
    cout<<"******************************************************";
    cout<<"\n";
    goto m;
    return 0;
}