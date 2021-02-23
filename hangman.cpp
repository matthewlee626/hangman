#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
#include <filesystem>
namespace fs = std::filesystem;

class Hangman {

  public:
    Hangman(string gameWord){
      guessesLeft = 6;
      word = gameWord;
      guess = string(gameWord.length(), '_');
    };
    void printGameState(){
        cout << "Guesses left: " << guessesLeft << endl;
        cout << "Word: " << guess << endl;
        cout << "        ______" << endl;
        cout << "        |     " << endl;
        cout << "        " << (guessesLeft > 5 ? " " : "O") << "     " << endl;
        cout << "        " << (guessesLeft > 4 ? " " : "|") << "     " << endl;
        cout << "       " << (guessesLeft > 3 ? " " : "-") << (guessesLeft > 4 ? " " : "|") << (guessesLeft > 2 ? " " : "-") << "    " << endl;
        cout << "        " << (guessesLeft > 4 ? " " : "|") << "     " << endl;
        cout << "       " << (guessesLeft > 1 ? " " : "/") << " " << (guessesLeft > 0 ? " " : "\\") << "    " << endl;
    }
    bool isGameOver(){
      return guessesLeft == 0;
    }
    bool isGameWon(){
      return guess == word;
    }
    void guessLetter(char letter){
      if(guess.find(letter) != string::npos){
        cout << "You already guessed that letter!" << endl;
      }
      if(word.find(letter) == string::npos){
        guessesLeft--;
        cout << "Wrong guess!" << endl;
      } else {
        for(int i = 0; i < word.length(); i++){
          if(word[i] == letter){
            guess[i] = letter;
          }
        }
        cout << "Correct guess!" << endl;
      }
    }
    string getWord(){
      return word;
    };

  private:
    int guessesLeft;
    string word;
    string guess;
};

int main() {
  string word;
  
  cout << "Welcome to Hangman!" << endl;
  cout << "Enter a word to play with: ";
  cin >> word;
  cout << endl;
  Hangman game = Hangman(word);
  for (int i = 0; i < 7; i++) {
    game.printGameState();
    string guess = " ";
    while (guess == " ") {
      cout << "Guess a letter: ";
      cin >> guess;
      if (guess.length() == 1 && isalpha(guess[0])) {
        break;
      }
      cout << "You must guess a letter!" << endl;
      guess = " ";
    }
    game.guessLetter(guess[0]);
    if (game.isGameOver()) {
      cout << "You lost!" << endl;
      break;
    }
    if (game.isGameWon()) {
      cout << "You won!" << endl;
      cout << "The word was " << game.getWord() << endl;
      break;
    }
  }
  return 0;
};

