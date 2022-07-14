cmake_minimum_required(VERSION 3.5)

project(Demod LANGUAGES CXX)

if(UNITTEST)
        add_subdirectory(googletests/)
endif()

add_subdirectory(sourse/libs/complex/)
add_subdirectory(sourse/libs/FileManager/)
add_subdirectory(sourse/libs/downsample/)
add_subdirectory(sourse/libs/Demodulator/)
add_subdirectory(sourse/libs/Filter/)
add_subdirectory(sourse/libs/matrix/)
add_subdirectory(sourse/libs/list/)
add_subdirectory(sourse/libs/myVec/)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_executable(Demod main.cpp)

target_link_libraries(${PROJECT_NAME} Complex)

target_link_libraries(${PROJECT_NAME} Demodulator)
