project(libgng)
cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED)
find_package(OpenCV REQUIRED)
include(${QT_USE_FILE})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(libgng_sources
        point.cpp
        imagesource.cpp
	camerasource.cpp
        aibosource.cpp
        node.cpp
        edge.cpp
        subgraph.cpp
        gng.cpp
        )

set(libgng_headers
#     point.h
#     imagegenerator.h
#     node.h
#     edge.h
    camerasource.h
    aibosource.h
    gng.h
    )

qt4_wrap_cpp(libgng_mocs ${libgng_headers})

add_executable(opencvtest opencvtest.cpp)
target_link_libraries(opencvtest ${OpenCV_LIBS})

add_library(gng SHARED ${libgng_sources} ${libgng_mocs})
target_link_libraries(gng aibo ${QT_LIBRARIES} ${OpenCV_LIBS})
