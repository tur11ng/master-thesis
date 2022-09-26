include(FetchContent)
FetchContent_Declare(
  ABY
  GIT_REPOSITORY https://github.com/encryptogroup/ABY.git
)
FetchContent_MakeAvailable(ABY)

add_executable(my_application my_application.cpp)
target_link_libraries(my_application ABY::aby)