#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// Funciones auxiliares generales.
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
int cantFilas (vector<vector<bool>> const &t);
int cantColumnas (vector<vector<bool>> const &t);

// Auxiliar del ejercicio 1.
bool esRectangulo (toroide const &t);

// Auxiliares del ejercicio 4.
bool estaViva(toroide const &t, posicion x);
bool posVecinaViva(toroide const &t, int f, int c, int i, int j);
int cantVecinosVivos (toroide const &t, posicion x);

// Auxiliar del ejercicio 7.
bool toroideMuerto (toroide const &t);

// Auxiliar del ejercicio 11.
toroide traslacion(toroide t, int a , int b );

// Auxiliares del ejercicio 12.
bool filaTieneViva (vector<bool> n);
int primeraFilaViva (toroide t);
int ultimaFilaViva (toroide t);
int ultimaColumnaViva(toroide t);
int areaTotal (const toroide& t);

#endif //REUNIONESREMOTAS_AUXILIARES_H
