# Styling guide for Arduino!
## Why comment your Arduino code?
When you do coding in the Arduino IDE, you should comment your code because it helps you understand what your code does in human language. In brief, you comment in Arduino with 
```cpp
//This is an example comment.
```
## What is an example of a commonly accepted commenting style?
The best way to do comment styling in Arduino IDE would be to use the Doxygen commenting style where you document your functions by telling code users several different important things about your functions. These are the components of the Doxygen commenting style below!
- `@brief`: This should be a short description in one or two sentences about what your function does in terms of human language. 
- `@param`: This is a short explanation of what your function inputs are. 
- `@return`: This is a short explanation of what your function returns. Does your function return a single variable, multiple variables, or the same variables as your function inputs?
- `@details`: This briefly describes the complicated language that you may include when describing your function in `@brief`. 

Here is an example of the Doxygen commenting style: 
```cpp
// Code documentation Using Doxygen Style Comments

#include <iostream>
using namespace std;
/**
 * @brief Calculates the factorial of a number.
 *
 * This function computes the factorial of a given
 * non-negative integer. It uses a recursive approach to
 * calculate the factorial.
 *
 * @param n The number for which the factorial is to be
 * calculated.
 *
 * @return The factorial of the number.
 *
 * @details
 * The factorial of a non-negative integer n is the product
 * of all positive integers less than or equal to n. For
 * example, the factorial of 5 is 5 * 4 * 3 * 2 * 1 = 120.
 * This function uses recursion to compute the factorial.
 *
 *  @example example.cpp
 *
 * @usage
 * int result = factorial(5); // result will be 120
 */
int factorial(int n)
{
    // Base case: factorial of 0 is 1
    if (n == 0)
        return 1;

    // Recursive case: n * factorial(n - 1)
    return n * factorial(n - 1);
}

int main()
{
    int n = 5;
    cout << "Factorial of " << n << " is: " << factorial(n)
         << endl;
    return 0;
}
```
Full website at https://www.geeksforgeeks.org/cpp/doxygen-cpp-documentation/. 
# Some important rules to follow while coding and commenting. 
- Do not try to comment in terms of entire paragraphs. Try to brief in terms of one or two short sentences at max. 
- When creating a function, it should be reusable code that clearly is designed to output one or more variables that have meaning to your project. Do not try to you know create functions that only have one or two lines of code. 
- In your code, declare all your variables that you intend to use in the void setup() function. This is an Arduino specific thing. 
- Also, it is best if you declare your variables with a value that works with a certain variable type rather than leaving those values null. 
- Conventionally, it is best to organize certain code into functions above your main two functions in Arduino as it prevents you from having a hard to read loop function. 
- Always try to return a specific number that you can understand with your documentation for certain error states in your functions. 
- Also try to print the meaning of your error if possible with print() to specify what error you get with wrong situations. 
- Lastly, always try to indent your code when you have to use brackets in your Arduino code as it improves readability of nested code. 
- Do not try to nest your code three brackets or more.
- What this means is that for Arduino, you need to use {} brackets to enclose certain conditional statements like if statements and for loops that you can add in the main Arduino loop. 
