# LightUTest
Headeronly c++ unit test lib


main.cpp:
``` c++
#include "LightUTest.hpp"

int main(int argc, char *argv[]) {

    printf("Start test\n");
    LTest::TestUnit::Run();

    return 0;
}
```

*.cpp:
``` c++
#include "LightUTest.hpp"

#include <vector>

TEST_CASE(TestSTDVector, "std::vector", {
    std::vector<int> test1;
    test1.resize(3);
    TEST_ASSERT(test1.size() == 3);
});

```
