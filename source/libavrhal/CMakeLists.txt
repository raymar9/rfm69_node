file(GLOB_RECURSE LIBAVRHAL_SRC_FILES "*.c")

add_library(avrhal STATIC ${LIBAVRHAL_SRC_FILES})
target_include_directories(avrhal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(CMAKE_CROSSCOMPILING)
    avr_library_settings(avrhal)
endif()