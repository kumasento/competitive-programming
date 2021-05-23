#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T; t ++) {
        int N; cin >> N;
        
        vector<int> L(N);
        for (int i = 0; i < N; i ++)
            cin >> L[i];
            
        int cost = 0;
        int i = 0;
        while (i < N - 1) {
            int j = min_element(L.begin() + i, L.end()) - L.begin();
            reverse(L.begin() + i, L.begin() + j + 1);

            cost += (j - i + 1);
            i ++;
        }
            
        cout << "Case #" << (t + 1) << ": " << cost << endl;
    }
}
