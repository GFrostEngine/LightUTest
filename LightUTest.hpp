#include <memory>
#include <iostream>
#include <assert.h>
#include <map>
#include <functional>
#include <utility>

namespace LTest{

    struct TestUnit {
        struct Unit{

            int line = 0;
            const char* file;
            std::function<void(Unit&)> function;

            int errs = 0;
        };

        inline static std::map<std::string, Unit> funcs_{};

        static void Run() {

            int err_count = 0;
            int done_count = 0;

            for (auto& func : TestUnit::funcs_) {

                auto err_tmp = func.second.errs;
                func.second.function(func.second);
                if (func.second.errs > err_tmp) {
                    printf("Error in section: %s, in file %i,%s\n", func.first.c_str(),
                           func.second.line, func.second.file);
                    err_count += func.second.errs;
                }
                else
                    done_count++;
            }

            if (err_count > 0)
                assert(0 && "Test is crashed");
            else
                printf("Test done! %i/%i", done_count, done_count);
        }
    };

}

#define TEST_CASE(unigueName, section, ...) \
auto (unigueName) = LTest::TestUnit::funcs_[section] = LTest::TestUnit::Unit(__LINE__, __FILE__, [](LTest::TestUnit::Unit& unit) {__VA_ARGS__})

#define TEST_ASSERT(expression) if (!(expression)) { unit.errs++; printf("assert(%s). in file %i,%s\n", #expression, __LINE__, __FILE__); }
#define TEST_ASSERT_COMENT(expression, text) if (!(expression)) { unit.errs++; printf("assert(%s). %s - in file %i,%s\n", #expression, text, __LINE__, __FILE__); }
