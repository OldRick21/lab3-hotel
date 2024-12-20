cmake_minimum_required(VERSION 3.10)
project(HotelManagement)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0
)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 17)

# Убедитесь, что компилятор поддерживает опции покрытия
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

add_executable(HotelManagement ${SOURCES})

# Добавление тестов
enable_testing()

# Правильно включите необходимые заголовки для тестирования
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

# Создайте отдельный список исходных файлов для тестов, исключив src/main.cpp
set(TEST_LIBRARY_SOURCES)
foreach(SOURCE_FILE ${SOURCES})
    if(NOT "${SOURCE_FILE}" STREQUAL "${CMAKE_SOURCE_DIR}/src/main.cpp")
        list(APPEND TEST_LIBRARY_SOURCES ${SOURCE_FILE})
    endif()
endforeach()

# Создайте отдельный исполняемый файл для тестов
add_executable(HotelManagementTests ${TEST_SOURCES} ${TEST_LIBRARY_SOURCES})
target_link_libraries(HotelManagementTests Catch2::Catch2)

# Добавьте тест в CTest
add_test(NAME HotelManagementTests COMMAND HotelManagementTests)

