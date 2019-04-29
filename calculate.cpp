#include "calculate.hpp"
#include <string>
#include <sstream>
using namespace std;
using std::string;
using std::to_string;


// calculateBullAndPgia
string bullpgia::calculateBullAndPgia(string str,string guess){
unsigned int length=str.size();
int bull=0;
int pgia=0;
//parse str (the answer that we try to guess) and insert into "secret"
stringstream geek(str);
uint secret=0;
geek>>secret;
//secret hold the int number of str


//pastr guess that is the guess of the secret  and insert to "secretGuess"
stringstream geek2(guess);
uint secretGuess=0;
geek2>>secretGuess;
//secretGuess hold the int number of guess
if(secretGuess == secret)
    {
        return to_string(length)+","+to_string(0);
    }
//check bull , pgia
int choosen=secret;
int guessing=secretGuess;
int secretArray[length];
int secretGuessArray[length];


for(int i=length-1;i>=0;i--){
secretArray[i]=choosen%10;
choosen=choosen/10;
secretGuessArray[i]=guessing%10;
guessing=guessing/10;
}

int help[length];
int help2[length];
for(int i=0;i<length;i++){help[i]=0;help2[i]=0;}

//initialize helper 
for(int i=0;i<length;i++){
if(secretArray[i]==secretGuessArray[i]){help[i]=1;}//fill the help array, and count bull because its easy, bull=1
if(secretArray[i]==secretGuessArray[i]){help2[i]=1;}//fill the help array2, and count bull because its easy, bull=1
}

for(int i=0;i<length;i++){
for(int j=0;j<length;j++){
if((secretGuessArray[i]==secretArray[j])&&(help[i]==0)){help[i]=2;}
}//end j
}//end i

for(int i=0;i<length;i++){
if(help[i]==2){pgia++;}
if(help[i]==1){bull++;}
}

for(int i=0;i<length;i++){
for(int j=0;j<length;j++){
if((secretGuessArray[j]==secretArray[i])&&(help2[i]==0)){help2[i]=2;}
}//end j
}//end i
int pgia2=0;

for(int i=0;i<length;i++){
if(help2[i]==2){pgia2++;}

}
int ans1=pgia;

if(ans1>pgia2){ans1=pgia2;}


string ans=to_string(bull)+","+to_string(ans1);
return ans;
}//end calculateBullAndPgia
