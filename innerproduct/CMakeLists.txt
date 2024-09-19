set(BLA_VENDOR OpenBLAS)
find_package(BLAS REQUIRED)

add_library(ip)
target_sources(ip PUBLIC ip.h PRIVATE ip.cpp)
target_link_libraries(ip ${BLAS_LIBRARIES})
target_compile_options(ip PRIVATE -march=native)

# TODO: that's for Clang, make some other way to change build flags
#target_compile_options(bmip PRIVATE -march=native -O3 -ffast-math)
#target_compile_options(bmip PRIVATE -march=native -Ofast)

add_executable(bmip)

target_sources(bmip PUBLIC bmip.cpp)

target_link_libraries(bmip PRIVATE benchmark::benchmark ip)

