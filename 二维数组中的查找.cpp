//  二维数组中的查找
//
//  在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//  请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool find(int target, vector<vector<int>> array) {
    for (int i = 0, j = array[0].size() - 1; i < array.size() && j >= 0;) {
        if (target == array[i][j]) {
            return true;
        } else if (target > array[i][j]) {
            ++i;
        } else {
            --j;
        }
    }
    return false;
}

void test(bool result, string name) {
    if (result) {
        cout << name << ": 通过测试." << endl;
    } else {
        cout << name << ": 未通过测试." << endl;
    }
}

int main(int argc, char **argv) {
    vector<vector<int>> testArr = {
        { 0,  1,  3,  5 },
        { 2,  4,  6,  8 },
        { 7, 10, 13, 14 },
        { 9, 11, 15, 16 }
    };
    
    //  查找的数字在数组中
    test(find(10, testArr), "查找的数字在数组中");
    
    //  查找的数字不在数组中
    test(!find(12, testArr), "查找的数字不在数组中");
    
    //  查找的数是数组中最小的数字
    test(find(0, testArr), "查找的数是数组中最小的数字");
    
    //  查找的数是数组中最大的数字
    test(find(16, testArr), "查找的数是数组中最大的数字");
}
