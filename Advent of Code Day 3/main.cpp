#include <iostream>
#include <cmath>
using namespace std;
void puzzleA(int input){
    cout << "Puzzle A: " << endl;
    int i = input, root = 0;
    while(true){
        root = sqrt(i);
        if (root * root == i && i % 2 != 0) {
            break;
        }
        else
            i++;
    }
    // Now we have our nearest even square root, which equals the side length.
    int dif = (root*root) - input, center = (root-1) / 2, axis = dif - center;
    if(axis < 0)
        axis *= -1; // We want the absolute value of the axis
    cout << "Nearest odd root of our input: " << root << endl <<  "Difference between odd square and our input: " << dif << endl << "Center of the side: " << center << endl << "Axis: " << axis << endl << "Steps to center of the circle: " << axis + center << endl;

}
void puzzleB(){
    cout << "Puzzle B:\nhttps://oeis.org/A141481/b141481.txt\n";
}

int main() {
    int input = 0;
    cout << "Please enter your input: ";
    cin >> input;
    puzzleA(input);
    puzzleB();
    return 0;
}