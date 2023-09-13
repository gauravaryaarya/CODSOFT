#include <iostream>
using namespace std;

int numbergenerator(){
srand(static_cast<unsigned>(time(nullptr)));

int unkownnum= rand()%10 + 1;
return unkownnum;
}

int main() {
  int unkownnum,guess;
  unkownnum=numbergenerator();

  while(true){
    cout<<"Guess a Number Between 1 to 10"<<endl;
    cin>>guess;
    
    if(guess>unkownnum){
      cout<<"High Value"<<endl;
      }

    else if (guess<unkownnum){
      cout<<"low value"<<endl;
    }

    else{
      cout<<"You Guessed it right"<<endl;
      break;
    }
  }

  return 0; 
}