//Postfix calculator using stack class
//created by Safiul Alam

#include "Stack.h"
#include <string>
#include "Utility.h"
#include <stack>
#include <iostream>
#include <sstream>
   #include <cstring>
using namespace std;

char get_command()
{
   
    char command;
    bool waiting = true;
    cout << "Select commanand press <Enter>:";

    while (waiting) {
        cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q'|| command =='g' || command == 'a' || command == 'k' || command == 's' || command == 'x') waiting = false;


        else {
            cout << "Please enter a valid command:" << endl
                << "[?]push to stack   [=]print top" << endl
                << "[+] [-] [*] [/]   are arithmetic operations" << endl
                << "[Q]uit." << endl;
        }
    }
    return command;
}

bool do_command(char command, Stack& numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
    double sum = 0;
    char inp[100];
    double p, q,x;
    int i = 0;
    string text;
    char plus = '+';
    double num;
    switch (command) {
       

    case '?':
        cout << "Enter a real number: " << endl;
        cin >> p;
        if (numbers.push(p) == overflow)
            cout << "Warning: Stack full, lost number" << endl;
        break;

    case '=':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else
            cout << p << endl;
        break;

    case '+':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q + p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

        //   Add options for further user commands.
    case '-':
    
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q - p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '/':

        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q / p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;
  
    case '*':

        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q * p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }

    case 's':

        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            if (numbers.top(p) == underflow)
                cout << "Stack empty" << endl;
            else {
                double sum = 0;
                while (numbers.top(p) != underflow) {
                    sum += p;
                    numbers.pop();
                }
                numbers.push(sum);
            }
            break;
        }


    case 'x':

        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.top(q);
                numbers.pop();
                   
                if (numbers.push(p) == overflow or numbers.push(q)==overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;


    case 'k':

        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.size(numbers);
        }
        break;

    case 'a':

        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            if (numbers.top(p) == underflow)
                cout << "Stack empty" << endl;
            else {
                double avg = 0, sum=0;
                int count=0;
                while (numbers.top(p) != underflow) {
                    sum += p;
                    numbers.pop();
                    count++;
                }
                avg = sum / count;
                numbers.push(avg);
            }
            break;
        }


    case 'q':
        cout << "Calculation finished.\n";
        return false;
    }
    return true;
}
void  introduction() {
    cout << "*********************************************************" << endl
          <<"                  POSTFIX CALCULATOR"<<endl
         << "*********************************************************" << endl<<endl
        <<"Please enter a valid command:" << endl
        << "[?]push to stack   [=]print top" << endl
        << "[+] [-] [*] [/] [a] [s]  are arithmetic operations" << endl
        << "[Q]uit." 
<< endl;
}

bool checker(char input, string& number, Stack& numbers) {
    if (input != ' ' & input != '\n' & input != '+' & input != '=' & input != '*' & input != '/' & input != '-' & input != 'x' & input != 's' 
        & input != 'q' & input != 'a' & input != '0' & input != '1' & input != '2' & input != '3'
        & input != '4' & input != '5' & input != '6' & input != '7' & input != '8' & input != '9' & input != '.' & input != '?') {
        cout << "Invalid input. Enter ? to see the list of commands." << endl;
    }

    // If it's a digit
    if (input == '0' or input == '1' || input == '2' || input == '3' || input == '4' || input == '5' || input == '6' || input == '7' || 
        input == '8' || input == '9' || input == '.') {
        number += input;
    }
    else {
        if (number != "") {
            // If the sequence of digits ended
            numbers.push(stod(number));
            number = "";
        }
    }

    // If it's a command
    if (input == '+' || input == '=' || input == '*' || input == '/' || input == '-' || input == 'x' || input == 's' || input == 'a' ||
        input == 'k' || input == '?' || input == '%' || input == 'v') {
        do_command(input, numbers);
        number = "";
    }

    if (input == 'q') {
        return false;
    }
    return true;
}
bool get_command(Stack& numbers) {
    string number = "";
    char input;
    cout << "Enter the postfix expression and press Enter:";

    do {
        input = getchar();

        if (!checker(input, number, numbers)) {
            return false;
        }
    } while (input != '\n');
    return true;
}

int main(int argc, const char* argv[]) {
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

    Stack numbers;
   string number = "";

        // If user didn't input any arguments
        if (argc == 1) {
            introduction();
            while (get_command(numbers));
       }
        else {
            // If user used -p argument
            if (strcmp(argv[1], "-p") == 0) {
                for (int i = 2; i < argc; i++) {
                    for (int k = 0; argv[i][k] != '\0'; k++) {
                        checker(argv[i][k], number, numbers);
                    }
                    checker(' ', number, numbers);
                }
                while (get_command(numbers));
                // If user input only the mathmatical expression
            }
            else {
                for (int i = 1; i < argc; i++) {
                    for (int k = 0; argv[i][k] != '\0'; k++) {
                        checker(argv[i][k], number, numbers);
                    }
                    checker(' ', number, numbers);
                }
            }
        }
        return 0;
    }



