#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
using namespace std; // I don't like this

template<typename Out>
void split(const string &s, char delim, Out result) { // this is pasted thanks to stackoverflow
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

void challangeOne(vector<string> input) {
    int num = 0;
    for (vector<string>::const_iterator i = input.begin(); i != input.end(); i++) {
        string tosplit = *i;
        vector<string> check = split(tosplit, ' ');
        bool dupe = false;
        for (vector<string>::const_iterator x = check.begin(); x != check.end(); x++) {
            string target = *x;
            for (vector<string>::const_iterator y = check.begin(); y != check.end(); y++) {
                string oldTarget = *y;
                if(x != y) {
                    if (target == oldTarget) {
                        dupe = true;
                        break;
                    }
                }
            }
        }
        if (!dupe)
            num++;
    }
    cout << "Number of valid passphrases for puzzle A: " << num << endl;
}

void challangeTwo(vector<string> input) {
    int num = 0;
    for (vector<string>::const_iterator i = input.begin(); i != input.end(); i++) {
        string tosplit = *i;
        vector<string> check = split(tosplit, ' ');
        bool dupe = false;
        for (vector<string>::const_iterator x = check.begin(); x != check.end(); x++) {
            string target = *x;
            for (vector<string>::const_iterator y = check.begin(); y != check.end(); y++) {
                string currentTarget = target, oldTarget = *y;
                sort(oldTarget.begin(), oldTarget.end()), sort(currentTarget.begin(), currentTarget.end());
                if(x != y) {
                    if (currentTarget.substr(0, oldTarget.length()) == oldTarget && oldTarget.substr(0, currentTarget.length()) == currentTarget) {
                        dupe = true;
                        break;
                    }
                }
            }
        }
        if (!dupe)
            num++;
    }
    cout << "Number of valid passphrases for puzzle B: " << num << endl;
}

int main() {
    ifstream inputFile("input.txt");
    if(!inputFile){
    cout << "There is no valid input file, please try again." << endl;
        return 0;
    }
    string sInput((istreambuf_iterator<char>(inputFile)),
                  istreambuf_iterator<char>());
    vector<string> input = split(sInput, '\n');
    //cout << "Our input: " << sInput << endl;
    challangeOne(input);
    challangeTwo(input);
    return 0;
}