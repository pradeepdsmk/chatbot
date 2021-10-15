add_executable (${PROJECT_NAME} main.cpp Brain.cpp Cell.hpp Word.cpp Letter.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})
