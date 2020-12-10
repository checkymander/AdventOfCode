// Day6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tgmath.h>
#include <algorithm>
#include <ctype.h>
#include <set>
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

//Stolen and modified from here: https://www.geeksforgeeks.org/common-characters-n-strings/
int commonCharacters(vector<string> str)
{
    // primary array for common characters  
    // we assume all characters are seen before. 
    bool prim[26];
    memset(prim, true, sizeof(prim));

    for (auto x : str) {
        bool sec[26] = { false };

        for (auto z : x) {
            if (prim[z - 'a'])
                sec[z - 'a'] = true;
        }
        // copy whole secondary array into primary 
        memcpy(prim, sec, 26);
    }
    int characters = 0;
    // displaying common characters 
    for (int i = 0; i < 26; i++)
        if (prim[i])
            characters++;

    return characters;
}

int main()
{
    std::vector<string> answers = readFile("customs.txt");
    std::vector<char> affirms;
    std::vector<string> linechecks;
    int total = 0;
    int curGroup = 0;
    for (auto& line : answers) {
        if (line != "") {
            linechecks.push_back(line);
        }
        else{ 
            total += commonCharacters(linechecks);
        linechecks.clear();
        }
    }
    total += commonCharacters(linechecks);
    std::cout << total << "\n";
}