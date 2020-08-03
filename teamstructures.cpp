#include <fstream>
#include <iostream>
using namespace std;

struct Player {
    int number;
    string name;
    string surname;
};

void output_data(Player k) {
    cout << "SK"
         << " | #" << k.number << " " << k.name << " " << k.surname;
}

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

string nazwa;
cout<<"Name the file with the home team: ";
cin>>nazwa;

Team HOME = Team (nazwa);

    for (int i = 0; i < 28; i++) {
        output_data(HOME.k[i]);
        cout << endl;
    }
}
