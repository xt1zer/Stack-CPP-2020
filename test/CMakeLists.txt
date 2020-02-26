project(Stack-CPP-2020_test)

add_executable(Stack-CPP-2020_test testMain.cpp stackTest.cpp)

target_link_libraries(Stack-CPP-2020_test gtest gtest_main pthread)
