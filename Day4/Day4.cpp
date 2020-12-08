// Day4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class Passport {
public:
    string byr;
    string iyr;  
    string eyr;
    string hgt;
    string hcl;
    string ecl;
    string pid;
    string cid;
};

std::vector<string> readFile(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<string> lines;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

std::vector<string> splitStringIntoVector(std::istringstream& iss, char delim) {
std:vector<string> result;
    std::string item;
    while (std::getline(iss, item, delim)) {
        result.push_back(item);
    }
    return result;
}
string getKey(std::istringstream& iss, char delim) {
std:vector<string> result;
    std::string item;
    while (std::getline(iss, item, delim)) {
        result.push_back(item);
    }
    return result[0];
}

int main()
{
    vector<string> passports = readFile("passports.txt");
    bool byr = false;
    bool iyr = false;
    bool eyr = false;
    bool hgt = false;
    bool hcl = false;
    bool ecl = false;
    bool cid = false;
    bool pid = false;
    int validPassports = 0;
    int newlines = 0;
    for (auto& line : passports) {
        if (line != "") {
            std::istringstream iss(line);
            vector<string> props = splitStringIntoVector(iss, ' ');

            for (auto& prop : props) {
                std::istringstream iss2(prop);
                string value = getKey(iss2, ':');
                std::cout << value << "\n";
                if (value == "byr") {
                    byr = true;
                }
                else if (value == "iyr") {
                    iyr = true;
                }
                else if (value == "eyr") {
                    eyr = true;
                }
                else if (value == "hgt") {
                    hgt = true;
                }
                else if (value == "hcl") {
                    hcl = true;
                }
                else if (value == "ecl") {
                    ecl = true;
                }
                else if (value == "pid") {
                    pid = true;
                }
            }
        }
        else {
            byr = false;
            iyr = false;
            eyr = false;
            hgt = false;
            hcl = false;
            ecl = false;
            pid = false;
        }
        if (byr && eyr && hgt && hcl && ecl && pid) {
            validPassports+=1;
        }
        else {
            newlines++;
        }
    }    
    cout << validPassports;
    cout << "\n" << newlines;

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
