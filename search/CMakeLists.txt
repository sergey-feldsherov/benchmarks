add_executable(bmsearch)

target_sources(bmsearch
    PUBLIC
        bmsearch.cpp
    PRIVATE
        search.hpp
)

target_link_libraries(bmsearch PRIVATE benchmark::benchmark)
