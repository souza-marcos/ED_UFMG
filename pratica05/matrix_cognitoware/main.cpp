#include <iostream>
#include <vector>

#include "Matrix.h"
#include "memlog.h"

using namespace std;

vector<double> rand_vector(int size){
    srand(time(0));
    vector<double> arr(size);
    for(auto &el: arr) el = rand() % 21;
    return arr;
}

int main(int argc, char** argv){
    
    if(argc < 2) return -1;
    
    int COLS = stoi(argv[1]), ROWS = stoi(argv[1]);
    
    string logname = "/tmp/determinante" + to_string(COLS) + ".out";
    iniciaMemLog((char*)logname.c_str());
    ativaMemLog();

    // Inicializacao
    defineFaseMemLog(0);
    cognitoware::Matrix m1 = cognitoware::Matrix(ROWS, COLS, rand_vector(COLS * ROWS), (int) 0);

    //Operacao monitorada
    defineFaseMemLog(1);
    double determinant = m1.Determinant();

    // Printa a matriz e o seu determinante
    defineFaseMemLog(2);
    cout << m1 << endl;
    cout << "Determinante: " <<  determinant << endl;
    
    finalizaMemLog();
    return 0;
}