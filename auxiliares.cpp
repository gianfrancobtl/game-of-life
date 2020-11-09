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
    int result = t[(z+i + cantFilas(t)) % cantFilas(t)][(c+j + cantColumnas(t)) % cantColumnas(t)];
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


// EJERCICIO 7
bool toroideMuerto (toroide const &t){
    bool estaMuerto = true;
    for (int i = 0; i < cantFilas(t) && estaMuerto; i ++) {
        for (int j = 0; j < cantColumnas(t) && estaMuerto; j++) {
            if (t[i][j]) {
                estaMuerto = false;
            }
        }
    }
    return estaMuerto;
}



//EJERCICIOS 11
toroide traslacion(toroide t, int a , int b ){
    toroide l = t;
    for (int i = 0; i < cantFilas(t) ; ++i) {
        for (int j = 0; j < cantColumnas(t) ; ++j) {
            l[(i + a + cantFilas(t)) % cantFilas(t)] [(j + b + cantColumnas(t)) % cantColumnas(t)] = t[i][j];
        }
    }
    return l;
}



//EJERCICIO 12
bool filaTieneViva (vector<bool> n){
    bool resp = false;
    for (int i = 0; i < n.size() && !resp ; ++i) {
        if (n[i]){
            resp = true;
        }
    }
    return resp;
}


int primeraFilaViva (toroide t){
    int resultado = 0;
    bool resp = false;
    for (int i = 0; i < cantFilas(t) && !resp ; ++i) {
        if (filaTieneViva(t[i])){
            resultado = i;
            resp = true;
        }
    }
    return resultado;
}

int ultimaFilaViva (toroide t){
    int resultado = 0;
    bool resp = false;
    for (int i = cantFilas(t)-1; i > 0 && !resp ; i--) {
        if (filaTieneViva(t[i])){
            resultado = i;
            resp = true;
        }
    }
    return resultado;
}

int primeraColumnaViva(toroide t){
    int result = 0;
    bool resp = false;
    for (int j = 0; j < cantColumnas(t) && !resp ; ++j) {
        for (int i = 0; i <cantFilas(t) ; ++i) {
            if (t[i][j]){
                result = j;
                resp = true;
            }
        }
    }
    return result;
}

int ultimaColumnaViva(toroide t){
    int result = 0;
    bool resp = false;
    for (int j = cantColumnas(t) -1; j > 0 && !resp ; ++j) {
        for (int i = 0; i <cantFilas(t) ; ++i) {
            if (t[i][j]){
                result = j;
                resp = true;
            }
        }
    }
    return result;
}

int areaTotal (toroide t){
    int cantFilaViva = ultimaFilaViva(t) - primeraFilaViva(t) + 1;
    int cantColumnaViva = ultimaColumnaViva(t) - primeraColumnaViva(t) + 1;
    return cantFilaViva * cantColumnaViva;
}