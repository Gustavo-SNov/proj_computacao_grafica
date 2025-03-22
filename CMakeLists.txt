cmake_minimum_required(VERSION 3.30)
project(projeto_comp_grafica)

set(CMAKE_CXX_STANDARD 17)

# Adiciona os diretórios das bibliotecas
include_directories(C:/libs_c++/GLFW/include C:/libs_c++/GLAD/include)
link_directories(C:/libs_c++/GLFW/lib C:/libs_c++/GLAD/lib)

add_executable(projeto_comp_grafica main.cpp C:/libs_c++/GLAD/src/glad.c)

# Linkando as bibliotecas
target_link_libraries(projeto_comp_grafica glfw3 opengl32 gdi32)
