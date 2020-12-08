// Day3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

std::vector<string> readFile(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<string> lines;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

bool checkIfTree(std::string line, int horizontal) {
    return (line[horizontal] == '#');
}

void part2(int horizontal, int vertical) {
    //int verticalLocation = vertical;
    int horizontalLocation = 0;
    int treesHit = 0;
    vector<string> map = readFile("map.txt");
    for (int i = 0; i < map.size(); i += vertical) {        
        if (checkIfTree(map[i], horizontalLocation)) {
            treesHit += 1;
        }
        horizontalLocation = horizontalLocation + horizontal;
        int maxLineLen = map[i].size();
        if (horizontalLocation > maxLineLen - 1) {
            horizontalLocation = horizontalLocation % maxLineLen;
        }
    }
    std::cout << "Result: " << treesHit << "\n";
}

void part1() {
    int verticalLocation = 0;
    int horizontalLocation = 0;
    int treesHit = 0;
    vector<string> map = readFile("map.txt");
    //193 Part 1
    for (auto x : map) {
        if (checkIfTree(x, horizontalLocation)) {
            treesHit += 1;
        }
        horizontalLocation = horizontalLocation + 3;

        if (horizontalLocation > x.size() - 1) {
            horizontalLocation = horizontalLocation % x.size();
        }
    }
    std::cout << "Result: " << treesHit << "\n";
}
int main()
{
    //part1();
    part2(1,1);
    part2(3,1);
    part2(5,1);
    part2(7,1);
    part2(1,2);

}
