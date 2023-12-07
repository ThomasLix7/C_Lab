#include <iostream>
#include <ctime>

using std::cout, std::cin;


int main(){  
    int num;
    int guess;
    int tries;
    srand(time(NULL));
    num = rand() % 100 + 1;
    cout<<"\n***************GUESS NUMBER****************\n";
    do{
        cout<<"\nGuess The Number (1-100): ";
        cin >> guess;
        tries++;

        if (guess < num){
            cout<<"\nToo Low! Try again!\n";
        }
        else if(guess > num) {
            cout<<"\nToo High! Try again!\n";
        }
        else{
            cout<<"\nGreat! You got it in "<<tries<<" tries!\n";
        };
        
    }while(guess != num);
    cout<<"\n***************Thank You For Playing!****************";
    return 0;
}