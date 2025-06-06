#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> solutions;

void dfs(vector<int>& current, int pos, int sum) {
    if (pos == 10) {
        if (sum == n) {
            solutions.push_back(current);
        }
        return;
    }
    
    for (int i = 1; i <= 3; i++) {
        if (sum + i + (9 - pos) <= n && sum + i + 3 * (9 - pos) >= n) {
            current[pos] = i;
            dfs(current, pos + 1, sum + i);
        }
    }
}

int main() {
    cin >> n;
    
    if (n < 10 || n > 30) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> current(10);
    dfs(current, 0, 0);
    
    cout << solutions.size() << endl;
    for (const auto& sol : solutions) {
        for (int i = 0; i < 10; i++) {
            cout << sol[i];
            if (i < 9) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 