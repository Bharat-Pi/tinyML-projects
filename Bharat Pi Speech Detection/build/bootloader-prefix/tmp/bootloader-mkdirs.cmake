# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/hi/Documents/esp/esp-idf/components/bootloader/subproject"
  "C:/Users/hi/Documents/Arduino/BHARAT_PI/tensor_flow/esp-tflite-micro/examples/micro_speech/build/bootloader"
  "C:/Users/hi/Documents/Arduino/BHARAT_PI/tensor_flow/esp-tflite-micro/examples/micro_speech/build/bootloader-prefix"
  "C:/Users/hi/Documents/Arduino/BHARAT_PI/tensor_flow/esp-tflite-micro/examples/micro_speech/build/bootloader-prefix/tmp"
  "C:/Users/hi/Documents/Arduino/BHARAT_PI/tensor_flow/esp-tflite-micro/examples/micro_speech/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/hi/Documents/Arduino/BHARAT_PI/tensor_flow/esp-tflite-micro/examples/micro_speech/build/bootloader-prefix/src"
  "C:/Users/hi/Documents/Arduino/BHARAT_PI/tensor_flow/esp-tflite-micro/examples/micro_speech/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/hi/Documents/Arduino/BHARAT_PI/tensor_flow/esp-tflite-micro/examples/micro_speech/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/hi/Documents/Arduino/BHARAT_PI/tensor_flow/esp-tflite-micro/examples/micro_speech/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
