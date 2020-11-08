#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

// GENERALES
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}

int cantFilas (vector<vector<bool>> const &t){
    int size = t.size();
    return size;
}

int cantColumnas (vector<vector<bool>> const &t){
    return t[0].size();
}

// EJERCICIO 1
bool esRectangulo (vector<vector<bool>> const &t){
    int longEsperadaFilas = t[0].size();
    bool esRectangulo = true;
    for (int i = 1; i < t.size(); i ++) {
        if (t[i].size() != longEsperadaFilas)
            esRectangulo = false;
    }
    return esRectangulo;
}

// EJERCICIO 4
bool vecinaViva(toroide t , int z , int c , int i , int j){
    int result = t[(z+i + t.size()) % t.size()][(c+j + t[0].size()) % t[0].size()];
    return result;
}

int vecinosVivos(toroide t, int f , int c){
    int  result = 0 ;
    for (int i = -1; i <=1 ; ++i) {
        for (int j = -1; j <=1 ; ++j) {
            if ((i != 0 || j != 0) && vecinaViva(t,f,c,i,j)){
                result = result +1;
            }
        }
    }
    return result;
}