#include <iostream>


using std::cout, std::cin;


int main(){
    std::string questions[] = {"1. What year was C++ created?",
                                "2. Who created C++?",
                                "3. What is the predecessor of C++",
                                "4. Is there aliens?"};
    std::string options[][4] = {{"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
                                {"A. Guido", "B. Bjarne", "C. John", "D. Mark"},
                                {"A. C", "B. C+", "C. C#", "D. Python"},
                                {"A. Yes", "B. No", "C. Maybe", "D. What is alien"}};

    char answerKey[] = {'C', 'B', 'A', 'C'};

    int size = sizeof(questions)/sizeof(questions[0]);
    
    char answer;
    int score = 0;

    for(int i=0; i<size; i++){
        cout << "****************************\n";
        cout << questions[i] << "\n";
        cout << "****************************\n";

        for(int j=0; j<sizeof(options[i])/sizeof(options[i][0]); j++){
            cout << options[i][j] << "\n";
        }

        cin >> answer;
        answer = toupper(answer);

        if(answer == answerKey[i]){
            cout << "Correct!\n";
            score++;
        }

        else{
            cout << "Wrong!\n";
            cout << "Answer is " << answerKey[i] << "\n";   
            }

    }

    cout << "*****************************\n";
    cout << "*          RESULTS          *\n";
    cout << "*****************************\n";
    cout << "Correct Answers: " << score << "\n";
    cout << "Your Score is: " << (score/(double)size)*100 << "%";

    return 0;
}