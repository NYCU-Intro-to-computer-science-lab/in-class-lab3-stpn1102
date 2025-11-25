#include <iostream> copilot
using namespace std;


int fib(int n, int depth) {
    
    for (int i = 0; i < depth; ++i) cout << "|--";
    cout << "SEARCH fib(" << n << ")" << endl;

    int result;
    if (n == 1 || n == 2) {
        result = 1;
    } else {
        
        int fn1 = fib(n - 1, depth + 1);
        int fn2 = fib(n - 2, depth + 1);
        result = fn1 + fn2;
    }

    
    for (int i = 0; i < depth; ++i) cout << "|--";
    cout << "GET fib(" << n << ") = " << result << endl;
    return result;
}

int main() {
    int n;
    cin >> n;
    int res = fib(n, 0);         
    cout << res << endl;         
    return 0;
}
