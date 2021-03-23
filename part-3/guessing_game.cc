// Raxel Ortiz
// CPSC 120-05
// 2021-03-18
// raxelortiz7@csu.fullerton.edu
// @raxelortiz7
//
// Lab 06-03
//
// This program is a guessing game!
//

// Add the following header files algorithm, array, cstdlib,
// iostream, random
#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <random> 
#include <ostream>

using namespace std;

/// The RandomNumberGenerator class is a wrapper around the Standard C++
/// Library's Mersenne Twister pseudo random number generator.
/// This class is complete and correct; please do not make any changes to it.
///
/// In lieu of directly working with the [Mersenne Twister
/// class]
/// (https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine),
/// this class serves as a lightweight wrapper around the necessary elements of
/// the library. The usage of this class is very simple and requires a
/// minimum and maximum value for initialization.
/// \code
/// int minimum_random_number = 1;
/// int maximum_random_number = 10;
/// RandomNumberGenerator my_random_number_generator{minimum_random_number,
/// maximum_random_number}; int random_number =
/// my_random_number_generator.next();
/// \endcode
class RandomNumberGenerator {
 private:
  /// A hardware entropy source (a device on your computer to give random bits)
  std::random_device rd;
  /// A sequence of random bits to seed the Mersenne Twister engine
  std::seed_seq seed;
  /// A Mersenne Twister engine
  std::mt19937 mt_engine;
  /// A uniform distribution; select numbers randomly in a uniform manner
  std::uniform_int_distribution<> uniform_dist;

 public:
  /// Constructor to the RandomNumberGenerator class
  ///
  /// The RandomNumberGenerator generates random integer numbers between
  /// \p minimum and \p maximum. The constructor initializes and prepares
  /// the engine. To generate a number use the <RandomNumberGenerator::next>()
  /// method.
  ///
  /// \param minimum The lowest value the random number generator will return
  /// \param maximum The largest value the random number generator will return
  RandomNumberGenerator(int minimum, int maximum)
      : seed{rd()}, mt_engine{rd()}, uniform_dist{minimum, maximum} {}

  /// Return a random number
  ///
  /// Returns a random integer number between the minimum and maximum set
  /// when the constructor was called.
  /// \sa{RandomNumberGenerator::RandomNumberGenerator}
  ///
  /// \returns An integer between the minimum and maximum set when
  /// the constructor was called
  auto next() -> int {
    int random_number = uniform_dist(mt_engine);
    // std::cout << "Debugging: The random number is " << random_number << "\n";
    return random_number;
  }
};

/// NewGameMessage prints a short message at the start of every game summarizing
/// the \p minimum_number and \p maximum_number used in the guessing game.
///
/// For example, if the \p minimum_number and \p maximum_number are 1 and 5
/// respectively, then the function will print the message:
/// \code
/// "Hi - I'm a computer and I've thought of a number between 1 and 10.\n"
/// "Let's play a guessing game...\n"
/// \endcode
///
/// \param minimum_number The lowest number that a player can guess; the random
/// number generator uses this as it's minimum as well.
/// \param maximum_number The largest number that a player can guess; the random
/// number generator uses this as it's maximum as well.
void NewGameMessage(int minimum_number, int maximum_number) {
  cout << "Hi - I'm a computer and I've thought of a number between "
       << minimum_number << " and " << maximum_number << ".\n";
  cout << "Let's play a guessing game...\n";
}

/// ErrorMessage prints out \p message first and then prints the standard
/// message
/// \code
/// "There was an error. Exiting the guessing game.\n".
/// \endcode
///
/// \param message The programmer defined string that specifies the current
/// error.
void ErrorMessage(const string& message) {
  // implement ErrorMessage
  cout << message << "\n";
}

/// GatherGuess prompts the user for a guess, gathers the guess as a string,
/// converts that string to an integer, and finally returns the integer.
///
/// GatherGuess reads in strings to ensure that the game player always provides
/// good input. Since
/// [stoi()](https://en.cppreference.com/w/cpp/string/basic_string/stol) is
/// used to convert from a string to an integer, any input error the player
/// makes can be caught as an exception an handled by cleanly exiting the game.
///
/// \returns An integer representing the guess the player typed in
int GatherGuess() {
  // implement GatherGuess()
  string user_guess = "";
  cout << "What's your guess? ";
  cin >> user_guess;
  int user;
try{
   user = stoi(user_guess);
}catch(const exception& e){
  ErrorMessage("Problem getting guess number");
  exit(1);
  }
  return user;
}

/// WrongGuessMessage prints a random message to the terminal to let the
/// player know that what was guessed was wrong.
///
/// The function has a local variable called responses which is an array of
/// string messages. Given the \p message_id, the message is selected from
/// the array and printed to the terminal.
///
/// Use the random number generator to feed a random number as \p message_id.
/// Next select the message using the
/// [at()](https://en.cppreference.com/w/cpp/container/array) method of the
/// [array class](https://en.cppreference.com/w/cpp/container/array).The at()
/// method throws an exception if the index of the item is outside of the
/// bounds of the array. Make sure to wrap the call to at() in a try/catch
/// statement.
///
/// \param message_id The index of the message to be selected from the
/// array responses.
void WrongGuessMessage(int message_id) {
  // Implement WrongGuessMessage() 
  array<string, 4> responses = {"\tNope - that's not it.\n", "\tSorry Charlie.\n",
      "\tWrong number - try again.\n", "\tYou can do this - guess again.\n"};
  cout << responses.at(message_id); 
}

/// WarmerOrColder will take the player's \p guess, the player's \p last_guess
/// and the game's \p secret_number and print if the player is getting warmer
/// or colder.
///
/// Given the player's \p guess, the player's \p last_guess and the game's
/// \p secret_number, calculate if the player is moving towards the
/// \p secret_number (getting warmer) or moving away from the \p secret_number
/// (getting colder). To calculate this, use absolute value. You may use the
/// [abs()](https://en.cppreference.com/w/cpp/numeric/math/abs) that is
/// defined in the C++ Standard Library or write your own.
///
/// If
/// \f$\left| secret\_number - guess \right| <  \left| secret\_number - last\_guess \right|\f$
/// is true then the player is getting warmer, else the
/// player is getting colder.
///
/// \param guess The player's current guess
/// \param last_guess The player's previous guess
/// \param secret_number The game's secret number
///
/// \remark Using this function implies that the player's guess is being
/// saved in the main function such that there is a current guess variable
/// and a last guess variable.
void WarmerOrColder(int guess, int last_guess, int secret_number) {
  // Implement WarmerOrColder()
  int previouse_distance = abs(secret_number - last_guess);
  int curent_distance = abs(secret_number - guess);
  RandomNumberGenerator meassage(0,3);
  int mecha = meassage.next();
if(curent_distance < previouse_distance){
  WrongGuessMessage(mecha);
  cout << "\tYou're getting warmer\n";
  } else if (previouse_distance > curent_distance){
  WrongGuessMessage(mecha);
  cout << "\tYou're getting colder\n";
  } 
}

/// Entry point to the mind_reader program
/// \remark Must have at least 2 arguments. The first argument is the minimum
/// to be guessed and the second argument is the maximum to be guessed.
int main(int argc, char* argv[]) {
  if (argc < 3) {
    ErrorMessage(
        "Please provide two positive integers as the maximum and "
        "minimum for this guessing game.");
    exit(1);
  }
  string argv_one_minimum = string(argv[1]);
  string argv_two_maximum = string(argv[2]);
  int minimum_number = 0;
  int maximum_number = 0;

  // convert argv_one_minimum and argv_two_maximum to integers and
  // assign to minimum_number and maximum_number.
try{
  minimum_number = stoi(argv_one_minimum);
}catch(const exception& e){
  ErrorMessage("Problem");
  exit(1);
}
try{
  maximum_number = stoi(argv_two_maximum);
}catch(const exception& e){
  ErrorMessage("Problem");
  exit(1);
}
  // Check to make sure minimum_number is less than maximum_number,
  // and that both of them are greater than zero. Otherwise, print an 
  // error message an exit.
if(maximum_number <= minimum_number || minimum_number <= 0 || maximum_number <= 0){
    ErrorMessage("the min and the max have to be a min max.");
    exit(1);
}    
  RandomNumberGenerator rng(minimum_number, maximum_number);
  string answer = "y";
while(answer == "y"){
  int secret_number = rng.next();
  cout << "Debugging: The secret number is " << secret_number << "\n";
  int guess = 0;
  int last_guess = 0;
  NewGameMessage(minimum_number, maximum_number);
  do{
  guess = GatherGuess();
  if(guess == secret_number){
    cout << "\t Hooray! You guessed the secret number!!\n";
    cout << "Do you want to play again? (y or n)>\n";
    cin >> answer;
  } else {
    WarmerOrColder(guess,last_guess, secret_number);
    last_guess = guess;
    }
  } while(guess != secret_number);
}
  

  // Write a game loop which will prompt the player for their
  // guess. When the guess is correct, prompt the user with:
  // "\tHooray! You guessed the secret number!!\n";
  // "Do you want to play again? (y or n)> ";
  // If the player choose to play again, generate a new secret number
  // and continue.
  //
  // If the guess is incorrect, then print out a WrongGuessMessage()
  // and tell the player if they are getting warmer or colder.
  //
  // Don't forget to save the guess as the last_guess at the end of every
  // loop iteration.

  return 0;
}
