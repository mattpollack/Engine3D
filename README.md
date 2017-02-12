# Engine3D
3D Game Engine built with SFML, glew and OpenGL

![alt tag](http://i.imgur.com/ecJpW8S.png)

#### Design
The main design objective is to keep everything as simple as possible. The Math and Physics namespaces contain relevant math and physics. The Component namespace contains the abstract Component class and all it's derivatives. Including the Render.h file, and calling init, is all that's needed to create a Engine3D context.

#### Structure

Component
Entity
Math
Physics
Render
Scene
