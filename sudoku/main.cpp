#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
using namespace std;
typedef vector<vector<int>> MATRIX;

void print(MATRIX matrix, MATRIX checkmatrix);
void create(MATRIX &matrix, bool is_random);
void check(MATRIX &matrix, MATRIX &checkmatrix );
int count_rows(MATRIX &matrix, int n, int i);
int count_cols(MATRIX &matrix, int n, int j);
int count_square(MATRIX &matrix, int n, int i, int j);

int main() {
    MATRIX matrix;
    MATRIX checkmatrix;
    create(matrix, true);
    create(checkmatrix, false);
    check(matrix, checkmatrix);
    print(matrix, checkmatrix);
    return 0;
}

//Crea una matrix de 9 filas y 9 columnas.
// Si rand es true los valores de la matriz serán aleatorios
// Si rand es false los valores de la matriz serán cero.
void create(MATRIX &matrix, bool is_random){
    srand(time(nullptr));
    int filas=9, columnas =9;
    for(int i=0;i<filas;i++){
        vector<int> fil = vector<int>(columnas,0);
        if(is_random == true){
            for(int j=0;j<columnas; j++){
                fil[j] = rand()%9;
            }
        }
        matrix.push_back(fil);
    }
}
void check(MATRIX &matrix,MATRIX &checkmatrix ){
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j< matrix[i].size(); j++ ){
            if(count_rows(matrix, matrix[i][j], i) > 1){
                checkmatrix[i][j] = 1;
            }
            if(count_cols(matrix, matrix[i][j], j) > 1){
                checkmatrix[i][j] = 2;
            }
            bool no_es_borde = i>0 && i<matrix.size()-1 && j>0 && j < matrix[0].size()-1;
            if( no_es_borde && count_square(matrix, matrix[i][j],i,j) > 1){
                checkmatrix[i][j] = 3;
            }
        }
    }
  }

//Cuenta cuantas veces se repite el numero n en la fila i
int count_rows(MATRIX &matrix, int n, int i){
    int cont=0;
    for (int x=0; x<matrix[0].size(); x++){
      if(matrix[i][x]==n){
        cont=cont+1;
      }
    }
  return cont;}

//Cuenta cuantas veces se repite el numero n en region (i-1, j-1) a (i+1, j+1)
int count_square(MATRIX &matrix, int n, int i, int j){
    int cont=0;
    int val=0;
    for(int x=0; x<3;x++ ){
      for (int y=0; y<+3; y++){
          if (matrix[i][j]==matrix[i-1+x][j-1+y]){
            cont=cont+1;}
      }
    }
  return cont;}

//Cuenta cuantas veces se repite el numero n en la columna j
int count_cols(MATRIX &matrix, int n, int j){
    // Implementa esta función
    int cont=0;
    for (int s=0; s<matrix.size(); s++){
      if (matrix[s][j]==n){
        cont=cont+1;}
    }
  return cont;}



//Muestra la matriz en pantalla.  El elemento será
// rojo si se repite en la fila
// azul si se repite en la columna
// verde si se repite en la región de 3x3.
void print(MATRIX matrix, MATRIX checkmatrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0; j<matrix[i].size(); j++){
            if(checkmatrix[i][j] == 1){
                cout << "\033[1;41m "<<matrix[i][j]<<" \033[0m\t";
            }else if(checkmatrix[i][j] == 2){
                cout << "\033[1;44m "<<matrix[i][j]<<" \033[0m\t";
            }else if(checkmatrix[i][j] == 3){
                cout << "\033[1;42m "<<matrix[i][j]<<" \033[0m\t";
            }else{
                cout<<matrix[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
}
