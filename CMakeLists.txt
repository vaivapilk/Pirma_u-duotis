cmake_minimum_required(VERSION "3.12.1")

project(Pirma_uzduotis)

add_executable(Pirma_uzduotis main.cpp pagalb_funkcijos.cpp vart_ived.cpp struct.h pagalb_funkcijos.h vart_ivedimas.h)

install(TARGETS Pirma_uzduotis DESTINATION bin)