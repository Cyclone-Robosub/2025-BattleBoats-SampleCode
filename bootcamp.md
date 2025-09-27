# Programming Bootcamp

This guide was written by William Barber. If you have any questions, reach out to me!

## Introduction and Prerequisites
For this guide to be most helpful, it will be beneficial to have a basic understanding of the purpose of a computer program and access to a development environment to test these programs. However, the guide will have a brief overview of the basics of programming and computing. Feel free to skip ahead to areas that you feel will be most useful.

This guide will teach introductory program through the C programming language. In Cyclone Robosub, you'll be working primarily in C, C++, and Python. For Battle Boats, you'll be working in either C or C++. 

## Basics
### What is a program?
A program is a series of steps that your computer completes in order to solve a problem or complete a task. For example, you might write a program to:
- Calculate the area of a circle
- Pick a random card from a deck
- Control an automated sprinkler system

or anything else that a computer can do.

One key thing to remember when programming is that your computer will only do what you tell it to, and in the order that you tell it to. It is not smart, and will not infer anything that you do not write explicitly.

Programs are written in English text, and then transformed into binary (1s and 0s) that the computer can read. This is a process known as "compilation". Some languages, like C, compile the whole program at once. Other languages, like Python, compile the code bit-by-bit as the program runs. These languages are known as interpreted languages. For now, we'll just focus on C, a compiled language.

C programs are written (in English) in files that use the ".c" file extension, like "main.c". Remember, you cannot run ".c" files! Compilation is what turns the source code file (".c") into an executable file that can be run (executed) on your computer. In Windows, these end in ".exe". On MacOS or Linux, there isn't a specific file extension. *Remember that if you change your source code, you need to recompile the code for the change to take effect!*

### Your First Program
Let's start with writing the traditional first program in any programming language: a "Hello, World!" program!

1. Make an empty file text on your computer, and name it "main.c". Make sure to change the file extension to ".c" if it starts as something else (like ".txt").
    - If you're on Windows, make sure to untick the "hide file extensions" option in File Explorer. Otherwise, you can't easily edit the file type!
2. Open the file in your favourite code editor. VS Code works, or even something basic like Windows Notepad. Don't try to open it in MS Word or other word processors.
3. Add the following code (exactly word for word):

```C
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}
```
4. Compile the program, and run it!
    - If you're on a Linux or MacOS machine, compile the program by typing `gcc -o program main.c` into your terminal window, making sure to be in the correct directory.
    - Otherwise, you can run it in VS Code directly with the run button. You may need to install GCC or another C compiler if you don't have one installed already.

You should see the following output: "Hello, world!".

Let's break down what the program is doing:
1. `#include <stdio.h>`: This includes the standard C input/output library. A library is a collection of programs that someone else has made, and that we can reuse in our programs. For us, we need it for `printf()`, which is how we display text to the screen.
2. `int main() {...}`: This defines a new function called "main". We'll cover functions in a second, but for now, just know that every C program needs to have this, and that all the code we want to be run by the computer will have to live in `main()`. Everything inside the curly brackets `{}` is the body of the main function.
3. `printf("Hello, world!\n");`: This displays our message to the screen. `printf()` is a function that prints to the screen whatever arguments you give to it. In this case, we gave it the argument "Hello, world!\n", so that's what it printed. The `\n` to the end tells the computer to add a new line to the end after printing.
4. `return 0;`: This tells the program that it's done, and that everything went okay. If we returned something other than `0`, then the computer would interpret that as an error message indicating that the program had crashed.

That's it! Notice that each line of code is read one after the other, in order, i.e. we print our message before we exit the program (return 0). Also, note that lines of code that do work have to end in semicolons (`;`). If you forget this, your program won't compile! 

This is a good start, but we need some more tools in our toolbox before we can write useful programs.

## Variables and Datatypes

Variables are where we store values. They behave similarly to a variable in Algebra. You can think of them as buckets where we put data that we want to access later. They can be given nearly any name you want, as long as they start with an alphabetical character or an underscore. This guide will be using a lot of single-character variable names, but in general, it's good to use descriptive names that say what your variable does.

### Integers
Integers are one of the most basic datatypes. They store whole numbers (just like integers in mathematics). Here's an example:

```C
int x = 42;
```

This means "make an integer called x, and set its value to 42." Note that unlike in algebra, "=" does not mean "equals," and is not commutative. You **cannot** write `42 = x`: this is an error and will not run!

Now that we've made the variable, we can use it in our code. If we print it out, we can see its value like so:
```C
printf("%d\n", x);
```

This syntax is a little arcane, but it essentially says to replace `%d` with an integer (decimal number, hence the "d") with whatever other argument is passed to the function (in this case, `x`), and then print that, followed by a newline character (`\n`).

We can change the variable like so:
```C
int y = 100;
y = y + 1;
```

Now, `y` will contain the value `101`. We do this operation (adding a number to another number) so frequently when programming, that there's a shortcut for it: `y += 1`. In fact, we add `1` to a number so much that `y++` is the same as `y += 1`!

We can also make new variables based on the values of previously defined variables. For example:
```C
int a = 50;
int b = a + 50;
int c = b / 2;
int d = (b + a) * 10;
int e = a - (2 * b);
```
Note that we've introduced some mathematical operations. `*` means "times" (i.e. 3*2 = 6), and `\` means "divided by" (i.e. 6/2 = 3).

If we bring this all together, it might look something like this:

```C
int x = 42;
int y = 100;
y = y + 1;
int a = 50;
int b = a + 50;
int c = b / 2;
int d = (b + a) * 10;
int e = a - (2 * b);

printf("%d\n", x);
printf("%d\n", y);
printf("%d\n", a);
printf("%d\n", b);
printf("%d\n", c);
printf("%d\n", d);
printf("%d\n", e);

return 0;

```
This program will print:
```
42
101
50
100
50
1500
-150
```

### Floating Point Numbers
Another common datatype is the floating point number, or "float." These are all real numbers, like "42.0," "-8.31," or "100000.00001." A very similar datatype is "double", which does the same job as a float, except that it stores numbers with double the precision of a float. They can defined and used very similarly to an integer:

```
float x = 42.8;
float y = x - 5;
float z = 50;
```

One thing to keep in mind is that there are an infinite number of numbers (even just between 0 and 1), and only a finite number of bits in your computer. At the end of the day, you can't be more precise than the physical hardware of your computer allows, so you can't perfectly represent every number using a float. Think of it like the number $\frac{1}{3}$: you can't write it perfectly, only as $0.3333333...$

The format string identifier for a float is `%f`, and for a double it's `%lf` (for "long float"). A format string identifier is what's used in `printf()`, to tell it what variable will be subbed in, like `%d` for integers.

### Characters
You can also represent single textual characters as well, like `A`, `c`, or `(`. These are defined like so:
```C
char x = 'A';
char y = 'c';
char z = '!';
char space = ' ';
char number = '2';
char newline = '\n';
```
Keep in mind that `'2'` is not the same as `2`: the former is the character '2', and the latter is the integer (number) 2. Trying to assign the character to an integer, or trying to use one in a mathematical equation, will not work!

That last char is an interesting one, as it looks like two characters: `\` and `n`. Actually, this is a single character, and represents the newline! The backslash (`\`) is an escape character, telling the compiler to interpret the following character as a special sequence: something like newline, end of transmission, null, bell (like on a typewriter!), etc. You can find a list of these at https://www.asciitable.com/. 

Don't worry too much about escape character sequences for now. I would just focus on `\n`, which is newline; and `\0`, which is null (used in strings, which will be covered soon). Also, if you want to print the backslash key, you'll need to write `\\`. If you try to write something like `"Hello\Goodbye"`, then the compiler will try to intepret this with `\G` being a single character. Writing `"Hello\\Goodbye"` instead will have the desired effect.

The format string identifier for characters is `%c`.

### Strings
Strings are sequences of characters, like "Hello, world!\n". Strings in C are not very advanced compared to some more modern programming languages; they're simply lists of characters. For example:

```C
char someString[] = "Hello, world!\n";
```

When we printed "Hello, world!" at the start, we were using a string. We won't go into strings too much right now because they can get pretty complicated pretty fast due to C's need to manually manage its own memory.

One special rule for strings compared to other lists is that they always end with the null character `'\0'`. This tells the compiler where the end of the string is.

### Arrays
Arrays are lists. We can have a list of any of the datatypes we've talked about so far: lists of ints, floats, chars, or even other lists! To define them, we use the format "`type name[] = value`". Note the square brackets []: these are what we use to specify that we want a list, rather than the base datatype. Here's an example:
```C
float someArray[] = {42, 85.2, 33, 100.42};
```

To access an element in the array, use the square bracket location, i.e. `someArray[0]` is `42`. Note that array indexing starts at `0` rather than `1`! This means that the last element in the array is at index `3`, **not** `4`. As strings are just arrays of characters, you can index into a string in the same way (i.e. `someString[1]` from the earlier example is `e`);

As mentioned in the strings section, arrays can get pretty complicated pretty fast. We'll skip over most of it. Just keep in mind that you can't resize an array (i.e. add more elements to the end, or make it shorter).

## Conditionals and Boolean Logic
Put simply, conditionals are "if statements." These are used to control logic flow in a program. For example, maybe we want to do something different if a number is less than 0 rather than if it's greater than or equal to 0. We can do this specific example like so:
```C
if (x < 0) {
 // Code for if x is less than 0 here
}
else {
 // Code for if x is greater than 0 here
}
```
We run the first section of code if and only if x is less than 0, and the second if and only if x is greater than or equal to 0. Note that a double slash (`//`) signifies a comment, which is text that the compiler will ignore. Comparison operators include:
```
<: less than
>: greater than
<=: less than or equal to
>=: greater than or equal to
==: equal to
!=: not equal to
```

Additionally, the following are valid boolean operators:
```
!: not
||: or
&&: and
```

These can be combined into longer statements, like this: 
```C
 (x != 1) && (!(x > 5) || (y != 0) || (z == 8))
```

This can be read as something that is true if:
- x is not equal to 1, and either...
    - x is not greater than 5, or...
    - y is not equal to 0, or...
    - z is equal to 8

Otherwise, the whole statement will be false.

Booleans are actually a datatype in and of themselves. Behind the scenes they're just integers, but by adding `#include <stdbool.h>` to the top of your program, you can use `bool`, `true`, and `false` in your program like so:
```C
bool someFlag = false;
bool someOtherFlag = true;
if (someFlag) {
    // will not run
}
if (someOtherFlag) {
    // will run
}
```

## Loops
Loops allow us to repeat code for a certain number of times, or until a condition is met. There are two main types of loops: while loops and for loops. One loop is not more powerful than the other: anything that can be done with a while loop can be done with a for loop, and vice versa.

While loops have a similar syntax to if statements. They will execute their code over and over again, until their condition is false. For example, to print all the integers from 1 to 10:
```C
int i = 1;
while (i < 11) {
    printf("%d\n", i);
    i++;
}
```

This pattern of initializing an index variable, looping until a condition is met, and incrementing that variable each time, is really common. For loops allow us to write that same pattern in a more compact manner. The following code produces the same thing (all integers from 1 to 10):
```C
for (int i = 1; i < 11; i++) {
    printf("%d\n", i);
}
```
Before the for loop iterates, it will complete the initialization step (creating a variable `i` and setting its value to `1`). Then, for each iteration of the loop, it will first check if the condition is met (in this case, `i < 11`). If it is not met (evaluates to `false`), the loop exits. If it is met (evaluates to `true`), the loop body is executed (the print statement). Then, finally, the iteration step occurs, incrementing `i` by `1`.

Combining loops and conditionals allows us to write really complicated programs. However, there's another tool that helps us to write code more neatly and efficiently: functions.

## Functions
Functions allow us to give segments of code a name, and re-use them throughout the program. `main()`, which we've seen before, is an example of a function. Here's another example, showing a simple function that adds two integers together:
```C
int sum(int a, int b) {
    c = a + b;
    return c;
}
```
Here's a quick breakdown of the components to this function:
1. The first `int` is the return type of the function. This says what datatype the function gives back when it completes. If it doesn't give anything back, then this should be `void`.
2. The word `sum` is the name of the function. This is what we use when we want to "call" the function (demonstrated shortly).
3. This function takes two arguments, `a` and `b`. These are variables that must be given to (passed to) the function whenever it is called. We have to specify their types as well. Here, they're both integers (`int`).
4. Finally, we have the body of the function. We make a new variable called `c`, which we assign to the value of the sum of `a` and `b`. Then, we return the value in `c`. This means that we give back the sum of `a` and `b` to whoever called the function.
    - Note that we could also have written just `return a + b` if we wanted to be more concise.

Functions are often defined in their own files, but if they're in the same file as the main function, they must be defined before (above) any calls are made to them.

Here's what it might look like to call the function:
```C
#include <stdio.h>

int sum(int a, int b) {
    c = a + b;
    return c;
}

int main() {
    int x = 5;
    int y = 6;
    int z = sum(x,y); // z will be set to x + y
    printf("The value of z is: %d\n", z);
    return 0;
}
```

In this example, `sum(x,y)` "evaluates to" 11, which is the return value of the function. We can call functions within other functions, however much we want. In fact, we're doing so in the example above: as stated above, `main()` is also a function! However, to drive the point home, this program could also have been written like this:
```C
#include <stdio.h>

int sum(int a, int b) {
    c = a + b;
    return c;
}

int main() {
    int x = 5;
    int y = 6;
    printf("The sum is: %d\n", sum(x,y));
    return 0;
}
```
We got rid of `z`, and just used the return value of the function directly in the call to `printf()`. This is totally fine, and works just as well as the previous method!

Another important point to note here is that when you pass a variable to a function, the function gets a the **value** of that variable, not the **variable itself**. Consider the following example:

```C
void attemptToSum(int a, int b, int c) {
    c = a + b;
}

int main() {
    int a = 5;
    int b = 6;
    int c = 0;
    attemptToSum(a,b,c);
    printf("The sum is: %d\n", c); // This prints 0!
}
```

An important revelation here is that the name of the variable being passed into the function doesn't matter. Even though the names of the parameters of `attemptToSum()` matches the names of the arguments passed to it, they're actually different variables! The variables `a`, `b`, and `c` in `attemptToSum()` are different variables than the variables `a`, `b`, and `c` defined in `main()`. Changing variable `c` in `attemptToSum()`  did *not* change variable `c` in `main()`.

These examples of functions aren't actually much use in real life. Instead of a `sum()` function, it's much easier (and more sensible!) to just use the `+` operator like a normal human being. However, their true power will become obvious as you code. Any time you find yourself doing a "step" in your problem solving process, consider making that a function! For example, here's an actual implementation of the `printf()` function (from https://svnweb.freebsd.org/base/head/lib/libc/stdio/printf.c?view=markup):
```C
int printf(char const * __restrict fmt, ...) {
    int ret;
    va_list ap;

    va_start(ap, fmt);
    ret = vfprintf(stdout, fmt, ap);
    va_end(ap);
    return (ret);
}
```
Notice how much nicer it is to not have to write that every time you want to print something to the display? And also notice how it's not doing much except just calling another function, `vfprintf()`? The reason that I didn't include that is because the file defining that is over 1000 lines long. If you'd like to look at it, it's here: https://svnweb.freebsd.org/base/head/lib/libc/stdio/vfprintf.c?view=markup

## Variable Scope
One more point to be aware of is something called "variable scope". The basic idea is that variables only exist within the curly brackets that they were created. Consider the following:
```C
int main() {
    int x = 5;
    if (x > 0) {
        int y = 10; // y starts existing
        printf("x is greater than 0.\n");
    } // y stops existing
    else {
        int y = -10; // A new y starts existing
        printf("x is less than 0.\n");
    } // The new y stops existing
    printf("The value of y is: %d\n", y) // ERROR! y does not exist!
    return 0;
}
```

This can particularly create issues in for loops. If you create a for loop like this:
```C
for (int i = 0; i < 42; i++) {
    // Do whatever
}
// i does not exist here!
```
You cannot access `i` after the loop terminates! If you need to access `i` afterwards, you can write it like this instead:
```C
int i;
for (i = 0; i < 42; i++) {
    // Do whatever
}
// i still exists here!
```