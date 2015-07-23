#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <functional>

using namespace std;

int main(){
    int arr[] = {1,2,3};
    vector<int> vec(arr,arr+3);
    int num = count_if(vec.begin(), vec.end(), [](int x){return x < 3;});
    cout << num << endl;
    std::deque<int> d;
    return 0;
}
