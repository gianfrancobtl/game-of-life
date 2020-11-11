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

int filaToroide (toroide const &t, int f, int i){
    return (f + i + cantFilas(t)) % cantFilas(t);
}

int columnaToroide (toroide const &t, int c, int j){
    return (c + j + cantColumnas(t)) % cantColumnas(t);
}

// EJERCICIO 1
bool esRectangulo (toroide const &t){
    int longEsperadaFilas = cantColumnas(t);
    bool esRectangulo = true;
    for (int i = 1; i < cantFilas(t); i ++){
        if (t[i].size() != longEsperadaFilas)
            esRectangulo = false;
    }
    return esRectangulo;
}

// EJERCICIO 4
bool estaViva(toroide const &t, posicion x){
    return t[x.first][x.second];
}

bool posVecinaViva(toroide const &t, int f, int c, int i, int j){
    return (t[filaToroide (t, f, i)][columnaToroide (t, c, j)]);
}

int cantVecinosVivos (toroide const &t, posicion x){
    int cantVecinosVivos = 0;
    int f = x.first;
    int c = x.second;
    for (int i = - 1; i <= 1; i ++){
        for (int j = - 1; j <= 1; j ++){
            if ((i != 0 || j != 0) && posVecinaViva(t, f, c, i, j))
                cantVecinosVivos += 1;
        }
    }
    return cantVecinosVivos;
}

// EJERCICIO 7
bool toroideMuerto (toroide const &t){
    bool estaMuerto = true;
    int i = 0;
    while (i < cantFilas(t) && estaMuerto) {
        int j = 0;
        while (j < cantColumnas(t) && estaMuerto) {
            if (t[i][j])
                estaMuerto = false;
            j ++;
        }
        i ++;
    }
    return estaMuerto;
}

//EJERCICIOS 11
toroide traslacion(toroide t, int f , int c ){
    toroide trasladado = t;
    for (int i = 0; i < cantFilas(t); i ++) {
        for (int j = 0; j < cantColumnas(t); j ++) {
            trasladado[filaToroide(t, f, i)][columnaToroide(t, c, j)] = t[i][j];
        }
    }
    return trasladado;
}

//EJERCICIO 12
bool filaTieneViva (vector<bool> n){
    bool resp = false;
    for (int i = 0; i < n.size(); i ++){
        if (n[i])
            resp = true;
    }
    return resp;
}

int primeraFilaViva (toroide t){
    int resultado = -1;
    bool resp = false;
    int i = 0;
    while (i < cantFilas(t) && !resp){
        if (filaTieneViva(t[i])){
            resultado = i;
            resp = true;
        }
        i ++;
    }
    return resultado;
}

int ultimaFilaViva (toroide t){
    int resultado = -1;
    bool resp = false;
    int i = cantFilas(t) - 1;
    while (i >= 0 && !resp ){
        if (filaTieneViva(t[i])){
            resultado = i;
            resp = true;
        }
        i --;
    }
    return resultado;
}

int primeraColumnaViva(toroide t){
    int result = -1;
    bool resp = false;
    int j = 0;
    while (j < cantFilas(t) && !resp ){
        for (int i = 0; i < cantFilas(t); i ++){
            if (t[i][j]){
                result = j;
                resp = true;
            }
        }
        j ++;
    }
    return result;
}

int ultimaColumnaViva(toroide t){
    int result = -1;
    bool resp = false;
    int j = cantColumnas(t) - 1;
    while (j >= 0 && !resp ){
        for (int i = 0; i < cantFilas(t); i ++){
            if (t[i][j]){
                result = j;
                resp = true;
            }
        }
        j --;
    }
    return result;
}

int areaTotal (const toroide& t){
    int cantFilasVivas = ultimaFilaViva(t) - primeraFilaViva(t) + 1;
    int cantColumnasVivas = ultimaColumnaViva(t) - primeraColumnaViva(t) + 1;
    return cantFilasVivas * cantColumnasVivas;
}