/**
 *	找出文件中某一单词出现的次数 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, const char* argv[]){

	std::string file_name = argv[1];
	std::string find_word = argv[2];

	std::ifstream log_file(file_name);
    // std::ifstream log_file("2020-09-09.log");
	std::string str;
	int sum = 0;
    auto ret = 0;
	
	while(!log_file.eof()){
		getline(log_file, str);

		while((ret = str.find(find_word, ret)) != std::string::npos){
            if(str.find(find_word) != std::string::npos) {
                sum++;
            }
            ret = ret + find_word.size();
		};
		ret = 0;
		str.clear();
	}
	std::cout << "Sum = " << sum << std::endl;

	return 0;
}