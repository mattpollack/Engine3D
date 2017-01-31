#libsfml-graphics, libsfml-window and libsfml-system

g++ -std=c++14 \
./src/Maths/*.cpp \
./src/Object/*.cpp \
./src/Texture/*.cpp \
./src/Shader/*.cpp \
./src/*.cpp \
-o ./build/game \
-lsfml-graphics -lsfml-window -lsfml-system \
-framework OpenGL -lglew
