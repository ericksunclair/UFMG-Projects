// matrix.cpp
#include "matrix.h"
#include <iostream>
#include <fstream> 

// contrutor default - cria uma matriz vazia com nRows = nCols = 1  
Matrix::Matrix(){
    nRows = 1;
    nCols = 1;
    
    m = (double**) malloc(sizeof(double*)*nRows);   // aloca as linhas da matriz
    for (int i=0; i<nRows; i++){
        m[i] = (double*) malloc(sizeof(double)*nCols);  // aloca as colunas pra cada linha da matriz
    }
}
    

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, const double &value){
    nRows = rows;
    nCols = cols;
    
    m = (double**) malloc(sizeof(double*)*nRows);   // aloca as linhas da matriz
    for (int i=0; i<nRows; i++){
        m[i] = (double*) malloc(sizeof(double)*nCols);  // aloca as colunas pra cada linha da matriz
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            m[i][j] = value;
        }
    }
}

// construtor por arquivo
Matrix::Matrix(std::ifstream& myFile){
    nRows = (int) myFile.get();
    nCols = (int) myFile.get();
    
    m = (double**) malloc(sizeof(double*)*nRows);   // aloca as linhas da matriz
    for (int i=0; i<nRows; i++){
        m[i] = (double*) malloc(sizeof(double)*nCols);  // aloca as colunas pra cada linha da matriz
    }

    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            m[i][j] = (double) myFile.get();
        }
    }
}

// construtor por cópia
Matrix::Matrix(const Matrix& that){
    nRows = that.nRows;
    nCols = that.nCols;
    
    m = (double**) malloc(sizeof(double*)*nRows);   // aloca as linhas da matriz
    for (int i=0; i<nRows; i++){
        m[i] = (double*) malloc(sizeof(double)*nCols);  // aloca as colunas pra cada linha da matriz
    }

    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            m[i][j] = that.get(0, 0);
        }
    }
}


// destrutor
Matrix::~Matrix() {
    for(int i=0; i<nRows; i++){
        delete m[i];
    }
    delete m;
}


// obtem o numero de linhas
int Matrix::getRows() const {
    return nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const {
    return nCols;
}

// obtem um elemento específico na posição (row,col). Obs: deve checar consistencia
double Matrix::get(int row, int col) const {
    return m[row][col];
}

// retorna uma matriz transposta
Matrix Matrix::transpose() {
    double **t = (double**) malloc(sizeof(double*)*nCols);   // aloca as linhas da matriz
    for (int i=0; i<nRows; i++){
        t[i] = (double*) malloc(sizeof(double)*nRows);  // aloca as colunas pra cada linha da matriz
    }

    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            t[j][i] = m[i][j];
        }
    }
    Matrix mt(nCols, nRows, t[0][0]);
    return mt;
}

// imprime o conteudo da matriz
void Matrix::print() const {
    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            std::cout <<  m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// faz com que a matriz torne-se uma matriz identidade
void Matrix::unit(){
    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            if(i==j)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// faz com que a matriz torne-se uma matriz nula
void Matrix::zeros(){
    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            m[i][j] = 0;
        }
    }
}

// faz com que a matriz torne-se uma matriz cujos elementos sao iguais a 1
void Matrix::ones(){
    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            m[i][j] = 1;
        }
    }
}