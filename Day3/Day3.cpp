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

bool checkValue(int vertical, int horizontal, std::vector<string> map) {
    if (map[vertical][horizontal] == '#') {
        //std::cout << "(" << vertical << "," << horizontal << ")" << " - " << map[vertical][horizontal] << "\n";
        return true;
    }
}


int main()
{
    int verticalLocation = 0;
    int horizontalLocation = 0;
    int treesHit = 0;
    vector<string> map = readFile("map.txt");
    while (verticalLocation != map.size()) {
        std::cout << "(" << verticalLocation << "," << map.size() << ")\n";
        if (checkValue(verticalLocation, horizontalLocation, map)) {
            treesHit++;
        }
         verticalLocation++;
         horizontalLocation += 3;

        if (horizontalLocation > 30) {
            horizontalLocation = horizontalLocation % 30;
        }
    }
    
        std::cout << treesHit;
    //Step 1: Keep track of what line in the text file you are.
        //Step 1a: Maybe store the entire thing in a vector, wich each line being it's own item.
    //Step 2: Keep track of horizontal position (Position 0 to Position 30)
    //Step 3: If current position is greater than 30, loop back to 0 and continue from there
    //Step 4: Calculate what line you're on vs what horizontal position you have to determine whether that item is a "." or a "#"
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
