option(${PROJECT_NAME}_Enable_TSAN off)
if (${${PROJECT_NAME}_Enable_TSAN})
  if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    
  else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
  endif ()
endif ()

option(${PROJECT_NAME}_Enable_ASAN off)
if (${${PROJECT_NAME}_Enable_ASAN})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined")
endif ()
