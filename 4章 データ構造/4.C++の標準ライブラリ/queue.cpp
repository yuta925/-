#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> Q;

    Q.push("red");
    Q.push("yellow");
    Q.push("yellow");
    Q.push("blue");

    cout << Q.front() << " "; // red 
    Q.pop(); 

    cout << Q.front() << " "; // yellow
    Q.pop();

    cout << Q.front() << " "; // yellow
    Q.pop();

    Q.push("green");

    cout << Q.front() << " "; // blue
    Q.pop();

    cout << Q.front() << endl; // green

    return 0;
}

/**
 * size() キューの要素数を返す
 * front() 先頭の要素を返す
 * pop() 先頭の要素を取り出し削除する
 * push() キューに要素を追加する
 * empty() キューが空のときに true を返す
 */