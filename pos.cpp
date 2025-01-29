#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    cin >> n;
    map<int, int> poslowie;
    int a, b;
    
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        auto it1 = poslowie.find(a);
        auto it2 = poslowie.find(b);
        int x = 0;
        int y = 0;
        if (it1 != poslowie.end()) {
            x = it1->second;
            poslowie.erase(a);
        }
        if (it2 != poslowie.end()) {
            y = it2->second;
            poslowie.erase(b);
        }
        poslowie.insert({a, x + 1});
        poslowie.insert({b, y - 1});
    }

    int prev = 0;
    int ok = false;
    int days = 0;
    int akt = 0;
 
    for (const auto& [key, value] : poslowie) {
        akt += value;
        if (akt >= 2 && !ok) {
            ok = true;
            prev = key; 
        } else if (akt < 2 && ok){
            ok = false;
            days = days + key - prev;
        }
    }

    cout << days << endl;

    return 0;
}