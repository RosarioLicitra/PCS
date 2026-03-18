# Versione minima di CMake necessaria per compilare il progetto. Nel nostro caso
# specifichiamo 3.20
cmake_minimum_required(VERSION 3.20)

# Specifico il nome del progetto software
project(esercitazione_1) 

# Specifico la versione di C++ che voglio
# sia usata per la compilazione. Utilizzo C++20, ovvero la versione
# standardizzata nel 2020
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Imposto il livello di Warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

# Dichiaro l'eseguibile che voglio produrre 
add_executable(es1 es1.cpp)
add_executable(es2 es2.cpp)
