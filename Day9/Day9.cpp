// Day9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>


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


bool part2() {
    bool match = false;
    std::vector<int> nums = readFile("Day9.txt");
    int start = 0;
    long sum_of_elems = 0;
    int curNum = 1124361034;
    for (int start = 0; start < nums.size() - 1; start++){
        for(int end = 0; end < nums.size() - 1; end ++)
        {
            for (int i = start; i < end +1; i++) {
                sum_of_elems += nums[i];
            }
            if (sum_of_elems == curNum) {
                std::cout << "Found Range: " << start << " " << end << "\n";
                return true;
            }
            sum_of_elems = 0;
        }
        sum_of_elems = 0;
    }
    return false;
}




int main()
{
    std::vector<int> nums = readFile("Day9.txt");
    int curNum = 0;
    int i = 26;
    while (i < nums.size() - 1) {
        bool match = false;

        curNum = nums[i];
        for (int f = i - 26; f != i; f++) {
            if (match) {
                break;
            }
           for(int g = i-26; g != i; g++) {
                if (match) {
                    break;
                }
                if (nums[g] + nums[f] == curNum) {
                    match = true;
                }
            }
        }
        if (!match) {
            std::cout << curNum << "\n";
            break;
        }
        i++;
    }
    int r = 0;
    std::cout << "Starting Part2\n";
    part2();


    //1124361034
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
