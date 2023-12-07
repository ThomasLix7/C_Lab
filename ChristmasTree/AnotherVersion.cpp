#include <iostream>
#include <string>

using std::cout, std::cin;


int main(){  
    for (int i=0; i<=11; i+=2){
        std:: string spaces((10-i)/2, ' ');
        std:: string stars(i+1, '*');
        cout<<"\n"<<spaces<<stars<<spaces;
    }
    cout<<"\n'   | |   ";
    cout<<"'\n'   | |   '";
    return 0;
}