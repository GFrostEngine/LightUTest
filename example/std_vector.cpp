#include "LightUTest.hpp"

#include <vector>

TEST_CASE(TestSTDVector, "std::vector", {
    std::vector<int> test1;
    test1.resize(3);
    TEST_ASSERT(test1.size() == 3);
});
