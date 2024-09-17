set(BLA_VENDOR OpenBLAS)
find_package(BLAS REQUIRED)

add_executable(bmip)

target_sources(bmip PUBLIC bmip.cpp ipfun.h)

target_link_libraries(bmip PRIVATE benchmark::benchmark ${BLAS_LIBRARIES})
