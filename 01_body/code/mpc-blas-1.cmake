include(FetchContent)
FetchContent_Declare(
        mpc-blas
        GIT_REPOSITORY https://github.com/st1064870/mpc-blas.git
)
FetchContent_MakeAvailable(mpc-blas)

add_executable(my_application my_application.cpp)
target_link_libraries(my_application STATIC MPC-BLAS::mpc-blas)