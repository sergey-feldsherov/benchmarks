add_executable(bmip)

target_sources(bmip PUBLIC bmip.cpp ipfun.h)

target_link_libraries(bmip PRIVATE benchmark::benchmark)
