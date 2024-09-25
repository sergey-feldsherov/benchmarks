if(NOT BLA_VENDOR)
    message(STATUS "Using default BLA_VENDOR")
    set(BLA_VENDOR OpenBLAS)
endif()
message(STATUS "BLA_VENDOR is ${BLA_VENDOR}")

find_package(BLAS REQUIRED)

add_library(l2norm)
target_sources(l2norm PUBLIC l2norm.hpp PRIVATE l2norm.cpp)
target_link_libraries(l2norm PRIVATE ${BLAS_LIBRARIES})
target_compile_options(l2norm PRIVATE -march=native)

add_executable(bml2norm)

target_sources(bml2norm PUBLIC bml2norm.cpp)

target_link_libraries(bml2norm PRIVATE benchmark::benchmark l2norm)
