#include <iostream>
#include <vector>
using namespace std;

void print(vector<double> V) {
    for (int i=0; i<V.size();i++) {
        cout << V[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<double> V;

    V.push_back(0.1);
    V.push_back(0.2);
    V.push_back(0.3);
    V[2] = 0.4;
    print(V); // 0.1 0.2 0.4

    V.insert(V.begin() + 2, 0.8);
    print(V); // 0.1 0.2 0.8 0.4

    V.erase(V.begin() + 1);
    print(V); // 0.1 0.8 0.4

    V.push_back(0.9);
    print(V); // 0.1 0.8 0.4 0.9

    return 0;
}

/**
 * size() ベクターの要素数を返す
 * push_back() ベクターに要素を追加する
 * pop_back() ベクターの末尾の要素を削除する
 * bigin() 先頭のイテレータを返す
 * end() 末尾の次のイテレータを返す
 * insert(p,x) イテレータ p の位置に要素 x を挿入する
 * erase(p) イテレータ p の要素を削除する
 * clear() ベクターを空にする
 */