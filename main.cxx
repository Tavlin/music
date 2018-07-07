#include "musicmember.h"


using namespace std;

vector<Musicmember> musiclist;

int main(int argc, char* argv[]){
  int status = 1;
  string input = "";
  cout << "Welcome to the musiclist program!" << endl;
  while(status){
    cout << "Please choose what you want to do:" << endl;
    cout << "Type help for help, or any other command you which to execute." << endl << endl;
    cin >> input;
    cout << endl << "You chose: " << input << " as input" << endl << endl;
    if(input == "exit" || input == "Exit"){
      break;
    }
    if(input == "help" || input == "Help"){
      print_commands();
    }
    else{
      cout << "What oO? Please check your input and try again." << endl;
    }
  }
  return 0;
}
