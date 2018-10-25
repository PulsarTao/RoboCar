set(LIB_NAME rcmove)

set(SLIB_NAME lrcmove)
set(SOURCE_FILES src/rc_move/rcmove.cpp)
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
add_library(${SLIB_NAME} ${SOURCE_FILES})
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	target_link_libraries(${LIB_NAME} ${OpenCV_LIBS} rccv rcserial rclog)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
	target_link_libraries(${LIB_NAME} ${OPENCV_LIB}  lrccv lrcserial lrclog)
endif ()
