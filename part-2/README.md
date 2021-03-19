# Calculate Average

Let's get some more practice with C++ arrays by taking our last program and modifying it just a little bit.

In the previous exercise, we found the minimum value in an array by looping through the array. This time around, let's do some calculations.

Calculating the [average (or arithmetic mean)](https://en.wikipedia.org/wiki/Mean) is something that we have all learned long ago. The operations that one does to calculate the average of a sequence of numbers is to sum all the numbers and then divide by how many numbers there are. Mathematically, this is denoted as ![\bar{x} = \frac{1}{n}\sum_{i = 1}^{n} x_i](https://render.githubusercontent.com/render/math?math=%5Cbar%7Bx%7D%20%3D%20%5Cfrac%7B1%7D%7Bn%7D%5Csum_%7Bi%20%3D%201%7D%5E%7Bn%7D%20x_i).

For example, let's say we have the number 2, 3, 5, and 7. The sum of all these numbers is 17. There are 4 numbers so the average is 4.25.

Using the same framework from the previous exercise, let's generate a list of random numbers and then calculate the average.

The catch is that we must use the C++'s [range-for](https://en.cppreference.com/w/cpp/language/range-for) loop rather than the old fashioned foo loop we have been using previously.

Let's image we want to loop through an array of integers with a range-for.

```c++
array<int, 10> my_array{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
for(const auto& element : my_array){
  cout << element << "\n";
}
```

The code above will loop through the entire array, one element at a time, and print each element out to a line of it's own.

Notice that we are marking the variable element as `const`. Meaning that it can't change. If we wish to modify the values of the array's elements then we have to remove the `const`. Imagine that we wish to set all the locations of an array to the value 42, the loop may look like this:

```c++
array<int, 10> my_array{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
for(auto& element : my_array){
  element = 42;
}
```

In this exercise, we shall declare an array in main, use a random number generator to fill it with values, then calculate the average value, and finally print it out.

See the [README.md in part-3](../part-3/README.md) for more information about the random number generator.

## Requirements

Using a C++ array and a random number generator, create an array of random integers. Then print out the array with one element from the array on a line. Next the average of the values in the array by visiting each location in the array, sum the values, and calculate the quotient of the sum over the number of elements in the array. Once the average is found, return it to the main function and print it out.

Using the inline documentation, implement the following functions.

* `void ErrorMessage(const string& message);`
* `void PrintArray(const array<int, number_elements>& the_array);`
* `void FillArray(array<int, number_elements>& the_array, RandomNumberGenerator& random_number_generator);`
* `float CalculateAverage(const array<int, number_elements>& the_array);`

A global `const int` variable is defined for your use with the array in this exercise. The variable defines the size of the array and it can be used throughout the program.

```
const int number_elements = 10;
```

In the functions that you must define, use the C++ range-for loop.


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
Doxyfile		README.md
Makefile		calc_average.cc
$ make doc
set -e; clang++ -MM -g -Wall -pipe -std=c++14  calc_average.cc \
	| sed 's/\(calc_average\)\.o[ :]*/\1.o calc_average.d : /g' > calc_average.d; \
	[ -s calc_average.d ] || rm -f calc_average.d
doxygen Doxyfile
ls$ ls
Doxyfile		README.md		calc_average.d
Makefile		calc_average.cc		doc/
```

The inline documentation is saved in `doc/html`. To view the documentation, use the command `gio open doc/html/index.html` which will open the index file in your web browser.

If the `doxygen` command is not available, for instance when you use `make doc` the output looks like:

```
$ make doc
set -e; clang++ -MM -g -Wall -pipe -std=c++14  calc_average.cc \
	| sed 's/\(calc_average\)\.o[ :]*/\1.o calc_average.d : /g' > calc_average.d; \
	[ -s calc_average.d ] || rm -f calc_average.d
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
set -e; clang++ -MM -g -Wall -pipe -std=c++14  calc_average.cc \
	| sed 's/\(calc_average\)\.o[ :]*/\1.o calc_average.d : /g' > calc_average.d; \
	[ -s calc_average.d ] || rm -f calc_average.d
clang++ -g -Wall -pipe -std=c++14  -c calc_average.cc
clang++ -g -Wall -pipe -std=c++14 -o calc_average calc_average.o 
$ ./calc_average 
Please provide two positive integers as the maximum and minimum for this exercise.
There was an error. Exiting.
$ ./calc_average 1
Please provide two positive integers as the maximum and minimum for this exercise.
There was an error. Exiting.
$ ./calc_average 1 10
10
1
1
6
9
6
2
7
8
2
The average value of the array is 5.2
$ ./calc_average 1 100
94
25
29
47
69
71
50
85
88
87
The average value of the array is 64.5
$ ./calc_average 1 100000
57577
1010
79775
28342
54458
22768
25920
56665
15000
15295
The average value of the array is 35681
```

