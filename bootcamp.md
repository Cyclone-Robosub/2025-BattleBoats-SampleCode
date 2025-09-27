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

### Arrays
Arrays are lists. We can have a list of any of the datatypes we've talked about so far: lists of ints, floats, chars, or even other lists! To define them, we use the format "`type name[] = value`". Note the square brackets []: these are what we use to specify that we want a list, rather than the base datatype. Here's an example:
```C
float someArray[] = {42, 85.2, 33, 100.42};
```

To access an element in the array, use the square bracket location, i.e. `someArray[0]` is `42`. Note that array indexing starts at `0` rather than `1`! This means that the last element in the array is at index `3`, **not** `4`. As strings are just arrays of characters, you can index into a string in the same way (i.e. `someString[1]` from the earlier example is `e`);

## Conditionals
Put simply, conditionals are "if statements." These are used to control logic flow in a program.