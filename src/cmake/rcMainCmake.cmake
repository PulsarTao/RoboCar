set(EXE_NAME RoboCar)
set(SOURCE_FILES src/rc_main/main.cpp)
include_directories(src/include)
add_executable(${EXE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXE_NAME} ${OpenCV_LIBS}  rctask)
