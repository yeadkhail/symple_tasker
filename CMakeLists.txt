cmake_minimum_required(VERSION 3.24)
project(symple_tasker)

set(CMAKE_CXX_STANDARD 17)

add_executable(symple_tasker main.cpp functions/sources/core/Task/Task.cpp headers/Task.h functions/sources/core/PathManager/PathManager.cpp headers/PathManager.h functions/sources/core/visuals/Visuals.cpp headers/Visuals.h functions/sources/crypto/base64/base64.cpp headers/base64.h)
