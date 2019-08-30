#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	ifstream input_file("credit_users.txt");

	string user;
	string row;
	bool odd = true;
	bool error = false;
	
	while(getline(input_file, row)) {
		if (odd) {
			istringstream stream_row(row);

			getline(stream_row, user, ':');
			
			odd = false;
		}
		else {
			user.append(".yml");
			ofstream output_file(user.c_str());

			if (output_file.is_open()) {
				output_file<<row<<endl;
				output_file<<"CreditsSpent: 0"<<endl;

				cout<<user<<endl;
				cout<<row<<endl;
			}
			else {
				cout<<endl<<endl<<"Unable to output file.";
				error = true;
				break;
			}

			output_file.close();
			odd = true;
		}
		
	}
	if (!error) {
		cout<<endl<<endl<<"Credit Users exported to yaml from text file.";
	}

	input_file.close();
}
