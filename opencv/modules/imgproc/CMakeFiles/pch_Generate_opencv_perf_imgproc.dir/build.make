# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /var/www/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /var/www/opencv/rebuild

# Utility rule file for pch_Generate_opencv_perf_imgproc.

# Include the progress variables for this target.
include modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc.dir/progress.make

modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc: modules/imgproc/perf_precomp.hpp.gch/opencv_perf_imgproc_RELEASE.gch

modules/imgproc/perf_precomp.hpp.gch/opencv_perf_imgproc_RELEASE.gch: ../modules/imgproc/perf/perf_precomp.hpp
modules/imgproc/perf_precomp.hpp.gch/opencv_perf_imgproc_RELEASE.gch: modules/imgproc/perf_precomp.hpp
modules/imgproc/perf_precomp.hpp.gch/opencv_perf_imgproc_RELEASE.gch: lib/libopencv_perf_imgproc_pch_dephelp.a
	$(CMAKE_COMMAND) -E cmake_progress_report /var/www/opencv/rebuild/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating perf_precomp.hpp.gch/opencv_perf_imgproc_RELEASE.gch"
	cd /var/www/opencv/rebuild/modules/imgproc && /usr/bin/cmake -E make_directory /var/www/opencv/rebuild/modules/imgproc/perf_precomp.hpp.gch
	cd /var/www/opencv/rebuild/modules/imgproc && /usr/bin/c++ -O3 -DNDEBUG -DNDEBUG "-D__OPENCV_BUILD=1" "-D_USE_MATH_DEFINES" "-D__STDC_CONSTANT_MACROS" "-D__STDC_LIMIT_MACROS" -I"/var/www/opencv/rebuild/3rdparty/ippicv/ippicv_lnx/include" -I"/var/www/opencv/rebuild" -I"/var/www/opencv/rebuild/3rdparty/ippicv/ippicv_lnx/include" -I"/var/www/opencv/rebuild" -I"/var/www/opencv/modules/ts/include" -I"/var/www/opencv/modules/imgproc/include" -I"/var/www/opencv/modules/imgcodecs/include" -I"/var/www/opencv/modules/core/include" -I"/var/www/opencv/modules/core/include" -I"/var/www/opencv/modules/imgproc/include" -I"/var/www/opencv/modules/imgcodecs/include" -I"/var/www/opencv/modules/videoio/include" -I"/var/www/opencv/modules/highgui/include" -I"/var/www/opencv/modules/imgproc/perf" -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -Wno-comment -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -ffunction-sections -msse -msse2 -msse3 -mssse3 -fvisibility=hidden -fvisibility-inlines-hidden -x c++-header -o /var/www/opencv/rebuild/modules/imgproc/perf_precomp.hpp.gch/opencv_perf_imgproc_RELEASE.gch /var/www/opencv/rebuild/modules/imgproc/perf_precomp.hpp

modules/imgproc/perf_precomp.hpp: ../modules/imgproc/perf/perf_precomp.hpp
	$(CMAKE_COMMAND) -E cmake_progress_report /var/www/opencv/rebuild/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating perf_precomp.hpp"
	cd /var/www/opencv/rebuild/modules/imgproc && /usr/bin/cmake -E copy_if_different /var/www/opencv/modules/imgproc/perf/perf_precomp.hpp /var/www/opencv/rebuild/modules/imgproc/perf_precomp.hpp

pch_Generate_opencv_perf_imgproc: modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc
pch_Generate_opencv_perf_imgproc: modules/imgproc/perf_precomp.hpp.gch/opencv_perf_imgproc_RELEASE.gch
pch_Generate_opencv_perf_imgproc: modules/imgproc/perf_precomp.hpp
pch_Generate_opencv_perf_imgproc: modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc.dir/build.make
.PHONY : pch_Generate_opencv_perf_imgproc

# Rule to build all files generated by this target.
modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc.dir/build: pch_Generate_opencv_perf_imgproc
.PHONY : modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc.dir/build

modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc.dir/clean:
	cd /var/www/opencv/rebuild/modules/imgproc && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_perf_imgproc.dir/cmake_clean.cmake
.PHONY : modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc.dir/clean

modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc.dir/depend:
	cd /var/www/opencv/rebuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/www/opencv /var/www/opencv/modules/imgproc /var/www/opencv/rebuild /var/www/opencv/rebuild/modules/imgproc /var/www/opencv/rebuild/modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/imgproc/CMakeFiles/pch_Generate_opencv_perf_imgproc.dir/depend

