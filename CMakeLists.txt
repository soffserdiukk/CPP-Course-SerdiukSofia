cmake_minimum_required(VERSION 3.10)
project(CPP_Course_SerdiukSofia)
add_compile_options("-finput-charset=UTF-8" "-fexec-charset=UTF-8")

set(CMAKE_CXX_STANDARD 14)

add_executable(homework_5 homeworks/homework_5.cpp)
add_executable(practice_5 practices/practice_5.cpp)
add_executable(practice_7 practices/practice_7.cpp)
add_executable(homework_7 homeworks/homework_7.cpp)
add_executable(practice_8 practices/practice_8.cpp)
add_executable(homework_8 homeworks/homework_8.cpp)
add_executable(practice_9 practices/practice_9.cpp)
add_executable(homework_9 homeworks/homework_9.cpp)
add_executable(practice_10 practices/practice_10.cpp
        practices/practice_13.cpp)
add_executable(practice_10_1 practices/practice_10_1.cpp practices/rational.cpp)
add_executable(rational.cpp practices/rational.cpp)
add_executable(homework_10 homeworks/homework_10.cpp)
add_executable(practice_12 practices/practice_12.cpp)
add_executable(homework_12 homeworks/homework_12.cpp)
add_executable(practice_13 practices/practice_13.cpp)
add_executable(homework_13 homeworks/homework_13.cpp)


configure_file(practices/input_12_4.txt input_12_4.txt COPYONLY)
configure_file(practices/input_12_5.txt input_12_5.txt COPYONLY)
configure_file(homeworks/input_12_15.txt input_12_15.txt COPYONLY)
