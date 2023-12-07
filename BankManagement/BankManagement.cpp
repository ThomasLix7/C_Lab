#include <iostream>
#include <iomanip>


using std::cout, std::cin;


void showbalance(double balance){
    cout<<"\nYour Account Balance:\t"<<std::setprecision(2)<<std::fixed<<balance<<"\n\n";
}


double deposit(){
    double amount;
    cout<<"\nEnter the amount you want to deposit:\t";
    cin>>amount;
    if(amount<0){
        cout<<"\nInvalid Deposit!\n";
        return 0;
    }
    cout<<"\n"<<amount<<"\tdeposited sucessfully!\n";
    return amount;
}


double withdraw(double balance){
    double amount;
    cout<<"\nEnter the amount you want to withdraw:\t";
    cin>>amount;
    if(amount<0){
        cout<<"\nInvalid Withdraw!\n";
        return 0;
    }
    if(amount>balance){
        cout<<"\nInsufficient  Balance!\n";
        return 0;
    }
    cout<<"\n"<<amount<<"\twithdrew sucessfully!\n";
    return amount;
}


int main(){
    double balance = 0;
    int choice = 0;
    do{
        cout<<"\n*********************\n";
        cout<<"Enter Your Choice:";
        cout<<"\n*********************\n";
        cout<<"1. Show Balance\n";
        cout<<"2. Deposit Money\n";
        cout<<"3. Withdraw Money\n";
        cout<<"4. Exit\n\n";
        cin>>choice;

        cin.clear();
        cin.ignore();

        switch(choice){
            case 1: showbalance(balance);
                    break;
            case 2: balance += deposit();
                    showbalance(balance);
                    break;
            case 3: balance -= withdraw(balance);
                    showbalance(balance);
                    break;
            case 4: cout<<"\n*********************\n";
                    cout<<"Thanks For Visiting!";
                    cout<<"\n*********************\n";
                    break;
            default: cout<<"\nPlease Select Right Number!\n";
        }
    } while(choice != 4);
}