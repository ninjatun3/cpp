#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <filesystem>

using namespace std;



int main() {
	filesystem::current_path("/home/user/codelite_project/cpp_projects/log_reader/log_files");
	cout << "workdir " << filesystem::current_path() << "\n";
	
	
	// string line;
	
	ifstream in("20241028_111041_412.log");
	
/*	if (in.is_open()) {
		cout << "file successfully opened";
		while (getline(in, line)) {
			//cout << line << "\n";
			if (line.find("[dbg]") != string::npos) {
				cout << "debug: " << line << "\n";
			}
		}
	} else {
		cout << "file open error";
	}
*/	

	string_view line;
	
	if (in.is_open()) {
		cout << "file successfully opened";
		while (readline(in, line)) {
			//cout << line << "\n";
			if (line.find("[dbg]") != string::npos) {
				cout << "debug: " << line << "\n";
			}
		}
	} else {
		cout << "file open error";
	}
	
	in.close();
	
	cout << "\n";
	return 0;
}
