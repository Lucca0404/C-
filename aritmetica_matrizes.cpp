#include <iostream>
using namespace std;

int** somaMatrizes(int** mat1,int** mat2, int n1, int m1){
  int** matRes = (int**) malloc(n1 * sizeof(int*));
  int i, j, k;
  for(i = 0; i < n1; i++){
    matRes[i] = (int*) calloc(m1, sizeof(int));
  }
  
  for(i = 0; i < n1; i++){
    for(j = 0; j < m1; j++){
      matRes[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
  
  return matRes;
}

int** multMatrizes(int** mat1, int n1, int m1, int** mat2, int n2, int m2){
  int** matRes = (int**) malloc(n1 * sizeof(int*));
  int i, j, k;
  for(i = 0; i < n1; i++){
    matRes[i] = (int*) calloc(m2, sizeof(int));
  }
  
  for(i = 0; i < n1; i++){
    for(j = 0; j < m2; j++){
      for(k = 0; k < m1; k++){
        matRes[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  
  return matRes;
}

int main() 
{
  
  int n1,m1;
  int n2,m2;
  
  cout << "Digite o numero de linhas e colunas, respectivamente, da primeira matriz: ";
  cin >> n1 >> m1;
  
  cout << "Digite o numero de linhas e colunas, respectivamente, da segunda matriz: ";
  cin >> n2 >> m2;
  
  int** mat1 = (int**) malloc(sizeof(int*) * n1);
  int** mat2 = (int**) malloc(sizeof(int*) * n2);
  
  int i,j;
  
  for(i = 0; i < n1; i++){
    mat1[i] = (int*) calloc(m1, sizeof(int));
  }
  
  for(i = 0; i < n2; i++){
    mat2[i] = (int*) calloc(m2, sizeof(int));
  }
  
  cout << "Preencha os valores da primeira matriz: \n";
  for(i = 0; i < n1; i++){
    cout << "Linha " << i+1 << endl;
    for(j = 0; j < m1; j++){
      cout << "Coluna " << j+1 << endl;
      cin >> mat1[i][j];
    }
  }
  
  cout << "Preencha os valores da segunda matriz: \n";
  for(i = 0; i < n2; i++){
    cout << "Linha " << i+1 << endl;
    for(j = 0; j < m2; j++){
      cout << "Coluna " << j+1 << endl;
      cin >> mat2[i][j];
    }
  }
  
  int escolha = 0;
  int validacao = 0;
  
  while(escolha != 1 && escolha != 2){
    cout << "Digite 1 para multiplicar elas ou 2 para soma-las: ";
    cin >> escolha;
  }
  
  int** mat3;
  
  if(escolha == 1 && m1 == n2){
     mat3 = multMatrizes(mat1, n1, m1, mat2, n2, m2);
    validacao = 1;
  }
  else{
    if(escolha == 2 && n1 == n2 && m1 == m2){
      mat3 = somaMatrizes(mat1,mat2,n1,m1);
      validacao = 1;
    }
  }
  
  if(validacao){
    for(i = 0; i < n1; i++){
      for(j = 0; j < m2; j++){
        cout << mat3[i][j] << " ";
      }
      cout << endl;
    }  
  }
  
  free(mat3);
  
  return 0;
}
