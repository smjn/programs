#include <iostream>
#include <deque>
#include <vector>

int main(){
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);

    std::deque<int> deck(vec.begin(), vec.end());

    for(std::deque<int>::iterator iter = deck.begin(); iter != deck.end(); iter++){
        std::cout << (*iter) << std::endl;
    }

    return 0;
}
