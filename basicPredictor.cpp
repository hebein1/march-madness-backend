#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string team1;
	string team2;
	cout << "Input team 1:\n";
	cin >> team1;
	cout << "Input team 2:\n";
	cin >> team2;

	if(team1.length() < team2.length())
		cout << team2 + " wins\n";
	else
		cout << team1 + " wins\n";
}
