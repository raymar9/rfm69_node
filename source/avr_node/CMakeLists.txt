file(GLOB_RECURSE AVR_NODE_SRC_FILES "*.c")

add_executable(avr_node.elf ${AVR_NODE_SRC_FILES})

if(CMAKE_CROSSCOMPILING)
    avr_executable_settings(avr_node)
endif()