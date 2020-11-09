

#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
int cantFilas (vector<vector<bool>> const &t);
int cantColumnas (vector<vector<bool>> const &t);
bool esRectangulo (toroide const &t);
bool estaViva(toroide const &t, posicion x);
bool posVecinaViva(toroide const &t, int f, int c, int i, int j);
int cantVecinosVivos (toroide const &t, posicion x);
bool toroideMuerto (toroide const &t);
toroide traslacion(toroide t, int a , int b );
bool filaTieneViva (vector<bool> n);
int primeraFilaViva (toroide t);
int ultimaFilaViva (toroide t);
int ultimaColumnaViva(toroide t);
int areaTotal (const toroide& t);

#endif //REUNIONESREMOTAS_AUXILIARES_H
