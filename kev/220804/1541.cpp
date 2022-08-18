#include <iostream>
#include <vector>
#include <string>
using namespace std;

string input;

void init(){
    cin >> input;
}

void solve(){
    vector<int> nums;
    vector<char> syms;
    int start;
    int pos = 0;
    while((start = input.find_first_not_of("+-", pos)) != string::npos){
        pos = input.find_first_of("+-", start + 1);
        int n = stoi(input.substr(start, pos - start));
        nums.push_back(n);
        syms.push_back(input[pos]);
    }

    int sum = nums[0];
    bool toggle = false;
    for(int i = 1; i < nums.size(); i++){
        if(!toggle && syms[i - 1] == '-') toggle = true;
        if(toggle) sum -= nums[i];
        else sum += nums[i];
    }
    cout << sum << '\n';
}

int main(){
    init();
    solve();
    return 0;
}