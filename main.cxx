#include "musicmember.h"


using namespace std;

vector<Musicmember> musiclist;

int main(int argc, char* argv[]){
  int status = 1;
  string input = "";
  cout << "Welcome to the musiclist program!" << endl;
  while(status){
    cout << "Please choose what you want to do:" << endl;
    cout << "Type help for help, or any other command you wish to execute." << endl << endl;
    getline(cin, input);
    if(input == "exit" || input == "Exit"){
      break;
    }
    if(input == "help" || input == "Help"){
      print_commands();
    }
    if(input == "creat list" || input == "new list"){
      new_list();
    }
  }
  return 0;
}
