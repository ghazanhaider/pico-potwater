cmake_minimum_required(VERSION 3.25)
include(pico_sdk_import.cmake)
project(potwater C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

#add_executable(potwater potwater.c wifi.c temp.c http_post.c)
add_executable(potwater potwater.c wifi.c http_post.c)

configure_file(potwater.c.in potwater.c)
configure_file(http_post.h.in http_post.h)
configure_file(http_post.c.in http_post.c)

target_include_directories(potwater PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
	#	/Users/haidegh/dev/rpi/pico-sdk/lib/lwip/src/include
        )

#target_compile_definitions(potwater PRIVATE
#		PICO_STACK_SIZE=0x2000
#	)

target_link_libraries(potwater pico_stdlib pico_cyw43_arch_lwip_threadsafe_background pico_lwip_http)
pico_enable_stdio_usb(potwater 1)
pico_enable_stdio_uart(potwater 0)

pico_add_extra_outputs(potwater)

#set(PICO_CXX_ENABLE_EXCEPTIONS 1)
#set(PICO_CXX_ENABLE_RTTI 1)

