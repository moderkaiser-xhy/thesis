#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    int rem = INT16_MIN;
    cout << rem <<endl;
    cout << 1%10 << endl;
    vector<int> data(10,1);
    cout << data.size() << endl;
    data.clear();
    cout << data.size() << endl;

    return 0;
}


