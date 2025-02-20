// C21-Quick-Union-Connectivity-App.cpp 
/*
Quick-union uses a tree-based structure to represent the connected components of a graph.
    -The root of the tree represents the group.
    -The Quick Union algorithm is more efficient than Quick Find because
     it uses the root of the tree to determine if two elements are in the same group.
    -The Quick Union algorithm has a time complexity of O(N) for union and find operations.

References: https://algs4.cs.princeton.edu/15uf/

*/
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


class QuickUnion {
private:
    vector<int> id;

public:
    QuickUnion(int N) {
        id.resize(N);
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    int root(int i) {
        while (i != id[i]) {
            i = id[i];
        }
        return i;
    }

    bool find(int p, int q) {
        return root(p) == root(q);
    }

    void union_elements(int p, int q) {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }

    string toString() {
        stringstream sout;
        for (int i = 0; i < id.size(); i++) {
            sout << id[i] << " ";
        }
        sout << endl;
        return sout.str();
    }
};

int main() {
    cout << "Quick Union Connectivity" << endl;
    QuickUnion qu(10);

    cout << "Initial state:" << endl;
    cout << qu.toString();

    qu.union_elements(4, 3);
    cout << "After union(4, 3):" << endl;
    cout << qu.toString();

    qu.union_elements(3, 8);
    cout << "After union(3, 8):" << endl;
    cout << qu.toString();

    qu.union_elements(6, 5);
    cout << "After union(6, 5):" << endl;
    cout << qu.toString();

    qu.union_elements(9, 4);
    cout << "After union(9, 4):" << endl;
    cout << qu.toString();

    qu.union_elements(2, 1);
    cout << "After union(2, 1):" << endl;
    cout << qu.toString();

    cout << "Find(8, 9): " << (qu.find(8, 9) ? "True" : "False") << endl;
    cout << "Find(5, 4): " << (qu.find(5, 4) ? "True" : "False") << endl;

    qu.union_elements(5, 0);
    cout << "After union(5, 0):" << endl;
    cout << qu.toString();

    qu.union_elements(7, 2);
    cout << "After union(7, 2):" << endl;
    cout << qu.toString();

    qu.union_elements(6, 1);
    cout << "After union(6, 1):" << endl;
    cout << qu.toString();

    cout << "Find(1, 0): " << (qu.find(1, 0) ? "True" : "False") << endl;

    return 0;
}

