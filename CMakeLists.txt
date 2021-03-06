cmake_minimum_required(VERSION 3.10)
project(QRGame)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(QRGame
        main.cpp
        src/game/Window.h src/InputManager.h src/game/Logic.h src/game/Player.h src/game/Wall.h src/game/Sprite.h
        src/IProcess.h src/QRGame.h src/Game.h src/ImageFactory.h src/QRReader.h
        src/image/CameraHandler.cpp src/image/CameraHandler.h
        src/Util.h src/memory/SharedMemoryVideo.h
        src/memory/SharedMemoryGame.h
        src/memory/SharedQueueGame.h src/memory/SharedMemoryVideo.h src/Logger.h
        src/memory/SharedQueueTimestamp.h
        )
target_link_libraries(QRGame ${CURSES_LIBRARIES} ${OpenCV_LIBS} rt pthread)