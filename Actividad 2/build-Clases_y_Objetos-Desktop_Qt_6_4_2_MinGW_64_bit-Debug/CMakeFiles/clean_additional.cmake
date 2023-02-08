# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Clases_y_Objetos_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Clases_y_Objetos_autogen.dir\\ParseCache.txt"
  "Clases_y_Objetos_autogen"
  )
endif()
