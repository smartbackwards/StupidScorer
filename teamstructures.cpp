#include <fstream>
#include <iostream>
using namespace std;
//structure of the player data
struct Player {
    int number;
    string name;
    string surname;
};
//function that outputs the data of a player
void output_data(Player k) {
    cout << " | #" << k.number << " " << k.name << " " << k.surname;
}
//structure of the team data
struct Team {
  Player k[28];
  Team(string Filename){
    Filename += ".txt";
    ifstream input_file (Filename);
    Player player;
    int i = 0;
    while (input_file >> player.number >> player.name >> player.surname) {
        k[i] = player;
        i++;
    }
  }
};

int main() {

string home_name, away_name;
cout<<"Name the file with the away team: ";
cin>>away_name;

cout<<"Name the file with the home team: ";
cin>>home_name;

Team AWAY = Team (away_name);

Team HOME = Team (home_name);

cout<<endl<<"Away team player list: "<<endl<<"================================"<<endl;
    for (int i = 0; i < 28; i++) {
        cout << away_name;
        output_data(AWAY.k[i]);
        cout << endl;
    }
cout<<endl<<"Home team player list: "<<endl<<"================================"<<endl;
  for (int i = 0; i < 28; i++) {
      cout << home_name;
      output_data(HOME.k[i]);
      cout << endl;
  }
}
