#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> S;

    S.push(3); // スタックに 3 を積む
    S.push(7); // スタックに 7 を積む
    S.push(1); // スタックに 1 を積む
    cout << S.size() << " "; // スタックのサイズ = 3

    cout << S.top() << " "; // 1
    S.pop(); // スタックの頂点から要素を削除

    cout << S.top() << " "; // 7
    S.pop(); 

    cout << S.top() << " "; // 3

    S.push(5);

    cout << S.top() << " "; // 5
    S.pop();

    cout << S.top() << endl; // 3

    return 0;
}