#include <iostream>
#include <string>

using std::cout, std::cin;


int main(){  
    for (int i=1; i<=10; i++){
        std:: string spaces((10-i)/2, ' ');
        std:: string stars(i, '*');
        cout<<"\n"<<spaces<<stars<<spaces;
    }
    cout<<"\n'   ||   ";
    cout<<"'\n'   ||   '";
    cout<<"\n    ||   ";
    return 0;
}