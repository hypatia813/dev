project(migrate)

set(TOP_DIR ${PROJECT_SOURCE_DIR})

include_directories(${TOP_DIR}/${PROJECT_NAME}/include
	${TOP_DIR}/${PROJECT_NAME}/src)

file(GLOB SRCS "${PROJECT_NAME}/src/*.cc")

set(BIN migrate_main)
add_executable(${BIN} ${PROJECT_NAME}_main.cc ${SRCS})
