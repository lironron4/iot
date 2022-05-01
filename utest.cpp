#include "../../inc/mu_test.h"

#include "smart_home_server.hpp"

BEGIN_TEST(something)
    std::ifstream file("test.txt");
    smarthome::Server s(file);
    ASSERT_PASS();
END_TEST

BEGIN_SUITE(smarthome)
    TEST(something)
END_SUITE    