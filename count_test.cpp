#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string findWord = "EventID";

int main(int argc, char* argv[]){

	//std::string file_name = argv[1];
	std::ifstream log_file("2020-09-09zujian.log");
    // std::ifstream log_file("2020-09-09.log");
	std::string str;
	int sum = 0;
	int row = 0;
    auto ret = string::npos;
	while(getline(log_file, str)){
        // cout << str << endl;
        // string::size_type start = 0;
		string::size_type end = str.size();

        int count = 0;
		while((ret = str.find(findWord, ret+1)) != string::npos){
            // cout << "~~~" << endl;
            if(str.find(findWord) != string::npos) {
                sum++;
            }
            ret = ret + findWord.size();
			
            
            // cout << "ret --->" << ret << endl;
		};
		ret = string::npos;
		str.clear();

        // cout << "---------------------" << endl;
	}
	std::cout << "Sum = " << sum << std::endl;
	// std::cout << i << std::endl;
	return 0;
}