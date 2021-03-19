# Find Minimum

We have worked with many different types, `int`, `float`, `string`, `bool`, and even `void` - the type that can't have a variable. In all of our programs, we've always worked with one value at a time. However the strength of using a computer is that it can keep many values organized in its memory which enables the programmer to come up wit many interesting applications.

Consider for a moment how useful your favorite app on your smart phone would be if it could only hold one photo, one message, or one video. Many of our favorite apps use lists like a list of favorite videos or playlists of our favorite songs. The concept of keep things organized in lists is very powerful and if we can master how to use them then we'll find many new problem solving strategies available to us.

Let's start with thinking about our lists as fixed size and it can only hold one kind of thing (a type). That means that if we create a list, then the list must have a length greater than zero and it can never grow or shrink. This is what we call an [Array](https://en.cppreference.com/w/cpp/container/array) in C++.

Let's declare an array of ten integers. To use arrays, remember to `#include <array>`. The code below will fetch the value 8 from the fourth location. Remember we start counting from 0. In the example below, the array `my_array` has been statically initialized to have the even numbers from 2 to 20. Notice the type is `array<int, 10>` which tells the compiler that the variable `my_array` is an array that contains 10 integer variables.

```c++
array<int, 10> my_array{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
int fourth_element = 0;
try{
  fourth_element = my_array.at(3);
}catch(const exception& e){
  ErrorMessage("There's nothing there!");
  exit(1);
}
```

Notice that the [`at()`](https://en.cppreference.com/w/cpp/container/array/at) method is wrapped with a try/catch so if by accident you attempt to fetch an item that doesn't exist you'll be able to recover from your error.

If you use an Internet search engine to search for _c++ array_ you will find plenty of pages showing you how to use _C arrays_. *Do not use C Arrays please.*

C arrays are pretty nifty and you can do some really wild and amazing things with them. Because we can do wild and amazing things with them, C arrays can be dangerous to use and tedious to learn. C++ arrays have really great features that help beginners catch their errors early and often.

Looping through a C++ array is very easy too. Let's print out all the elements in an array to the terminal.
```c++
array<int, 10> my_array{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
for(int index = 0; index < my_array.size(); index++){
  int element = 0;
  try{
    element = my_array.at(index);
  }catch(const exception& e){
    ErrorMessage("There's nothing there!");
    exit(1);
  }
  cout << element << "\n";
}
```

C++ arrays also support C++'s [range-for](https://en.cppreference.com/w/cpp/language/range-for). It is like the for loop you have previously learned but is a lot easier to write and read when working with data types that are sequences like arrays.

```c++
array<int, 10> my_array{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
for(const auto& element : my_array){
  cout << element << "\n";
}
```

The example above makes use of the [`auto`](https://en.cppreference.com/w/cpp/language/auto) keyword which is a _placeholder type specifier_. In other words, since the language is strongly typed you can let the compiler figure out what the type is for you. This only works in certain situations and range-for loops are an example.

In this exercise, we shall declare an array in main, use a random number generator to fill it with values, then find the minimum value, and finally print it out.

See the [README.md in part-3](../part-3/README.md) for more information about the random number generator.

## Requirements

Using a C++ array and a random number generator, create an array of random integers. Then print out the array with one element from the array on a line. Next find the minimum value in the array by visiting each location in the array. Once the minimum value is found, return it to the main function and print it out.

Using the inline documentation, implement the following functions.

* `void ErrorMessage(const string& message);`
* `void PrintArray(const array<int, number_elements>& the_array);`
* `void FillArray(array<int, number_elements>& the_array, RandomNumberGenerator& random_number_generator);`
* `int FindMinimum(const array<int, number_elements>& the_array);`

A global `const int` variable is defined for your use with the array in this exercise. The variable defines the size of the array and it can be used throughout the program.

```
const int number_elements = 10;
```

In the functions that you must define, use any type of for loop you would like to use.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* doc: generate HTML documentation from the source code using Doxygen
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* headercheck: check to make sure your files have the appropriate header

## Inline Documentation
The project is thoroughly documented inline using the [Doxygen](https://en.wikipedia.org/wiki/Doxygen) format. The documentation establishes a framework for you to follow so that you can implement all the details of the program. To generate HTML formatted documents to view on your computer use the make target `doc`. For example:

```
$ ls
Doxyfile	Makefile	README.md	find_min.cc
$ make doc
set -e; clang++ -MM -g -Wall -pipe -std=c++14  find_min.cc \
	| sed 's/\(find_min\)\.o[ :]*/\1.o find_min.d : /g' > find_min.d; \
	[ -s find_min.d ] || rm -f find_min.d
doxygen Doxyfile
$ ls
Doxyfile	README.md	find_min.cc
Makefile	doc/		find_min.d
```

The inline documentation is saved in `doc/html`. To view the documentation, use the command `gio open doc/html/index.html` which will open the index file in your web browser.

If the `doxygen` command is not available, for instance when you use `make doc` the output looks like:

```
$ make doc
set -e; clang++ -MM -g -Wall -pipe -std=c++14  find_min.cc \
	| sed 's/\(find_min\)\.o[ :]*/\1.o find_min.d : /g' > find_min.d; \
	[ -s find_min.d ] || rm -f find_min.d
doxygen Doxyfile
make: doxygen: No such file or directory
make: *** [doc] Error 1
```

Then you can install `doxygen` using the command `sudo apt install doxygen doxygen-latex graphviz`.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
clang++ -g -Wall -pipe -std=c++14  -c find_min.cc
clang++ -g -Wall -pipe -std=c++14 -o find_min find_min.o 
$ ./find_min 
Please provide two positive integers as the maximum and minimum for this exercise.
There was an error. Exiting.
$ ./find_min 1
Please provide two positive integers as the maximum and minimum for this exercise.
There was an error. Exiting.
$ ./find_min 1 10
5
8
7
1
3
1
4
10
3
1
The minimum value in the array is 1
$ ./find_min 1 200
121
194
128
49
12
153
194
183
51
55
The minimum value in the array is 12
$ ./find_min 1 10000
1600
6053
3346
2556
5289
2275
7161
5799
8002
3921
The minimum value in the array is 1600
```

