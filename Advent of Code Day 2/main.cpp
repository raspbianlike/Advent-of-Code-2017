#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std; // I don't like this
template<typename Out>
void split(const std::string &s, char delim, Out result) { // this is pasted thanks to stackoverflow
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
void challangeOne(){
    string sSum;
    vector<string> input = split("1208 412 743 57 1097 53 71 1029 719 133 258 69 1104 373 367 365 \n"
                                         "4011 4316 1755 4992 228 240 3333 208 247 3319 4555 717 1483 4608 1387 3542 \n"
                                         "675 134 106 115 204 437 1035 1142 195 1115 569 140 1133 190 701 1016 \n"
                                         "4455 2184 5109 221 3794 246 5214 4572 3571 3395 2054 5050 216 878 237 3880 \n"
                                         "4185 5959 292 2293 118 5603 2167 5436 3079 167 243 256 5382 207 5258 4234 \n"
                                         "94 402 126 1293 801 1604 1481 1292 1428 1051 345 1510 1417 684 133 119 \n"
                                         "120 1921 115 3188 82 334 366 3467 103 863 3060 2123 3429 1974 557 3090 \n"
                                         "53 446 994 71 872 898 89 982 957 789 1040 100 133 82 84 791 \n"
                                         "2297 733 575 2896 1470 169 2925 1901 195 2757 1627 1216 148 3037 392 221 \n"
                                         "1343 483 67 1655 57 71 1562 447 58 1561 889 1741 1338 88 1363 560 \n"
                                         "2387 3991 3394 6300 2281 6976 234 204 6244 854 1564 210 195 7007 3773 3623 \n"
                                         "1523 77 1236 1277 112 171 70 1198 86 1664 1767 75 315 143 1450 1610 \n"
                                         "168 2683 1480 200 1666 1999 3418 2177 156 430 2959 3264 2989 136 110 3526 \n"
                                         "8702 6973 203 4401 8135 7752 1704 8890 182 9315 255 229 6539 647 6431 6178 \n"
                                         "2290 157 2759 3771 4112 2063 153 3538 3740 130 3474 1013 180 2164 170 189 \n"
                                         "525 1263 146 954 188 232 1019 918 268 172 1196 1091 1128 234 650 420", '\n' );
    int sum = 0;
    for(vector<string>::const_iterator i = input.begin(); i != input.end(); i++){
        string tosplit = *i;
        vector<string> check = split(tosplit, ' ');
        int big = 0, low = numeric_limits<int>().max(); // Style
        for(vector<string>::const_iterator x = check.begin(); x != check.end(); x++) {
            string target = *x;
            int temp = stoi(target);
            if(temp > big)
                big = temp;
            if(temp < low)
                low = temp;
        }
        sum += (big - low);
    }


    cout << "Sum for challange one: " << sum << endl;
}
void challangeTwo(){
    string sSum;
    vector<string> input = split("1208 412 743 57 1097 53 71 1029 719 133 258 69 1104 373 367 365 \n"
                                         "4011 4316 1755 4992 228 240 3333 208 247 3319 4555 717 1483 4608 1387 3542 \n"
                                         "675 134 106 115 204 437 1035 1142 195 1115 569 140 1133 190 701 1016 \n"
                                         "4455 2184 5109 221 3794 246 5214 4572 3571 3395 2054 5050 216 878 237 3880 \n"
                                         "4185 5959 292 2293 118 5603 2167 5436 3079 167 243 256 5382 207 5258 4234 \n"
                                         "94 402 126 1293 801 1604 1481 1292 1428 1051 345 1510 1417 684 133 119 \n"
                                         "120 1921 115 3188 82 334 366 3467 103 863 3060 2123 3429 1974 557 3090 \n"
                                         "53 446 994 71 872 898 89 982 957 789 1040 100 133 82 84 791 \n"
                                         "2297 733 575 2896 1470 169 2925 1901 195 2757 1627 1216 148 3037 392 221 \n"
                                         "1343 483 67 1655 57 71 1562 447 58 1561 889 1741 1338 88 1363 560 \n"
                                         "2387 3991 3394 6300 2281 6976 234 204 6244 854 1564 210 195 7007 3773 3623 \n"
                                         "1523 77 1236 1277 112 171 70 1198 86 1664 1767 75 315 143 1450 1610 \n"
                                         "168 2683 1480 200 1666 1999 3418 2177 156 430 2959 3264 2989 136 110 3526 \n"
                                         "8702 6973 203 4401 8135 7752 1704 8890 182 9315 255 229 6539 647 6431 6178 \n"
                                         "2290 157 2759 3771 4112 2063 153 3538 3740 130 3474 1013 180 2164 170 189 \n"
                                         "525 1263 146 954 188 232 1019 918 268 172 1196 1091 1128 234 650 420", '\n' );
    int sum = 0;
    for(vector<string>::const_iterator i = input.begin(); i != input.end(); i++){
        string tosplit = *i;
        vector<string> check = split(tosplit, ' ');
        for(vector<string>::const_iterator x = check.begin(); x != check.end(); x++) {
            string target = *x;
            for(vector<string>::const_iterator y = check.begin(); y != check.end(); y++) {
                int currentTarget = stoi(target);
                int oldTarget = stoi(*y);
                if(currentTarget != oldTarget) {
                    if (currentTarget % oldTarget == 0){
                    sum += currentTarget  / oldTarget;
                    }
                }

            }
        }
    }
    cout << "Sum for challange two: " << sum << endl;
}

int main() {
    challangeOne();
    challangeTwo();
    return 0;
}