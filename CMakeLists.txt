project(dump)

# Create a shared library
file(GLOB SOURCES src/*.cpp src/*.c)
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Ensure clients can find the includes
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Dependencies
set(LIB_DEPENDS common)
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIB_DEPENDS})
