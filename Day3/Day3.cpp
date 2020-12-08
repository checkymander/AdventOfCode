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
    std::cout << horizontal << "\n";
    return (line[horizontal] == '#');
}


int main()
{
    int verticalLocation = 0;
    int horizontalLocation = 0;
    int treesHit = 0;
    vector<string> map = readFile("map.txt");
    std::cout << "Map Size: " << map.size() << "\n";
    //193
    for (auto x : map) {
        if (checkIfTree(x, horizontalLocation)) {
            treesHit += 1;
        }
        horizontalLocation = horizontalLocation + 3;
        if (horizontalLocation > x.size()-1) {
            horizontalLocation = horizontalLocation % x.size();
        }
    }
        std::cout << "Result: " << treesHit;
}
