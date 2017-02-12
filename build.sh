#libsfml-graphics, libsfml-window and libsfml-system

echo "Compiling..."
g++ -std=c++14 \
./src/Component/*.cpp \
./src/Render/*.cpp \
./src/*.cpp \
-o ./build/game \
-lsfml-graphics -lsfml-window -lsfml-system \
-framework OpenGL -lglew
