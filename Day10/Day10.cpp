// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;
std::vector<int> readFile(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<int> lines;

    while (getline(file, line)) {
        lines.push_back(atoi(line.c_str()));
    }
    return lines;
}

int main()
{
    std::vector<int> nums = readFile("Day10.txt");
    int oneJolt = 0;
    int threeJoly = 0;
    int prevNum = 0;
    std::sort(nums.begin(), nums.end());
    for (auto x : nums) {
        std::cout << (x - prevNum) << "\n";


        prevNum = x;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
