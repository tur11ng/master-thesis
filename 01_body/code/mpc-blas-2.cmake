add_subdirectory(extern/mpc-blas)

add_executable(my_application my_application.cpp)
target_link_libraries(my_application STATIC MPC-BLAS::mpc-blas)