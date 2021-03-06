project(gng)
cmake_minimum_required(VERSION 2.8)
SET(CMAKE_BUILD_TYPE RelWithDebInfo)

find_package(Qt4 REQUIRED)
find_package(OpenCV REQUIRED) # Hack because I need <cv.h> in the header of libgng
include(${QT_USE_FILE})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_subdirectory(libgng)
add_subdirectory(libaibo)

set(gng_image_sources image.cpp)

set(gng_imageseries_sources gngapp.cpp imageseries.cpp)
set(gng_imageseries_headers gngapp.h)

set(gng_camera_sources camera.cpp)

set(gng_aibo_sources aibo.cpp)
set(gng_aibo_webcam_sources aibowebcam.cpp)
set(gng_aibo_focus_sources aibofocus.cpp)
qt4_wrap_cpp(gng_abio_focus_mocs aibofocus.h)

qt4_wrap_cpp(gng_imageseries_mocs ${gng_imageseries_headers})
#qt4_wrap_ui(gng_imageseries_uic viewer.ui)

qt4_wrap_cpp(gng_imageviewer_mocs gngviewer.h)
add_library(gngviewer SHARED gngviewer.cpp ${gng_imageviewer_mocs})
target_link_libraries(gngviewer gng aibo ${QT_LIBRARIES})

add_executable(aibocam aibocam.cpp)
target_link_libraries(aibocam aibo ${QT_LIBRARIES})

qt4_wrap_ui(aiboremote_ui aiboremote.ui)
qt4_wrap_cpp(aiboremote_moc aiboremote.h)
add_executable(aiboremote aiboremote.cpp ${aiboremote_ui} ${aiboremote_moc})
target_link_libraries(aiboremote aibo ${QT_LIBRARIES})

add_executable(gng-image ${gng_image_sources})
target_link_libraries(gng-image gng gngviewer ${QT_LIBRARIES} ${Boost_PROGRAM_OPTIONS_LIBRARY})

add_executable(gng-imageseries ${gng_imageseries_sources} ${gng_imageseries_mocs})
target_link_libraries(gng-imageseries gng gngviewer ${QT_LIBRARIES} ${Boost_PROGRAM_OPTIONS_LIBRARY})

add_executable(gng-camera ${gng_camera_sources})
target_link_libraries(gng-camera gng gngviewer ${QT_LIBRARIES} ${Boost_PROGRAM_OPTIONS_LIBRARY})

# add_executable(gng-aibo ${gng_aibo_sources} ${gng_aibo_focus_sources} ${gng_abio_focus_mocs})
# target_link_libraries(gng-aibo aibo gngviewer ${QT_LIBRARIES} ${Boost_PROGRAM_OPTIONS_LIBRARY})

add_executable(gng-aibowebcam ${gng_aibo_webcam_sources} ${gng_aibo_focus_sources} ${gng_abio_focus_mocs})
target_link_libraries(gng-aibowebcam aibo gngviewer ${QT_LIBRARIES} ${Boost_PROGRAM_OPTIONS_LIBRARY})

# add_executable(gng-aibofocus ${gng_aibo_focus_sources})
# target_link_libraries(gng-aibo aibo gngviewer ${QT_LIBRARIES} ${Boost_PROGRAM_OPTIONS_LIBRARY})
