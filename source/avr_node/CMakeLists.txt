add_executable(blink.elf src/main_blink.c)
add_executable(spi_master.elf src/main_spi_master.c)
add_executable(spi_slave.elf src/main_spi_slave.c)

if(CMAKE_CROSSCOMPILING)
    avr_executable_settings(blink)
    avr_executable_settings(spi_master)
    avr_executable_settings(spi_slave)
endif()

target_link_libraries(blink.elf PRIVATE avrhal)
target_link_libraries(spi_master.elf PRIVATE avrhal)
target_link_libraries(spi_slave.elf PRIVATE avrhal)
