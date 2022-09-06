/* ********************************************************************** *\
    Name: Simple Calculator 
    Description: Simple calculator for Add, Substract, Multiply, Divide
    Author: Andrew Hayden
\* ********************************************************************** */
#include <iostream>
#include <string>

using namespace std;

enum operators {none, add, subtract, multiply, divide};

string OperatorText(operators operand){
    string result = "";
    switch(operand){
        case none:
            result = "";
            break;
        case add:
            result = "addition";
            break;
        case subtract:
            result = "subtraction";
            break;
        case multiply:
            result = "multiplication";
            break;
        case divide:
            result = "division";
            break;
    }
    return result;
}

int main()
{
    cout << "Welcome to My Calculator" << endl;
    cout << "Enter your numbers and operators, enter a blank option when finished to calculate" << endl;

    string buff;
    float result=0.0f;
    operators operand;
    do{
        getline(cin, buff);

        if(buff == ""){
            break;
        }else if(buff == "+"){
            operand = add;
        }else if(buff == "-"){
            operand = subtract;
        }else if(buff == "*"){
            operand = multiply;
        }else if(buff == "/"){
            operand = divide;
        }else{
            if(operand != none){
                switch(operand){
                    case add:
                        result += stof(buff);
                        break;
                    case subtract:
                        result -= stof(buff);
                        break;
                    case multiply:
                        result *= stof(buff);
                        break;
                    case divide:
                        if(stoi(buff) == 0){
                            cout << "cannot divide by 0, skipping step, resetting operand" << endl;
                        }else{
                            result /= stof(buff);
                        }
                        break;
                    default:
                        result = stof(buff);
                        break;
                }

                operand = none;
            }
        }
        cout << "temp result:" << result << endl;
        cout << "stored operand: " << OperatorText(operand) << endl;
    }while(buff != "\n");
    
    cout << "Final Result: " << result << endl;

    return 0;
}