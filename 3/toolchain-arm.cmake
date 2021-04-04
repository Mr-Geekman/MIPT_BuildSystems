SET(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Without that flag CMake is not able to pass test compilation check
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_AR                        ${ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-ar)
set(CMAKE_ASM_COMPILER              ${ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_C_COMPILER                ${ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER              ${ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-g++)
set(CMAKE_LINKER                    ${ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-ld)
set(CMAKE_OBJCOPY                   ${ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-objcopy CACHE INTERNAL "")
set(CMAKE_RANLIB                    ${ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-ranlib CACHE INTERNAL "")
set(CMAKE_SIZE                      ${ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-size CACHE INTERNAL "")
set(CMAKE_STRIP                     ${ARM_TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-strip CACHE INTERNAL "")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
