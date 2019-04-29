#include "Guesser.hpp"
#include "calculate.hpp"
#include <vector>
using std::vector;
using bullpgia::Guesser;

namespace bullpgia{

class SmartGuesser:public Guesser{
private:
unsigned int length;//the length
vector<int> guesses;//the guesses that has been tryed
public:
string guess()override;//function to guess 
void startNewGame(uint length)override;//start new game by int length
void learn(string answers)override;//learn data

};//end SmartGuesser

};//end bullpgia
