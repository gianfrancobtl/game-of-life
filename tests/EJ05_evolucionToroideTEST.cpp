#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionToroideTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {true, true, true}, {true, true, true}, {true, true, true} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroideTRUE){
    toroide t = { {true, true, true}, {true, true, true}, {true, true, true} };
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {false, false, false}, {false, false, false}, {false, false, false} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroideMUERTO){
    toroide t = { {false, false, false}, {false, false, false}, {false, false, false}};
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {false, false, false}, {false, false, false}, {false, false, false} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroideNORMAL){
    toroide t = {{true, false, false, true},
                 {false, false, false, true},
                 {true, true, true, false},
                 {false, false, false, false}};

    toroide evo_t = { {true, false, false, true},
                      {false, false, false, false},
                      {true, true, true, true},
                      {false, false, true, false} };
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}