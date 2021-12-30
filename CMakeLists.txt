add_executable(main main.cpp)

add_subdirectory(ListGraph)
add_subdirectory(MatrixGraph)
add_subdirectory(SetGraph)
add_subdirectory(ArcGraph)
target_link_libraries(main LINK_PUBLIC ListGraph MatrixGraph SetGraph ArcGraph)