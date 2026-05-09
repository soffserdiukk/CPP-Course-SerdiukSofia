cmake_minimum_required(VERSION 3.20)
project(CPP_Course_SerdiukSofia)

# Налаштування кодування для коректного виводу кирилиці
add_compile_options("-finput-charset=UTF-8" "-fexec-charset=UTF-8")

set(CMAKE_CXX_STANDARD 17)

include_directories(practices/practice_15)

add_executable(practice_15
        practices/practice_15/main15.cpp
        practices/practice_15/Point.cpp
        practices/practice_15/Point.h
        practices/practice_15/Polinom.cpp
        practices/practice_15/Polinom.h
        practices/practice_15/Rational.cpp
        practices/practice_15/Rational.h
)


add_executable(homework_15
        homeworks/homework_15/main15_h.cpp
        homeworks/homework_15/Rectangle.cpp
        homeworks/homework_15/Rectangle.h
)

add_executable(practice_16
        practices/practice_16/main16.cpp
        practices/practice_16/Person.cpp
        practices/practice_16/Person.h
        practices/practice_16/Friend.cpp
        practices/practice_16/Friend.h
        practices/practice_16/PhoneBook.cpp
        practices/practice_16/PhoneBook.h
)

add_executable(homework_16
        homeworks/homework_16/main16_h.cpp
        homeworks/homework_16/Figure3D.cpp
        homeworks/homework_16/Figure3D.h
)

add_executable(practice_17
        practices/practice_17/main17.cpp
        practices/practice_17/Person.cpp
        practices/practice_17/Person.h
)

add_executable(homework_17
        homeworks/homework_17/main17_h.cpp
        homeworks/homework_17/Int24.cpp
        homeworks/homework_17/Int24.h
)

add_executable(practice_18_1
        practices/practice_18/task_18.1.cpp
        practices/practice_15/Rational.cpp
)

add_executable(practice_18_2
        practices/practice_18/task_18.2.cpp
        practices/practice_15/Rational.cpp
)

add_executable(homework_18_5
        homeworks/homework_18/task_18.5.cpp
        practices/practice_15/Rational.cpp
)

add_executable(homework_18_7
        homeworks/homework_18/task_18.7.cpp
        practices/practice_15/Rational.cpp
)

add_executable(homework_5 homeworks/homework_5.cpp)
add_executable(practice_5 practices/practice_5.cpp)
add_executable(practice_7 practices/practice_7.cpp)
add_executable(homework_7 homeworks/homework_7.cpp)
add_executable(practice_8 practices/practice_8.cpp)
add_executable(homework_8 homeworks/homework_8.cpp)
add_executable(practice_9 practices/practice_9.cpp)
add_executable(homework_9 homeworks/homework_9.cpp)
add_executable(practice_10 practices/practice_10.cpp)
add_executable(practice_10_1 practices/practice_10_1.cpp practices/rational.cpp)
add_executable(homework_10 homeworks/homework_10.cpp
        practices/practice_17/Person.cpp
        practices/practice_17/Person.h)
add_executable(practice_12 practices/practice_12.cpp)
add_executable(homework_12 homeworks/homework_12.cpp)
add_executable(practice_13 practices/practice_13.cpp)
add_executable(homework_13 homeworks/homework_13.cpp)
