#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class Type>
Type string_to_num(const string& str)
{
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}


float get_val(std::string &ori_str, std::string find_word) {
    auto ret = std::string::npos;
    if((ret = ori_str.find(find_word)) != std::string::npos) {
        // std::cout << "ret is " << ret << std::endl;
        int flag = 0;
        int lstr, rstr;

        for(int i = ret; i < ori_str.size(); ++i) {
            if(flag == 1) {
                if(ori_str[i] != '.' && ori_str[i] <= '0' || ori_str[i] >= '9') {
                    rstr = i;
                    // cout << "rstr is " << rstr << endl;
                    break;
                } 
            } else {
                if(ori_str[i] >= '0' && ori_str[i] <= '9') {
                    // std::cout << "ori_str[" << i << "]" << " is " << ori_str[i] << std::endl;
                    flag = 1;
                    lstr = i;
                } else if(ori_str[i] == ',' || ori_str[i] == '}') {
                    return -1.0;
                }
            }
        }

        // std::string str_val = ori_str.substr(lstr, rstr - lstr);
        // std::cout << "str_val is " << str_val << std::endl;

        return string_to_num<float>(ori_str.substr(lstr, rstr - lstr));
    }
    return -1.0;
}

int main() {
    string str = "123";
    int i;

    i = stoi(str);
    cout << "str: " << str << endl;
    cout << "i: " << i << endl;

    char c = '3';
    int ret = -1;
    if((ret = str.find(c)) != string::npos) {
        cout << "Found!" << " ret = " << ret << endl;
    }

    string str_row = "{\"X\":\"0\",\"Y\":\"0\",\"Z\":\"0\"}";
    cout << str_row << endl;
    cout << "X: " << get_val(str_row, "X") << endl;
    cout << "Y: " << get_val(str_row, "Y") << endl;
    cout << "Z: " << get_val(str_row, "Z") << endl;

    return 0;
}