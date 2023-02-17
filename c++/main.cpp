//
//  main.cpp
//  c++
//
//  Created by suraj kumar on 09/02/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Matrix {
    int A[10];
    int n;
};
void Set(struct Matrix *m, int i, int j, int x) {
    
    if(i == j) {
        m->A[i - 1] = x;
    }
}
int Get(struct Matrix m, int i, int j) {
    if(i == j) {
        return m.A[i - 1];
    }
    return 0;
}
void Display(struct Matrix m) {
    int i, j;
    for(i = 0; i < m.n; i++) {
        for(j = 0; j < m.n; j++) {
            if(i == j) {
                printf("%d ", m.A[i - 1]);
            }else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
/*
int main() {
    struct Matrix m;
    m.n = 4;
    Set(&m, 1, 1, 3);
    Set(&m, 2, 2, 5);
    Set(&m, 3, 3, 2);
    Set(&m, 4, 4, 6);
    Display(m);
}
*/

//MARK: Class for Diagonal Matrix:

class DiagonalMatrix {
private:
    int n;
    int *A;
    
public:
    DiagonalMatrix() {
        n = 2;
        A = new int[2];
        
    }
    DiagonalMatrix(int n) {
        this->n = n;
        A = new int[n];
        
    }
    ~DiagonalMatrix() {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension(){return n;}
    
};
void DiagonalMatrix::Set(int i, int j, int x) {
    if (i == j) {
        A[i - 1] = x;
    }
}
int DiagonalMatrix::Get(int i, int j) {
    if(i == j) {
        return A[i - 1];
    }
    return 0;
}
void DiagonalMatrix::Display() {
    for (int i = 0; i < n; i++) {
        
        for(int j = 0; j < n; j++) {
            if(i == j) {
                cout<<A[i - 1];
            }else {
                cout<<"0";
            }
        }
        cout<<endl;
    }
}
int main() {
    int d;
    cout<<"Enter Dimension";
    cin>>d;
    DiagonalMatrix dm(d);
    int x;
    cout<<"Enter All the Element";
    
    for(int i = 1; i <= d; i++) {
        
        for(int j = 1; j <= d; j++) {
            cin>>x;
            dm.Set(i, j, x);
        }
    }
    
    dm.Display();
    return 0;
}
