project(libobjreader)

SET(LIBOBJREADER_VERSION 0.1+devel)
SET(PROJECT_NAME libobjreader)

include_directories(${libobjreader_SOURCE_DIR} 
                    ${PROJECT_SOURCE_DIR}/../include)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(MtlParser 
             mtl.y 
             ${CMAKE_CURRENT_BINARY_DIR}/mtlparser.y.c)

FLEX_TARGET(MtlScanner 
            mtl.l
            ${CMAKE_CURRENT_BINARY_DIR}/mtlscanner.l.c)

BISON_TARGET(ObjParser 
             wavefrontobj.y 
             ${CMAKE_CURRENT_BINARY_DIR}/objparser.y.c)

FLEX_TARGET(ObjScanner 
            wavefrontobj.l
            ${CMAKE_CURRENT_BINARY_DIR}/objscanner.l.c)


ADD_FLEX_BISON_DEPENDENCY(MtlScanner MtlParser)
ADD_FLEX_BISON_DEPENDENCY(ObjScanner ObjParser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(objreader
            ${BISON_MtlParser_OUTPUTS}
            ${FLEX_MtlScanner_OUTPUTS}
            ${BISON_ObjParser_OUTPUTS}
            ${FLEX_ObjScanner_OUTPUTS})

install(TARGETS objreader
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

FILE(GLOB files "${PROJECT_SOURCE_DIR}/../include/objreader/*.h")
INSTALL(FILES ${files} DESTINATION include/objreader)

