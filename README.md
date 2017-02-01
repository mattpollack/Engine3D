# Engine3D
3D Game Engine built with SFML, glew and OpenGL

![alt tag](http://i.imgur.com/ecJpW8S.png)

### Goals
 - Generate terrain based on player position
 - Move along terrain endlessly

### TODO
#### Renderer Goals:
 - Group objects by common meshes/shaders/textures to minimize resource binding calls, in order to maximize GPU concurrency.
 - Datatype that groups by multiple identifiers, and orders by least identifier group differences. O(1) find.
