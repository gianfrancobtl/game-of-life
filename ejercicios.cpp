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
    bool resp;
    if ((estaViva(t, x) && (cantVecinosVivos(t, x) == 2 || cantVecinosVivos(t, x) == 3)) ||
    (!estaViva(t, x) && cantVecinosVivos(t, x) == 3))
        resp = true;
    else
        resp = false;

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
    for (int k = K; k > 0; k --)
        evolucionToroide(out);
    return out;
}

// EJERCICIO 7
bool esPeriodico(toroide const& t, int &p) {
    bool resp = false;
    p = 0;
    toroide toroideOut = t;
    while (!toroideMuerto(toroideOut) && !resp){
        p ++;
        evolucionToroide(toroideOut);
        if (t == toroideOut)
            resp = true;
    }
    return resp;
}

// EJERCICIO 8
bool primosLejanos(toroide const &t, toroide const &u) {
    bool resp = false;
    toroide genericoT = t;
    toroide genericoU = u;
    while (!toroideMuerto(genericoT) && !toroideMuerto(genericoU) && !resp){
        evolucionToroide(genericoT);
        evolucionToroide(genericoU);
        if ( genericoT == u || genericoU == t)
            resp = true;
    }
    return resp;
}

// EJERCICIO 9
int seleccionNatural(vector <toroide> ts) {
    int resp = -1;
    int mayorCantTicks = -1;
    for (int i = 0; i < ts.size(); i ++){
        toroide evoT = ts[i];
        int k = 0;
        while (!toroideMuerto(evoT)){
            evolucionToroide(evoT);
            k ++;
        }
        if (k > mayorCantTicks){
            resp = i;
            mayorCantTicks = k;
        }
    }
    return resp;
}


// EJERCICIO 10
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out (cantFilas(t), vector<bool>(cantColumnas(t)));
    for (int i = 0; i < cantFilas(t); i ++) {
        for (int j = 0; j < cantColumnas(t); j ++) {
            if (t[i][j] && u[i][j])
                out [i][j] = true;
            else
                out [i][j] = false;
        }
    }
    return out;
}

// EJERCICIO 11
bool vistaTrasladada(toroide const &t, toroide const &u){
    bool resp = false;
    for (int i = 0; i < cantFilas(t) && !resp ; ++i) {
        for (int j = 0; j < cantColumnas(t) ; ++j) {
            if (traslacion(t,i,j) == u)
                resp = true;
        }
    }
    return resp;
}

// EJERCICIO 12

int menorSuperficieViva(toroide const &t){
    int resp = areaTotal(t);
    for (int i = 0; i < t.size() ; ++ i) {
        for (int j = 0; j < t[0].size() ; ++ j) {
            if (resp > areaTotal(traslacion(t,i,j)))
                resp = areaTotal(traslacion(t,i,j));
        }
    }
    return resp;
}

