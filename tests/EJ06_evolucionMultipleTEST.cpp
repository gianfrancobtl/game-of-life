#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionMultipleTEST, toroideDiagonalTresPorTresUnPaso){
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
    toroide res = evolucionMultiple(t, 1);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroideMUERTO){
    toroide t = { {false, false, false}, {false, false, false}, {false, false, false}};

    toroide evo_t = { {false, false, false}, {false, false, false}, {false, false, false} };

    toroide res = evolucionMultiple(t, 5);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, seMuere){
    toroide t = { {false, false, false}, {false, true, false}, {false, false, false}};

    toroide evo_t = { {false, false, false}, {false, false, false}, {false, false, false} };

    toroide res = evolucionMultiple(t, 3);
    EXPECT_EQ(res, evo_t);
}