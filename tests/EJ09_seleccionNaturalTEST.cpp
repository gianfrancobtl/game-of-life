#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;


TEST(seleccionNaturalTEST, toroideDiagonalVsUnoVivo){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, false, false}, 
                  {false, false, false}, 
                  {false, true, false},
                  {false, false, false}, 
                  {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

// Borramos el test propuesto "DiagonalVSHorizontal porque no cumplía con la especificación".

TEST(seleccionNaturalTEST, muerenALaVez){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

TEST(seleccionNaturalTEST, esperaResDifCero){
    toroide t1 = {{true, false, false},
                  {false, true, false},
                  {false, false, true}};
    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, true, false},
            {false, false, false},
            {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t2);
    ts.push_back(t2);
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t1);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 4);
}

