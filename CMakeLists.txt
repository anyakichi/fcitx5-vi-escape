cmake_minimum_required(VERSION 3.15)
project(fcitx5-vi-escape VERSION 0.1.0 LANGUAGES CXX)

find_package(Fcitx5Core REQUIRED)

add_subdirectory(src)

configure_file(${CMAKE_SOURCE_DIR}/vi-escape.conf.in
               ${CMAKE_BINARY_DIR}/vi-escape.conf @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/vi-escape.conf
        DESTINATION ${FCITX_INSTALL_PKGDATADIR}/addon)
