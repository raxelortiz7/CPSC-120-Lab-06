# Guessing Game

Let's write a guessing game where the player gets to choose the minimum number and maximum number to guess from and the computer's artificial intelligence (AI) will select a secret number from that range for the player to guess.

Additionally, the AI will give the player hints as to whether or not the player is getting warmer or colder with each guess.

The program takes two positive integers as command line parameters which define the minimum and maximum values of the guessing range. This is a way to control how hard or easy the game will be given the size of the range.

The AI will need to calculate the secret number and we don't want to make it easy for the player to guess. We'll use a pseudo-random number generator to make a hard to predict secret number for our game. (We use pseudo because nothing is _truly_ random when a machine is involved.)

If you use an Internet search engine to search for _random number generator in c++_ you will invariably be led to use the functions `rand()` and `srand()`. *Do not use these please.*

The functions `rand()` and `srand()` go way back and are part of the [ISO C90 specification](https://en.wikipedia.org/wiki/ANSI_C#C90). For this reason alone, they will never go away. However `rand()` is not a super high quality random number generator. The algorithm it uses is called [Lehmer random number generator](https://en.wikipedia.org/wiki/Lehmer_random_number_generator) or a [Park-Miller random number generator](https://doi.org/10.1145/63039.63042). D.H. Lehmer published the algorithm in 1949. Almost 40 years later, Park & Miller proposed using Lehmer's algorithm in a paper in 1988 because it was easy enough to implement using only integers, worked correctly on a computer with 32 bit integers, and appeared to be random enough after some statistical analysis.

The thinking at the time was that if you're going to go to all the trouble of writing a random number generator, you better pick an algorithm that will work correctly on the computers available at the time. The 1980s were a great period of transition as computers and software libraries standardized around 32 bit integers and 32 bit memory addressing. And in 1985, [IEEE standardized floating point numbers](https://en.wikipedia.org/wiki/IEEE_754) which further boosted interoperability of software. Park & Miller recommended Lehmer's algorithm because by 1988 32 bit integers had become common on the various central processing units used in computers ([Intel 386](https://en.wikipedia.org/wiki/Intel_80386), [Motorola 68020](https://en.wikipedia.org/wiki/Motorola_68020), [System/360](https://en.wikipedia.org/wiki/IBM_System/360) [MIPS](https://en.wikipedia.org/wiki/MIPS_architecture), [VAX](https://en.wikipedia.org/wiki/VAX), [Sparc](https://en.wikipedia.org/wiki/SPARC), [ARM](https://en.wikipedia.org/wiki/ARM_architecture), [PA-RISC](https://en.wikipedia.org/wiki/PA-RISC), etc.). 

Since we're writing programs in the 21st century and there are a lot of applications that need a little bit of unpredictability to make them interesting, let's use a random number generator that isn't old enough to collect Social Security.

The C++ Standard Library has a whole section dedicated to [pseudo-random numbers](https://en.cppreference.com/w/cpp/numeric/random). The library has a quite a few pseudo random number generator engines. We'll use the [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister) engine (because I like the sound of the name and it's a good PRNG).


Define a function named `int random_number_generator(int minimum, int maximum);`. Make sure that before you call this function that you've checked to make sure maximum is greater than minimum. If it isn't then you need to warn the player and exit from the program. We shall use the [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister) engine (because I like the sound of the name and it's a good PRNG).

The Mersenne Twister is written by Makoto Matsumoto and Takuji Nishimura in 1997. It's named Mersenne because it's period length is that of a [Mersenne prime](https://en.wikipedia.org/wiki/Mersenne_prime). The period length tells us how many numbers you can generate before the numbers start repeating from where you started. In our case, one must ask for ![2^19937 - 1](https://render.githubusercontent.com/render/math?math=2%5E19937%20-%201) or a 6,002 digit prime number. Mersenne primes are named after [Marin Mersenne](https://en.wikipedia.org/wiki/Marin_Mersenne) because he figured out that you can write certain primes in the form ![M_n = 2^n - 1](https://render.githubusercontent.com/render/math?math=M_n%20%3D%202%5En%20-%201) for some integer n. (Join the [Great Internet Mersenne Prime Search](https://en.wikipedia.org/wiki/Great_Internet_Mersenne_Prime_Search) to find the next unknown Mersenne prime.)

The Mersenne Twister is encapsulated in a C++ class. You will not make any changes to the code, all you must do is learn to use it.

Your main function shall have an infinite loop. The only way to exit out of the loop is if the player wins and then chooses to exit the game by refusing to play again. If this should happen use [`break`](https://en.cppreference.com/w/cpp/language/break) to break out of the loop. (Alternatively create a boolean variable and change it's value from true to false to end the loop.)

As the player guesses, keep track of their current guess and their last guess. If their current guess gets them closer to the secret number than their last guess then they are getting warmer. If their current guess is further way from the secret number than the last guess then they are getting colder. Give these hints to the player as they make guesses to help the game along.

Use a [C++ Array](https://en.cppreference.com/w/cpp/container/array) to store a series of messages that the AI prints to the screen. For example:

```c++
  std::array<std::string, 4> responses = {
      "\tNope - that's not it.\n", "\tSorry Charlie.\n",
      "\tWrong number - try again.\n", "\tYou can do this - guess again.\n"};
```

Then to print out a message at random you can re-use your random number generator. Because it is possible to select a location outside of the range of the array, we'll use the try/catch pattern to catch any errors.

```c++
try{
  std::cout << responses.at(2);
}catch(const exception& e){
    ErrorMessage();
    exit(1);
}
```

To calculate if the player's guesses are getting warmer or colder, consider the distance from the guess to the secret number. Mathematically, you can think of distance as the absolute value of the difference between the secret number and a given guess. When the distance decreases from the last guess to the current guess, then the player is getting warmer. Otherwise, the player is getting colder.

## Requirements

The program takes two integer arguments which define the minimum value for the player to guess and the maximum value for the player to guess.

The entire game runs within a loop in the main function. The loop continues until the player wins and chooses to exit.

Check to make sure that the values make sense, in other words that maximum is greater than minimum and that both minimum and maximum are positive values.

Generate a random secret number using the RandomNumberGenerator class. For example:

```c++
  RandomNumberGenerator rng(minimum_number, maximum_number);
  int secret_number = rng.next();
```

Declare two variables, `guess` and `last_guess` to keep track of the player's guesses. Initialize both to zero. After every guess, assign the value of guess to last_guess so that the game knows what the player is guessing currently and has guessed previously. This is needed to figure out if the player is getting warmer or colder.

Write a function named `NewGameMessage()` which prints a standard greeting every time a new game starts.

Write a function that gather's the player's guess first as a string and then converts it to an integer. Name this function `GatherGuess()`.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal.

Whenever a guess is made that is incorrect, print out a random message using the `WrongGuessMessage()` function.

If the guess is incorrect, use the function `WarmerOrColder()` to print a message hinting at which direction (greater or lesser than the current guess) the player should guess.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section Example Output below.

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
Makefile		guessing_game.cc
$ make doc
make doc
set -e; clang++ -MM -g -Wall -pipe -std=c++14  guessing_game.cc \
	| sed 's/\(guessing_game\)\.o[ :]*/\1.o guessing_game.d : /g' > guessing_game.d; \
	[ -s guessing_game.d ] || rm -f guessing_game.d
doxygen Doxyfile
$ ls
Doxyfile		README.md		guessing_game.cc
Makefile		doc			guessing_game.d
```

The inline documentation is saved in `doc/html`. To view the documentation, use the command `gio open doc/html/index.html` which will open the index file in your web browser.

If the `doxygen` command is not available, for instance when you use `make doc` the output looks like:

```
$ make doc
set -e; clang++ -MM -g -Wall -pipe -std=c++14  guessing_game.cc \
	| sed 's/\(guessing_game\)\.o[ :]*/\1.o guessing_game.d : /g' > guessing_game.d; \
	[ -s guessing_game.d ] || rm -f guessing_game.d
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
set -e; clang++ -MM -g -Wall -pipe -std=c++14  guessing_game.cc \
	| sed 's/\(guessing_game\)\.o[ :]*/\1.o guessing_game.d : /g' > guessing_game.d; \
	[ -s guessing_game.d ] || rm -f guessing_game.d
clang++ -g -Wall -pipe -std=c++14  -c guessing_game.cc
clang++ -g -Wall -pipe -std=c++14 -o guessing_game guessing_game.o 
$ ./guessing_game 
Please provide two positive integers as the maximum and minimum for this guessing game.
There was an error. Exiting the guessing game.
$ ./guessing_game 1
Please provide two positive integers as the maximum and minimum for this guessing game.
There was an error. Exiting the guessing game.
$ ./guessing_game 1 10
Hi - I'm a computer and I've thought of a number between 1 and 10.
Let's play a guessing game...
What's your guess?> 7
	Hooray! You guessed the secret number!!
Do you want to play again? (y or n)> n
$ ./guessing_game 1 10
Hi - I'm a computer and I've thought of a number between 1 and 10.
Let's play a guessing game...
What's your guess?> 1
	Sorry Charlie.
	You're getting warmer!
What's your guess?> 2
	Wrong number - try again.
	You're getting warmer!
What's your guess?> 3
	You can do this - guess again.
	You're getting warmer!
What's your guess?> 4
	Wrong number - try again.
	You're getting warmer!
What's your guess?> 5
	Wrong number - try again.
	You're getting warmer!
What's your guess?> 7
	Wrong number - try again.
	You're getting colder.
What's your guess?> 8
	Sorry Charlie.
	You're getting colder.
What's your guess?> 9
	Sorry Charlie.
	You're getting colder.
What's your guess?> 10
	Sorry Charlie.
	You're getting colder.
What's your guess?> 11
	Sorry Charlie.
	You're getting colder.
What's your guess?> 12
	Nope - that's not it.
	You're getting colder.
What's your guess?> 5
	Nope - that's not it.
	You're getting warmer!
What's your guess?> 6
	Hooray! You guessed the secret number!!
Do you want to play again? (y or n)> n
$ ./guessing_game 1 10
Hi - I'm a computer and I've thought of a number between 1 and 10.
Let's play a guessing game...
What's your guess?> 2
	You can do this - guess again.
	You're getting warmer!
What's your guess?> 3
	Hooray! You guessed the secret number!!
Do you want to play again? (y or n)> y
Great!! I'd love to play again...
Hi - I'm a computer and I've thought of a number between 1 and 10.
Let's play a guessing game...
What's your guess?> 5
	Wrong number - try again.
	You're getting colder.
What's your guess?> 4
	Wrong number - try again.
	You're getting warmer!
What's your guess?> 2
	Wrong number - try again.
	You're getting warmer!
What's your guess?> 1
	Hooray! You guessed the secret number!!
Do you want to play again? (y or n)> n
$
```

