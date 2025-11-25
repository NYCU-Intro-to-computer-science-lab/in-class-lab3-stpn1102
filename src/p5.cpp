#include <iostream> 
using namespace std;

void move(int disk, int from, int to) {
    // 限制不得 1 <--> 3 直接移動
    if ((from == 1 && to == 3) || (from == 3 && to == 1)) {
        // 應該不會真的進入這裡
        return;
    }
    cout << "Move disk " << disk << " from " << from << " to " << to << endl;
}

// 限制版河內塔遞迴
void hanoi(int n, int from, int to, int aux) {
    // 禁止 from=1 to=3 或 from=3 to=1 的直接遞移
    if (n == 0) return;
    if ((from == 1 && to == 3) || (from == 3 && to == 1)) {
        // 想從柱子1移到柱子3，分兩段：1->2, 2->3
        hanoi(n, from, aux, to);   // 先將 n 全部移到 aux（2）
        hanoi(n, aux, to, from);   // 再將 n 全部移到 to（3）
    } else {
        // 允許 1<->2或2<->3直接遞移
        if (n == 1) {
            move(1, from, to);
            return;
        }
        hanoi(n-1, from, aux, to);
        move(n, from, to);
        hanoi(n-1, aux, to, from);
    }
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);
    return 0;
}
