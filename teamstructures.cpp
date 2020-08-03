#include <iostream>
#include <fstream>
using namespace std;

struct player {
  //char team [8];
  int number;
  string name;
  string surname;
};

player input_data (player k){
          ifstream file_we( "SK.txt" );
          file_we >> k.number>>k.name>>k.surname;
          return k;
}

void output_data (player k){
  cout<<"SK"<<" | #"<<k.number<<" "<<k.name<<" "<<k.surname;
}
//struct VisitLineup

int main() {

  player k[17];
  for (int i=0; i<17; i++){
    k[i]=input_data(k[i]);
  }

  for (int i=0; i<17; i++){
    output_data(k[i]);
    cout<<endl;
  }
}
