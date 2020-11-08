#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = false;
    if (cantFilas(t) >= 3 && cantColumnas(t) >= 3 && esRectangulo(t))
        resp = true;
    return resp;
}

// EJERCICIO 2
vector<posicion> posicionesVivas(toroide const &t) {
    vector<posicion> vivos;
    for (int i = 0; i < cantFilas(t); i ++){
        for (int j = 0 ; j < cantColumnas(t); j ++){
            if (t[i][j])
                vivos.push_back(mp(i,j));
        }
    }
    return vivos;
}

// EJERCICIO 3
float densidadPoblacion(toroide const &t) {
    float cantidadViva = posicionesVivas(t).size();
    float superficieTotal = float(cantFilas(t)) * float(cantColumnas(t));
    return cantidadViva / superficieTotal;
}

// EJERCICIO 4
bool evolucionDePosicion(toroide const &t, posicion x) {
    bool resp = false;
    int cantVecinos =  vecinosVivos(t,x.first,x.second);
    if (cantVecinos==3) {
        resp = true;
    } else {
        if ( t[x.first][x.second] && cantVecinos >= 2 && cantVecinos <= 3){
            resp = true;
        }
    }
    return resp;
}

// EJERCICIO 5
void evolucionToroide(toroide &t){
    toroide toroideOriginal = t;
    for (int i = 0; i < cantFilas(t); i ++) {
        for (int j = 0; j < cantColumnas(t); j++) {
            t[i][j] = evolucionDePosicion(toroideOriginal, mp(i, j));
        }
    }
}

// EJERCICIO 6
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out = t;
    for (int k = K; k > 0; k --){
        evolucionToroide(out);
    }
    return out;
}

// EJERCICIO 7
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    // Implementacion
    return resp;
}

// EJERCICIO 8
bool primosLejanos(toroide const &t, toroide const &u) {
	bool resp = false; 
    // Implementacion
    return resp;
}

// EJERCICIO 9
int seleccionNatural(vector <toroide> ts) {
    int resp = -1; // este valor puede ser cambiado de acuerdo a la propia implementacion    
	// Implementacion
    return resp;
}

// EJERCICIO 10
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    // Implementacion
    return out;
}

// EJERCICIO 11
bool vistaTrasladada(toroide const &t, toroide const &u){
	bool resp = false;
    // Implementacion
    return resp;
}

// EJERCICIO 12
int menorSuperficieViva(toroide const &t){
	int resp = -1;
	// Implementacion
	return resp;
}
