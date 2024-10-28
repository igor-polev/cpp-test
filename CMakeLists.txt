cmake_minimum_required(VERSION 3.5.0)

project(cpp-test VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_library(
    LIBBITCOIN 
    NAMES libbitcoin-system bitcoin-system
    REQUIRED
)

find_library(
    LIBSECP 
    NAMES secp256k1
    REQUIRED
)

# failed to make find_library() work for libbech32
set(LIBBECH_INCLUDE /opt/contract.design/libbech32/include/libbech32)
set(LIBBECH_LIB /opt/contract.design/libbech32/lib/libbech32.a)

find_package(
    Boost
    1.78.0 EXACT
    COMPONENTS program_options json
    REQUIRED
)

set(Qt6_DIR /opt/Qt/6.8.0/gcc_64/lib/cmake/Qt6)
find_package(
    Qt6
    COMPONENTS Core Gui Widgets
    REQUIRED
)

qt_standard_project_setup()

qt_add_executable(btc
    src/main.cpp
    src/mainwindow.cpp
    src/btc_func.cpp
    src/btc_public.cpp
    src/btc_address.cpp
    src/btc_key.cpp
)

target_include_directories(btc
    PRIVATE
    ${LIBBECH_INCLUDE}
    # Quick-fix for header not found
    /opt/Qt/6.8.0/gcc_64/include/QtWidgets
)

target_link_libraries(btc
    PRIVATE
    ${LIBBITCOIN}
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    ${Boost_JSON_LIBRARY}
    ${LIBSECP}
    ${LIBBECH_LIB}
    ${Boost_LIBRARIES}
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

add_executable(test
    src/test.cpp
    src/btc_func.cpp
    src/btc_public.cpp
    src/btc_address.cpp
    src/btc_key.cpp
)

target_include_directories(test
    PRIVATE
    ${LIBBECH_INCLUDE}
)

target_link_libraries(test
    PRIVATE
    ${LIBBITCOIN}
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    ${Boost_JSON_LIBRARY}
    ${LIBSECP}
    ${LIBBECH_LIB}
    ${Boost_LIBRARIES}
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)