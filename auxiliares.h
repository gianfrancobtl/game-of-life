

#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
int cantFilas (vector<vector<bool>> const &t);
int cantColumnas (vector<vector<bool>> const &t);
bool esRectangulo (vector<vector<bool>> const &t);
bool vecinaViva(toroide t , int z , int c , int i , int j);
int vecinosVivos(toroide t, int f , int c);
bool toroideMuerto (toroide const &t);
toroide traslacion(toroide t, int a , int b );


#endif //REUNIONESREMOTAS_AUXILIARES_H
