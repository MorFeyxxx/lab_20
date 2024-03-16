add_library(data_structures
        bitset/bitset.c
        bitset/bitset.h
        unordered_array_set/unordered_array_set.h
        unordered_array_set/unordered_array_set.c
        ordered_array_set/ordered_array_set.c
        ordered_array_set/ordered_array_set.h
        vector/vector.h
        vector/vector.c
        vectorVoid/vectorVoid.c
        vectorVoid/vectorVoid.h
        matrix/matrix.h
        matrix/matrix.c
)

target_link_libraries(data_structures algorithms)