#include <iostream>
#include <random> 
#include <chrono>

using namespace std;

int main() {
    int num1, num2, userAnswer, correctAnswer;
    int score = 0;
    const int totalQuestions = 10;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(1, 20);

    cout << "=== WELCOME TO THE C++ MATH QUIZ ===" << endl;
    cout << "You will get " << totalQuestions << " questions. Good luck!\n" << endl;

    for (int i = 1; i <= totalQuestions; i++) {
        num1 = distribution(generator);
        num2 = distribution(generator);
        correctAnswer = num1 + num2;

        cout << "Question " << i << ": What is " << num1 << " + " << num2 << "?" << endl;
        cout << "Your answer: ";
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Correct!\n" << endl;
            score++;
        } else {
            cout << "Wrong! The correct answer was " << correctAnswer << ".\n" << endl;
        }
    }

    cout << "=== QUIZ OVER ===" << endl;
    cout << "Your final score: " << score << " out of " << totalQuestions << endl;
    
    if (score == totalQuestions) {
        cout << "Perfect score! Outstanding job!" << endl;
    } else if (score >= 7) {
        cout << "Great job! You passed." << endl;
    } else {
        cout << "Good effort! Keep practicing." << endl;
    }

    return 0;
}
