# CMake generated Testfile for 
# Source directory: /home/pcsdocker/Data/PCS/esercitazione5
# Build directory: /home/pcsdocker/Data/PCS/esercitazione5/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[mergesort]=] "/home/pcsdocker/Data/PCS/esercitazione5/build/test_merge")
set_tests_properties([=[mergesort]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/pcsdocker/Data/PCS/esercitazione5/CMakeLists.txt;14;add_test;/home/pcsdocker/Data/PCS/esercitazione5/CMakeLists.txt;0;")
add_test([=[quicksort]=] "/home/pcsdocker/Data/PCS/esercitazione5/build/test_quick")
set_tests_properties([=[quicksort]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/pcsdocker/Data/PCS/esercitazione5/CMakeLists.txt;17;add_test;/home/pcsdocker/Data/PCS/esercitazione5/CMakeLists.txt;0;")
add_test([=[hybridsort]=] "/home/pcsdocker/Data/PCS/esercitazione5/build/test_hybrid")
set_tests_properties([=[hybridsort]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/pcsdocker/Data/PCS/esercitazione5/CMakeLists.txt;20;add_test;/home/pcsdocker/Data/PCS/esercitazione5/CMakeLists.txt;0;")
