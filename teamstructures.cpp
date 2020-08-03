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
  Team(){
    ifstream input_file ("SK.txt");
    Player player;
    int i = 0;
    while (input_file >> player.number >> player.name >> player.surname) {
        k[i] = player;
        i++;
    }
  }
};

int main() {

Team SK;

    for (int i = 0; i < 28; i++) {
        output_data(SK.k[i]);
        cout << endl;
    }
}
