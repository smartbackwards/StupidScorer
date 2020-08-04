#include <fstream>
#include <iostream>
using namespace std;
//structure of the player data
struct Player {
	int number;
	string name;
	string surname;
	string position;
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
void team_roster(Team homeaway, string teamname) {
	cout << endl << teamname << " player list: " << endl << "================================" << endl;
	for (int i = 0; i < 28; i++) {
		cout << teamname << " | #";
		output_data(homeaway.k[i]);
		cout << endl;
	}
}

void position_implementer (string positionname, string positionshort, Team homawa, string teamname){
	int positionnumber;
	int helper = 0;
		tryagain:
	cout << "Type in the number of the " << positionname << ": ";
		cin >> positionnumber;
	for (int i = 0; i < 28; i++) {
		if (homawa.k[i].number == positionnumber) {
			homawa.k[i].position = positionshort;
			cout << homawa.k[i].name << " " << homawa.k[i].surname << " is now the " << teamname << " " << positionname << "!" << endl;
			helper = 1;
		}
	}
	if (helper == 0) {
				cout << "There is no player on the roster with that number. Try again!" <<endl;
				goto tryagain;
	}
}
void defense_maker(Team homawa, string teamname){
	team_roster(homawa, teamname);
	position_implementer ("pitcher", "P", homawa, teamname);
	position_implementer ("catcher", "C", homawa, teamname);
	position_implementer ("first baseman", "1B", homawa, teamname);
	position_implementer ("second baseman", "2B", homawa, teamname);
	position_implementer ("third baseman", "3B", homawa, teamname);
	position_implementer ("shortstop", "SS", homawa, teamname);
	position_implementer ("left fielder", "LF", homawa, teamname);
	position_implementer ("center fielder", "CF", homawa, teamname);
	position_implementer ("right fielder", "RF", homawa, teamname);
}

int main() {

	string home_name, away_name;
	cout << "Name the file with the away team: ";
	cin >> away_name;

	cout << "Name the file with the home team: ";
	cin >> home_name;

	Team AWAY = Team(away_name);

	Team HOME = Team(home_name);

//    team_roster(AWAY, away_name);
//	home_team_roster(HOME, home_name);

//	output_number(HOME, 27);
	defense_maker(AWAY, away_name);
	defense_maker(HOME, home_name);
}
