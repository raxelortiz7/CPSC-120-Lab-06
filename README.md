# CPSC 120 - Lab 06

# Instructions

Write a program for each exercise sub-directory. Each exercise subdirectory is prefixed with the string `part-`. The subdirectory contains a README.md which explains the requirements for the exercise.

Each exercise subdirectory has its own [Makefile](https://en.wikipedia.org/wiki/Makefile) which you may use to build and test your progress. Each Makefile has the following targets:

* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* doc: generate HTML documentation from the source code using Doxygen
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* headercheck: check to make sure your files have the appropriate header

To build the program use the `make` command. The Makefile's default target is to build `all`.

Every file that you submit must have a header. Please follow the guidelines from the course Canvas page.

Please adhere to the [Google C++ coding style](https://google.github.io/styleguide/cppguide.html).

When writing git log comments, please make them descriptive and meaningful.

# Inline Documentation
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

# Rubric

Each exercise is worth 5 points. There is a total of 15 points possible. Your program must compile before it is graded. Submissions that do not compile shall be assigned a zero grade.

For each problem:

* Functionality (3 points): Your submission shall be assessed for the appropriate constructs and strategies to address the exercise. A program the passes the instructor's tests completely receives full marks. A program that partially passes the instructors tests receives partial-marks. A program that fails the majority or all the tests receives no marks.
* Format & Readability (2 point): Your submission shall be assessed by checking whether your code passess the style and format check, as well as how well it follows the proper naming conventions, and internal documentation guidelines. Git log messages are an integral part of how readable your project is. Failure to include a header forfeits all marks.

