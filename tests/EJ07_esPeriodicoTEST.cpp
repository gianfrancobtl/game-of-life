#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(esPeriodicoTEST, toroideHorizontalPeriodico2){
    toroide t = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

TEST(esPeriodicoTEST, cuadrado){
    toroide t = {
            {false, false, false, false, false},
            {false, false, true, true, false},
            {false, false, true, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 1);
}

TEST(esPeriodicoTEST, dimensionesGrandes){
    toroide t = {
            {false, false,false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, true, false, false, false, false, false},
            {false, false, false, false, false, true, false, false, false, false, false},
            {false, false, false, false, false, true, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false},
            {false, true,  true, true, false, false, false, true, true, true, false},
            {false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, true, false, false, false, false, false},
            {false, false, false, false, false, true, false, false, false, false, false},
            {false, false, false, false, false, true, false, false, false, false, false},
            {false, false, false, false, false, false ,false, false, false, false, false}
    };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

TEST(esPeriodicoTEST, toroideMuere){
    toroide t = {
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, false, true, false},
            {false, false, false, false, false},
            {false, false, false, false, false}
    };
    int p = 1000;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, 1000);
}

TEST(esPeriodicoTEST, toroideMuereEnMasDeUnTick){
    toroide t = {
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, true, false, true, false, false, false, false, false},
            {false, false, false, false, true, false, true, false, false, false, false, false},
            {false, false, false, false, true, true, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false}
    };
    int p = 9;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, 9);
}

TEST(esPeriodicoTEST, toroideTodoFalso) {
    toroide t = {{false, false, false},
                 {false, false, false},
                 {false, false, false}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 0);
}