#include <iostream>
#include <stack>
#include <stdexcept>
#include <vector>
#include <map>
#include <string>
using namespace std;

/* This is a program by Will Duquette and Elijah Stein. This is a simple stack calculator that allows the user to input a simple arithmetic equation and see the output of the stack calculator.

Date: 5/11/2021

*/

void solve(string entry);


int main() {
  //the user is promted to enter a arithmetic expression
  cout << "Please enter the arithmetic expression that you would like to be solved" << endl;
  string entry;
  getline(cin, entry);

  solve(entry);

}

void solve(string entry){
  //This function is the program that uses the stack calculator to ouptput the solution

  //This map container is used to check the priority level of operators (line 76)
  map<char, int> priorityLevel;
  priorityLevel.emplace('+', 0);
  priorityLevel.emplace('-', 0);
  priorityLevel.emplace('*', 1);
  priorityLevel.emplace('/', 1);

  //This is the decleration of both the operand, operator stack, and letters stack
  stack<char> operatorStack;
  stack<char> operandStack;
  stack<char> letters;
  letters.push('n');
  letters.push('o');
  letters.push('p');
  letters.push('q');
  letters.push('r');
  letters.push('s');
  letters.push('t');
  letters.push('u');
  letters.push('v');
  letters.push('w');
  letters.push('x');
  letters.push('y');
  letters.push('z');

  //This is the decleration of the possible operators that could be used. This is stored in a vector
  vector<char> operators = {'*','/','+','-'};

  for (int i = 0; i < entry.size(); ++i){//this loop iterates over the size of the user entry
    if(entry.at(i) != ' ') {//checks if index is a space
      if((96 < int(entry.at(i))) && (int(entry.at(i))) < 110){//between a and m ascii values. If so, it is pushed to the operand stack
        operandStack.push(entry.at(i));
      }
      else{ //not a space or an operand, check if operator
        for(int j = 0; j < operators.size(); ++j){//This iterates through the operators vector
          if(entry.at(i) == operators.at(j)){ //is an operator
            if(operatorStack.empty() || (priorityLevel.at(entry.at(i)) > priorityLevel.at(operatorStack.top()))){//checks priority of operator
              operatorStack.push(entry.at(i));//if operator is of higher priority, it is pushed to the operator stack
            }
            else{
              //if the operator is of lower priority than what is in the stack, the program will output
              while(!operatorStack.empty()){
                cout << operatorStack.top();
                operatorStack.pop();
                char x = operandStack.top();
                operandStack.pop();
                char y = operandStack.top();
                operandStack.pop();
                char z = letters.top();
                cout << y << x << z << endl;
                operandStack.push(letters.top());
                letters.pop();
              }
              //once the operator is able to be added
              operatorStack.push(entry.at(i));
            }
          }
        }
      }
    }
  }
  while(!operatorStack.empty()){
    //this will output what is remaining in the stack after the the size of the input is iterated through. In other words this clears what is remaining in the stack

    cout << operatorStack.top();
    operatorStack.pop();
    char x = operandStack.top();
    operandStack.pop();
    char y = operandStack.top();
    operandStack.pop();
    char z = letters.top();
    cout << y << x << z << endl;
    operandStack.push(letters.top());
    letters.pop();

  }
}
