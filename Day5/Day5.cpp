// Day5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tgmath.h>
#include <algorithm>


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

int findMidPoint(int x1, int x2) {
    int midpoint = round((x1 + x2) / 2);
    return midpoint;

}

int translateBSP(std::string value) {
    //First 7 characters [0]..[6] will either be B or F
    // B = Upper Half
    // F = Lower Half
    // Total number of rows on the plane are 128 (0-127)
    //Each letter tells you which half of a region the given set is in
    // The first letter indicates whether the seat is in the front (0-63) or the back (64-127)
    // The next letter indicates which half of the previously set region the seat is in, and it continues until you run out of letters
    int rowMaxVal = 128;
    int rowMinVal = 1;
    int seatMinVal = 1;
    int seatMaxVal = 8;
    int rowVal = 0;
    int seatVal = 0;
    // maxVal/2 = midpoint
    // if upper
    // minVal = midpoint
    // maxVal = maxVal
    // if lower
    // minVal = minVal
    // maxVal = midpoint
    for (auto x : value) {
        switch (x) {
        case 'F':
            rowMaxVal = findMidPoint(rowMaxVal, rowMinVal);
            break;
        case 'B':
            rowMinVal = findMidPoint(rowMaxVal, rowMinVal);
            break;
        case 'R':
            seatMinVal = findMidPoint(seatMaxVal, seatMinVal);
            break;
        case 'L':
            seatMaxVal = findMidPoint(seatMaxVal, seatMinVal);
            break;
        }
    }
    switch (value[6]) {
    case 'F':
        rowVal = rowMinVal;
        break;
    case 'B':
        rowVal = rowMaxVal;
        break;
    }
    std::cout << value[9] << "\n";
    switch (value[9]) {
    case 'R':
        seatVal = seatMinVal;
        break;
    case 'L':
        seatVal = seatMaxVal;
        break;
    }
    std::cout << "[DEBUG]: " << "Val: " << seatVal << " Min: " << seatMinVal << " Max: " << seatMaxVal << "\n";
    std::cout << "Row: " << rowVal << "  Column:" << seatVal << " ID: " << ((rowVal * 8) + seatVal) << "\n";

    return ((rowVal * 8) + seatVal);
}


int main()
{
    vector<string> bsps = readFile("bsp.txt");
    int maxVal = 0;

    int total = 0;
    for (auto x : bsps) {
        int curVal = translateBSP(x);

        if (curVal > maxVal){
            maxVal = curVal;
        }
        total += curVal;
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
