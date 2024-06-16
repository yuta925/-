#include <iostream>
#include <list>
using namespace std;

int main() {
    list<char> L;

    L.push_front('b');          // [b]
    L.push_back('c');           // [bc]
    L.push_front('a');          // [abc]

    cout << L.front();          // a
    cout << L.back();           // c

    L.pop_front();              // [bc]
    L.push_back('d');           // [bcd]

    cout << L.front();          // b
    cout << L.back() << endl;   // d

    return 0;
}

/**
 * size() リストの要素数を返す
 * begin() 先頭のイテレータを返す
 * end() 末尾の次のイテレータを返す
 * push_front(x) 先頭に要素 x を追加する
 * push_back(x) 末尾に要素 x を追加する
 * pop_front() 先頭の要素を削除する
 * pop_back() 末尾の要素を削除する
 * insert(p,x) イテレータ p の位置に要素 x を挿入する
 * erase(p) イテレータ p の要素を削除する
 * clear() リストを空にする
 */