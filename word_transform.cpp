#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::map<std::string, std::string> buildMap(std::ifstream &map_file) {
    std::map<std::string, std::string> trans_map;       // 保存转换规则
    std::string key;            // 要转换的单词
    std::string value;          // 替换后的内容
    // 读取第一个单词存入key中， 行中剩余内容存入value
    while(map_file >> key && getline(map_file, value)) {
        if(value.size() > 1)            // 检查是否有转换规则
            trans_map[key] = value.substr(1);       // 跳过前导空格
        else 
            throw std::runtime_error("no rule for " + key);
    }
    return trans_map;
}

const std::string &
    transform(const std::string &s, const std::map<std::string, std::string> &m) {
    // 实际的转换工作； 此部分是程序的核心
    auto map_it = m.find(s);
    // 如果单词在转换规则map中
    return map_it == m.cend()? s: map_it->second;
} 

void word_transform(std::ifstream &map_file, std::ifstream &input) {
    auto trans_map = buildMap(map_file);    // 保存转换规则
    std::string text;                       // 保存输入中的每一行
    while (getline(input, text)) {          // 读取一行输入
        std::istringstream stream(text);    // 读取每个单词
        std::string word;
        bool firstword = true;              // 控制每个单词前是否打印空格，首单词除外
        while(stream >> word) {
            if(firstword)
                firstword = false;
            else
                std::cout << " ";           // 在单词间打印一个空格
            // transform返回它的第一个参数或其转换之后的形式
            std::cout << transform(word, trans_map);    // 打印输出            
        }
        std::cout << std::endl;             // 完成一行的转换
    }
}

int main(int argc, char const *argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] 
                  << " [trans_rules-file]" << " [trans_input-file]" 
                  << std::endl; 
        exit(1);
    }

    std::ifstream trans_rules(argv[1]);
    std::ifstream trans_input(argv[2]);
    
    if(trans_rules && trans_input)
        word_transform(trans_rules, trans_input);
    else
        std::cerr << "Can't find the documents." << std::endl;

    return 0;
}