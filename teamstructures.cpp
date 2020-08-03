#include <fstream>
#include <iostream>
using namespace std;

struct Player {
    // char team [8];
    int number;
    string name;
    string surname;
};

void output_data(Player k) {
    cout << "SK"
         << " | #" << k.number << " " << k.name << " " << k.surname;
}
// struct VisitLineup

int main() {
    Player k[17];

    ifstream input_file("SK.txt");

    Player player;
    int i = 0;
    while (input_file >> player.number >> player.name >> player.surname) {
        k[i] = player;
        i++;
    }

    for (int i = 0; i < 17; i++) {
        output_data(k[i]);
        cout << endl;
    }
}
