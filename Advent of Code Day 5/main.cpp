#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

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

void puzzleA(vector<int> input){
    int position = 0, count = 0, length(input.size());
    while(position >= 0 && position < length){
        position += input[position]++;
        count++;
    }

    cout << "Steps to exit for Puzzle A: " << count << endl;
}
void puzzleB(vector<int> input){
    int position = 0, count = 0, length(input.size());
    while(position >= 0 && position < length){
        if(input[position] >= 3)
            position += input[position]--;
        else
            position += input[position]++;
        count++;
    }

    cout << "Steps to exit for Puzzle B: " << count;
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
    vector<int> iInput;
    for(vector<string>::const_iterator x = input.begin(); x != input.end(); x++){
        iInput.push_back(stoi(*x));
    }
    puzzleA(iInput);
    puzzleB(iInput);

    return 0;
}