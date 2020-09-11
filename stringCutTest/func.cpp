#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <sys/types.h>      // Linux
#include <sys/stat.h>       
#include <dirent.h>
#include <stdio.h>

#define  SORT_ID_FOLDER "./Sort_ID/"

template <class Type>
Type string_to_num(const std::string& str)
{
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

void init_dir() {
    DIR *pDir = nullptr;
    struct dirent *sdir = nullptr;

    if(!(pDir = opendir(SORT_ID_FOLDER))) {
        std::cout << "Open dir failed !" << std::endl;
        exit(1);
    }

    while(sdir = readdir(pDir)) {
        // std::cout << sdir->d_name << " d_type is " << (int)sdir->d_type << "." << std::endl;
        if(sdir->d_type == 8) {
            std::string remove_file = SORT_ID_FOLDER;
            remove_file += sdir->d_name;
            if(remove(remove_file.c_str()) == 0) {
                // std::cout << "remove should be done." << std::endl;
            }
        }
    }

    closedir(pDir);
    pDir = nullptr;
}

float get_val(const std::string &ori_str, std::string find_word) {
    auto ret = std::string::npos;
    if((ret = ori_str.find(find_word)) != std::string::npos) {
        int flag = 0;
        int lstr, rstr;

        for(int i = ret; i < ori_str.size(); ++i) {
            if(flag == 1) {
                if(ori_str[i] != '.' && ori_str[i] <= '0' || ori_str[i] >= '9') {
                    rstr = i;
                    break;
                }    
            } else {
                if(ori_str[i] >= '0' && ori_str[i] <= '9') {
                    flag = 1;
                    lstr = i;
                } else if(ori_str[i] == ',' || ori_str[i] == '}') {
                    return -1.0;
                }
            }
        }

        return string_to_num<float>(ori_str.substr(lstr, rstr - lstr));
    }
    return -1.0;
}

std::string get_eventID(const std::string &ori_str, std::size_t &pos) {
    std::string str_id;
    std::string word_id = "EventID";

    if((pos = ori_str.find(word_id, pos + 1)) != std::string::npos) {
        str_id = ori_str.substr(pos + 10, 16);
    }
    
    return str_id;
}

std::string cut_xyz_string(const std::string &ori_str) {

}


int main(int argc, char const *argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [log-file]" << std::endl; 
        // fprintf(stderr,"Usage: %s [log-file] \n",argv[0]);
        exit(1);
    }

    if(mkdir(SORT_ID_FOLDER, 0777)) {
        // 创建失败 or 已存在
        // std::cout << "mkdir failed !" << std::endl;
        // exit(1);
        init_dir();
    }

    std::string file_name = argv[1];
    std::ifstream log_file(file_name);
    std::string str_row;
    std::string word_x = "{\"X\"";
    std::string word_evntid = "EventID";
    int ret = -1, lstr = -1, rstr = -1;

    std::vector<std::string> vstr;
    
    while(!log_file.eof()) {
        getline(log_file, str_row);

        while((ret = str_row.find(word_evntid, ret + 1)) != std::string::npos) {
            std::ofstream out_file;
            std::string str_id = str_row.substr(ret + 10, 16);
            // std::cout << str_id << std::endl;

            if((ret = str_row.find(word_x, ret + 1)) != std::string::npos) {
                // std::cout << "find word! " << "ret = " << ret << std::endl;
                lstr = ret;
                ret += word_x.length();
                
                if((ret = str_row.find("}", ret + 1)) != std::string::npos) {
                    // std::cout << "find } " << "ret = " << ret << std::endl;
                    ret++;
                    rstr = ret;
                }
                out_file.open(SORT_ID_FOLDER + str_id, std::ios::app);
                out_file << str_row.substr(lstr, rstr - lstr) << std::endl;

            }
            ret += word_evntid.length();
            
            
        }
        
    }
    

    return 0;
}