cmake_minimum_required(VERSION 3.10.0)
project(model_encryption)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_RELEASE "/MT")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output/lib)

file(COPY "${PROJECT_SOURCE_DIR}/include/paddle_model_encrypt.h" DESTINATION "${PROJECT_SOURCE_DIR}/output/include/")
file(COPY "${PROJECT_SOURCE_DIR}/include/paddle_model_decrypt.h" DESTINATION "${PROJECT_SOURCE_DIR}/output/include/")
file(COPY "${PROJECT_SOURCE_DIR}/include/paddle_stream_decrypt.h" DESTINATION "${PROJECT_SOURCE_DIR}/output/include/")
file(COPY "${PROJECT_SOURCE_DIR}/include/model_code.h" DESTINATION "${PROJECT_SOURCE_DIR}/output/include/")
file(COPY "${PROJECT_SOURCE_DIR}/include/deploy_declare.h" DESTINATION "${PROJECT_SOURCE_DIR}/output/include/")

include_directories("./")
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories("H:/bd/v14/thirdparty/gflags/include")
set(OPENSSL_ROOT_DIR "H:/bd/ctlung/thirdpart/openssl-1.1.0k/install-AMD64")
include_directories(${OPENSSL_ROOT_DIR}/include)
link_directories(${OPENSSL_ROOT_DIR}/lib)
link_directories("H:/bd/v14/thirdparty/gflags/lib")

set(OPENSSL_LIBS 
    libssl_static.lib
    libcrypto_static.lib
    shlwapi)

set(GFLAGS_LIBS
    gflags_static.lib
    gflags_nothreads_static.lib)

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ws2_32.lib /NODEFAULTLIB:libcmt.lib")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ws2_32.lib /NODEFAULTLIB:libcmt.lib")

aux_source_directory(util/src SRC_COMMON)
aux_source_directory(util/src/crypto SRC_COMMON)

# file(GLOB_RECURSE encrypt_model RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} )

add_library(pmodel-encrypt SHARED src/paddle_model_encrypt.cpp ${SRC_COMMON})
target_link_libraries(pmodel-encrypt ${OPENSSL_LIBS})

add_library(pmodel-decrypt SHARED src/paddle_model_decrypt.cpp ${SRC_COMMON})
target_link_libraries(pmodel-decrypt ${OPENSSL_LIBS})

add_library(pstream-decrypt SHARED src/paddle_stream_decrypt.cpp ${SRC_COMMON})
target_link_libraries(pstream-decrypt ${OPENSSL_LIBS})

file(GLOB_RECURSE decrypt_file RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} include/paddle_model_decrypt.h src/paddle_model_decrypt.cpp)
add_executable(decrypt_sample samples/model_decrypt_sample.cpp ${decrypt_file} ${SRC_COMMON})
target_link_libraries(decrypt_sample ${OPENSSL_LIBS} ${GFLAGS_LIBS})