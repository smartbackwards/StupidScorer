#include <iostream>
using namespace std;

struct player {
  char team [8];
  int number;
  string name;
  string surname;
};

player input_data (player k){
  cout<<"please input the data for the player"<<endl<<"team: ";
  cin>> k.team;
  cout<<endl<<"player's number: ";
  cin>> k.number;
  cout<<endl<<"player's name: ";
  cin>> k.name;
  cout<<endl<<"player's surname: ";
  cin>> k.surname;
  return k;
}

void output_data (player k){
  cout<<k.team<<" | #"<<k.number<<" "<<k.name<<" "<<k.surname;
}
//struct VisitLineup

int main(int argc, char *argv[]) {
  player k[3];
  for (int i=0; i<3; i++){
    k[i]=input_data(k[i]);
  }

  for (int i=0; i<3; i++){
    output_data(k[i]);
    cout<<endl;
  }
}
