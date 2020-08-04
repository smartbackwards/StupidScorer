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
	cout << k.number << " " << k.name << " " << k.surname;
}
//structure of the team data
struct Team {
	Player k[28];
	Team(string Filename) {
		Filename += ".txt";
		ifstream input_file(Filename);
		Player player;
		int i = 0;
		while (input_file >> player.number >> player.name >> player.surname) {
			k[i] = player;
			i++;
		}
	}
};
//outputs the data of a player with a given number
void output_number(Team homawa, int jernumber) {
	Player n;
	for (int i = 0; i < 28; i++) {
		if (homawa.k[i].number == jernumber) {
			n = homawa.k[i];
			output_data(n);
		}
	}
}
//outputs away team's roster
void away_team_roster(Team away, string teamname) {
	cout << endl << teamname << " player list: " << endl << "================================" << endl;
	for (int i = 0; i < 28; i++) {
		cout << teamname << " | #";
		output_data(away.k[i]);
		cout << endl;
	}
}

void home_team_roster(Team home, string teamname) {
	cout << endl << teamname << " player list: " << endl << "================================" << endl;
	for (int i = 0; i < 28; i++) {
		cout << teamname << " | #";
		output_data(home.k[i]);
		cout << endl;
	}
}

int main() {

	string home_name, away_name;
	cout << "Name the file with the away team: ";
	cin >> away_name;

	cout << "Name the file with the home team: ";
	cin >> home_name;

	Team AWAY = Team(away_name);

	Team HOME = Team(home_name);

	away_team_roster(AWAY, away_name);
	home_team_roster(HOME, home_name);

	output_number(HOME, 27);


}
