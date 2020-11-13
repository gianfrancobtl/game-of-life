#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}

TEST(densidadPoblacionTEST, toroideNormal){
    vector<bool> a = { false, true, false, true };
    vector<bool> b = { false, true, false, true };
    vector<bool> c = { false, true, false, true };
    toroide t = { a, b, c };
    EXPECT_NEAR(densidadPoblacion(t), 0.5, 0.01);
}

TEST(densidadPoblacionTEST, toroideMuerto){
    vector<bool> a = { false, false, false, false };
    vector<bool> b = { false, false, false, false };
    vector<bool> c = { false, false, false, false };
    toroide t = { a, b, c };
    EXPECT_NEAR(densidadPoblacion(t), 0, 0.01);
}

TEST(densidadPoblacionTEST, unaViva){
    vector<bool> a = { false, false, false, false };
    vector<bool> b = { false, false, false, false };
    vector<bool> c = { false, false, false, false };
    vector<bool> d = { false, false, false, false };
    vector<bool> e = { false, false, false, true };
    toroide t = { a, b, c, d, e };
    EXPECT_NEAR(densidadPoblacion(t), 0.05, 0.01);
}