cmake_minimum_required(VERSION 3.22)

project(gaunt)

add_executable(gaunt gaunt.cpp)

target_include_directories(
    gaunt
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)


####################################################################################################
# Install
####################################################################################################

install(
    TARGETS gaunt
    RUNTIME DESTINATION bin
)

install(
    FILES ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include)

install(
    TARGETS gaunt
    LIBRARY DESTINATION lib
)

#config

install(
    FILES ${PROJECT_SOURCE_DIR}/config/gaunt.conf
    DESTINATION etc
)