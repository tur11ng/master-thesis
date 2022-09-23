include(FetchContent)
FetchContent_Declare(
        mpc-blas
        GIT_REPOSITORY https://github.com/st1064870/mpc-blas.git
)
FetchContent_MakeAvailable(mpc-blas)