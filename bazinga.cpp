#include <iostream>
#include <iomanip>
#include <ios>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#define scanf LIXO
using namespace std;

//char = 97 == 'a' 

int achar(string p){
    int i;
    string arr[5] = {"tesoura","papel","pedra","lagarto","Spock"};
    for(i = 0; i < 5; i++){
        if(arr[i] == p){
            return i;
        }
    }
    return 1;
}
 
int main() {
 
    int n;
    
    cin >> n;
    
    int mat[5][5] = {{0,1,-1,1,-1},
                    {-1,0,1,-1,1},
                    {1,-1,0,1,-1},
                    {-1,1,-1,0,1},
                    {1,-1,1,-1,0}};
    
    string p1,p2;
    int cont = 0;
    
    while(n > 0){
        n--;
        cont ++;
        cin >> p1 >> p2;
        
        cout << "Caso #" << cont << ": ";
        
        if(mat[achar(p1)][achar(p2)] == 1){
            cout << "Bazinga!" << endl;
        }
        else if(mat[achar(p1)][achar(p2)] == 0){
            cout << "De novo!" << endl;
        }
        else{
            cout << "Raj trapaceou!" << endl;
        }
        
    }
 
    return 0;
}
