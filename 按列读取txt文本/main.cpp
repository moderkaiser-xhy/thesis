#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;
void cpp_split(const std::string& s, std::vector<std::string>& v, const std::string& c)     ///c++实现split函数
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int txt_col(const std::string& file_name, const std::string& col_name, vector<float>& res){
    ifstream file;
    file.open(file_name);
    if(!file.is_open()){
        return 0;
    }
    int seq = -1;     ///提取特征的序列值
    vector<string> data;    ///按行读取txt文本
    string temp;
    string col;      ///读取第一列
    getline(file, col);
    vector<string> col_res;
    cpp_split(col, col_res, " ");
    for(int i=0; i<col_res.size(); i++){
        if(col_res[i] == col_name){
            seq = i;
            break;
        }
    }
    if(seq == -1) return -1;    ///特征名错误返回

    /***** 读取文本内容 *****/
    while(getline(file, temp)){
        data.push_back(temp);
    }
    for(auto &i: data){
        vector<string> split_str;
        cpp_split(i, split_str, " ");
        res.push_back(atof(split_str[seq].c_str()));
    }
    return 1;
}
int main() {
    vector<float> res;
    txt_col("../test.txt", "abc", res);
    for(auto &i: res){
        cout << i << endl;
    }
    return 1;
}
