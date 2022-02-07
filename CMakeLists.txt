cmake_minimum_required(VERSION 3.10.0)
project(model_encryption)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_RELEASE "/MT")

include_directories("./")
include_directories(${PROJECT_SOURCE_DIR}/include)
set(OPENSSL_ROOT_DIR "H:/bd/ctlung/thirdpart/openssl-1.1.0k/install-AMD64")
include_directories(${OPENSSL_ROOT_DIR}/include)
link_directories(${OPENSSL_ROOT_DIR}/lib)

set(OPENSSL_LIBS 
    libssl_static.lib
    libcrypto_static.lib
    shlwapi)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ws2_32.lib /NODEFAULTLIB:libcmt.lib")

aux_source_directory(util/src SRC_COMMON)
aux_source_directory(util/src/crypto SRC_COMMON)

# file(GLOB_RECURSE encrypt_model RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} )

add_library(paddle_model_encrypt SHARED src/paddle_model_encrypt.cpp ${SRC_COMMON})
target_link_libraries(paddle_model_encrypt ${OPENSSL_LIBS})