#include<iostream>
using namespace std;

int main(){
  float a,b;
  cout<<"Enter 2 numbers to be Added,Subtracted,Multiplied Or Divided"<<endl;
  cin>>a>>b;

  char c;
  cout<<"Provide the operation to be performed(+,-,*,/)"<<endl;
  cin>>c;

  switch(c){
    case '+':{
      cout<<a+b<<endl;
      break;
    }
    case '-':{
      cout<<a-b<<endl;
      break;
    }
    case '*':{
      cout<<a*b<<endl;
      break;
    }
    case '/':{
      cout<<a/b<<endl;
      break;
    }
    default:{
      cout<<"wrong operation selected"<<endl;
    }
    
        
  }
  
  return 0;
}