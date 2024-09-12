add_executable(bmpow2rd)

target_sources(bmpow2rd
    PUBLIC
        bmpow2rd.cpp
    PRIVATE
        pow2rd.h
)

target_link_libraries(bmpow2rd PRIVATE benchmark::benchmark)
