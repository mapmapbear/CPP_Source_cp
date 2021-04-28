#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    vector<int> vec{12,56,74,89,13,14,22,34,15,19};

    sort(vec.begin(),vec.end(),[](int a, int b){return a > 20 ? b > a : a >b;});
    for(auto s : vec)
        cout << s << endl;
    
    return 0;
}