find_package(Threads)
add_executable(LittleCrane main.c gpio.c stepper.c)
target_link_libraries(LittleCrane ${CMAKE_THREAD_LIBS_INIT})
include_directories(${PROJECT_SOURCE_DIR}/inc)