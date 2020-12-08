// Day4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <regex>

using namespace std;


bool isValidBirthYear(int year) {
    return (year >= 1920 && year <= 2002);
}

bool isValidIssueYear(int year){
    return (year >= 2010 && year <= 2020);
}
bool isValidExpirationYear(int year) {
    return (year >= 2020 && year <= 2030);
}
bool isValidHeight(std::string height) {
    try {
        int val;
        string heightString;
        if (height.substr(height.length() - 2) == "cm") {
            //3 characters for height
            heightString = height.substr(0, 3);
            val = atoi(heightString.c_str());
            return (val >= 150 && val <= 193);
        }
        else if (height.substr(height.length() - 2) == "in") {
            //2 characters for inches
            heightString = height.substr(0,2);
            val = atoi(heightString.c_str());
            return (val >= 59 && val <= 76);
        }
        else {
            return false;
        }
    }
    catch(int e)
    {
        return false;
    }
}
bool isValidHairColor(std::string color) {
    return regex_match(color, regex("^(#)([a-f0-9]){6}"));
}
bool isValidEyeColor(std::string color) {
    return regex_match(color, regex("(amb|blu|brn|gry|grn|hzl|oth)"));
}
bool isValidPassportId(std::string ID) {
    return regex_match(ID, regex("^\\d{9}$"));
}

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
string getValue(std::string &s, char delim) {
    std::string token = s.substr(s.find(delim) + 1, s.length());
    return token;
}

int main()
{
    vector<string> passports = readFile("passports.txt");
    int validPassports = 0;
    int newlines = 0;
    bool byr = false;
    bool iyr = false;
    bool eyr = false;
    bool hgt = false;
    bool hcl = false;
    bool ecl = false;
    bool cid = false;
    bool pid = false;

    for (auto& line : passports) {
        if (line != "") {
            std::istringstream iss(line);
            vector<string> props = splitStringIntoVector(iss, ' ');
            for (auto& prop : props) {
                std::istringstream iss2(prop);
                string value = getKey(iss2, ':');
                if (value == "byr") {
                    byr = isValidBirthYear(atoi(getValue(prop,':').c_str()));
                }
                else if (value == "iyr") {
                    iyr = isValidIssueYear(atoi(getValue(prop, ':').c_str()));
                }
                else if (value == "eyr") {
                    eyr =  isValidExpirationYear(atoi(getValue(prop, ':').c_str()));
                }
                else if (value == "hgt") {
                    hgt = isValidHeight(getValue(prop,':'));
                }
                else if (value == "hcl") {
                    hcl = isValidHairColor(getValue(prop, ':'));
                }
                else if (value == "ecl") {
                    ecl = isValidEyeColor(getValue(prop, ':'));
                }
                else if (value == "pid") {
                    pid = isValidPassportId(getValue(prop, ':'));
                }
            }
        }
        else {
            if (byr && iyr && eyr && hgt && hcl && ecl && pid) {
                validPassports++;
            }

            byr = false;
            iyr = false;
            eyr = false;
            hgt = false;
            hcl = false;
            ecl = false;
            pid = false;
        }
    }   
    if (byr && iyr && eyr && hgt && hcl && ecl && pid) {
        validPassports++;
    }
    std::cout << "Valid Passports: " << validPassports;

}