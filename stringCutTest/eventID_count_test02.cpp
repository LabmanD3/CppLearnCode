/**
 * 	将所有不重复的ID存入另一个文件中
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

/* 用数组的方法去重 */
/*
int main(int argc, char* argv[]){

	std::string file_name = argv[1];
	std::ifstream log_file(file_name);
	std::string str;
	int count = 0;
	int ret = 0;
	std::string p = "EventID";
	std::vector<std::string> vec;

	while(!log_file.eof()) {
		getline(log_file, str);
		while((ret=str.find(p,ret+1)) != std::string::npos) {
			std::string s =  str.substr(ret + 9, 18);
            // std::cout << "ID is " << s << std::endl;
			vec.push_back(s);
            // 排序
            sort(vec.begin(), vec.end());
            // unique重排输入范围，使得每个单词只出现一次
            auto end_unique = unique(vec.begin(), vec.end());
            // 删除重复ID
            vec.erase(end_unique, vec.end());
			count++;
			ret=ret+p.length();
            s.clear();
		}
		str.clear();
	}
	std::cout << "count = " << count << std::endl;
    for(auto &i : vec) {
        std::cout << i << std::endl;
    }
    
    std::ofstream outfile;
    outfile.open("ID.log", std::ios::out | std::ios::trunc );
    for(auto &i : vec) {
        outfile << i << std::endl;
    }

	return 0;
}
*/

int main(int argc, char* argv[]){

	std::string file_name = argv[1];
	std::ifstream log_file(file_name);
	std::ofstream outfile;
    outfile.open("ID.log", std::ios::out | std::ios::trunc );
	
	int count = 0, ret = 0, i = 0;
	std::string str;
	std::string find_word = "EventID";
	std::map<std::string, int> smp;
	
	while(!log_file.eof()){
		getline(log_file, str);
		while((ret=str.find(find_word, ret+1)) != std::string::npos)
		{
			std::string s =  str.substr(ret + 10, 16);
			auto newid = smp.insert(std::pair<std::string, int> (s, i++));
			count++;
			ret=ret+find_word.length();
		}
		str.clear();
	}
	std::cout << "count = " << count << std::endl;

    for(auto &i : smp) {
        outfile << i.first << " " << i.second << std::endl;
    }

	return 0;
}