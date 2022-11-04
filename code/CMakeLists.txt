
cmake_minimum_required(VERSION 3.13) # CMAKE (heading)
include(pico_sdk_import.cmake) # CMAKE -> PICO SDK (include)

project(button_interface C CXX ASM) # CMAKE ("project")
pico_sdk_init() # PICO SDK (initialization)

add_executable(button_interface) # CMAKE (target)

pico_generate_pio_header(button_interface ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}) # PICO SDK (PIO)

target_sources(button_interface PRIVATE Button_Interface.c pixel.c pushbutton.c sio_registers.c) # CMAKE -> C (compiler)
target_link_libraries(button_interface PRIVATE pico_stdlib hardware_pio) # CMAKE -> C (linker)

pico_enable_stdio_usb(button_interface 1) # PICO SDK (USB)
pico_enable_stdio_uart(button_interface 0) # PICO SDK (USB)

pico_add_extra_outputs(button_interface) # PICO SDK (UF2)