add_executable (${PROJECT_NAME} main.cpp Brain.cpp Block.hpp Word.cpp Letter.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})
