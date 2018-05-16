if (RC_TEST)
include_directories(src/include)

set(SERIAL_TEST src/rc_test/rc_serial_test.cpp)
add_executable(rc_serial_test ${SERIAL_TEST})
target_link_libraries(rc_serial_test rcserial rclog)

set(CV_TEST src/rc_test/rc_cv_test.cpp)
add_executable(rc_cv_test ${CV_TEST})
target_link_libraries(rc_cv_test ${OpenCV_LIBS} rccv rclog)

set(VLC_TEST src/rc_test/rc_vlc_test.cpp)
add_executable(rc_vlc_test ${VLC_TEST})
target_link_libraries(rc_vlc_test ${OpenCV_LIBS} rccv rclog)
endif ()
