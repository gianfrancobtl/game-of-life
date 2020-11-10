#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(evolucionDePosicionTEST, toroideDiagonalTresPorTres){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, NoRevivePorCincoVecinosVivos){
    toroide t = { {false, true, true}, {false, true, false}, {false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,0)));
}

TEST(evolucionDePosicionTEST, PorDerecha){
    toroide t = { {false, true, true}, {false, true, false}, {false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,2)));
}

TEST(evolucionDePosicionTEST, ToroideMuerto){
    toroide t = { {false, false, false}, {false, false, false}, {false, false, false}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,2)));
}

TEST(evolucionDePosicionTEST, posFalsoVecinos3){
    toroide t = { {false, true, false}, {false, false, true}, {false, false, true}};
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, posFalsoVecinos4){
    toroide t = { {false, true, false}, {false, false, true}, {false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, posFalsoVecinos2){
    toroide t = { {false, false, false}, {false, false, true}, {false, true, false}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, posVerdaderoVecinos1){
    toroide t = { {false, true, false}, {false, true, false}, {false, false, false}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,1)));
}