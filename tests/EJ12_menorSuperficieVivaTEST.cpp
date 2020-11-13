#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true, false, false, true},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, true, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

TEST(menorSuperficieVivaTEST, soloUnTrue){
    toroide t = {
            {false, false, false, false},   // 1
            {false, false, false, false}, // 2
            {false, true, false, false}, // 3
            {false, false, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 1);
}

TEST(menorSuperficieVivaTEST, todoTrue){
    toroide t = {
            {true, true, true, true},
            {true, true, true, true},
            {true, true, true, true}};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 12);
}
