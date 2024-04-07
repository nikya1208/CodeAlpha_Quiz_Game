#include <iostream>
#include <vector>
#include <cstdlib> // for randomization
#include <ctime>   // for seeding random number generator
#include <map>
using namespace std;

struct Question {
    string question;
    vector<string> options;
    int correctOption;
};

class QuizGame {
private:
    vector<Question> questions;
    map<string, string> users;
    int score;

public:
    QuizGame() : score(0) {
        // Initialize questions
        questions = {
            {"What is the capital of France?", {"Paris", "London", "Berlin", "Rome"}, 1},
            {"Which planet is known as the Red Planet?", {"Mars", "Venus", "Mercury", "Jupiter"}, 1},
            {"Who wrote 'Romeo and Juliet'?", {"Shakespeare", "Hemingway", "Tolstoy", "Dostoevsky"}, 1},
        };
    }

    void displayWelcomeMessage() {
        cout<<endl;
        cout << "Welcome to the Quiz Game!\n";
        cout<<endl;
    }

    void loginOrRegister() {
        cout << "1. Log in\n2. Register\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            login();
        } else if (choice == 2) {
            registerUser();
        } else {
            cout << "Invalid choice!\n";
        }
    }

    void login() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (users.count(username) && users[username] == password) {
            cout << "Login successful!\n";
        } else {
            cout << "Invalid username or password!\n";
        }
    }

    void registerUser() {
        string username, password;
        cout << "Enter new username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        users[username] = password;
        cout<<endl;
        cout << "Registration successful!\n";
        cout<<endl;
        cout<<"Quiz Start"<<endl;
        cout<<endl;
    }

    void startQuiz() {
        score = 0;
        for (const auto& question : questions) {
            cout << question.question << "\n";
            for (size_t i = 0; i < question.options.size(); ++i) {
                cout << i + 1 << ". " << question.options[i] << "\n";
            }

            int userChoice;
            cout<<"Enter your Choice"<<endl;
            cin >> userChoice;

            if (userChoice == question.correctOption) {
                cout << "Correct!\n";
                score++;
            } else {
                cout << "Incorrect. The correct answer is: " << question.options[question.correctOption - 1] << "\n";
            }
        }
        cout << "Quiz completed! Your score: " << score << "\n";
    }

    void run() {
        displayWelcomeMessage();
        loginOrRegister();
        startQuiz();
    }
};

int main() {
    QuizGame game;
    game.run();
    return 0;
}


