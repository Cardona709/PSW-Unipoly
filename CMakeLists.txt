cmake_minimum_required(VERSION 3.8)

set(This Game)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(Headers
   include/logic/Board.h
   include/logic/Cards.h
   include/logic/Dice.h
   include/logic/Faculty.h
   include/logic/Game.h
   include/logic/Player.h
   include/logic/Property.h
   #include/logic/Server.h
   include/logic/Station.h
   include/logic/Utility.h
)
set(Sources
   src/logic/Board.cpp
   src/logic/Cards.cpp
   src/logic/Dice.cpp
   src/logic/Faculty.cpp
   src/logic/Game.cpp
   src/logic/Player.cpp
   src/logic/Property.cpp
   #src/logic/Server.cpp
   src/logic/Station.cpp
   src/logic/Utility.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(unit_test)