# Snake-Ladder
## Chapter 1 :
### 1. INTRODUCTION
We are developing a snake game using openGL. It is a game written in C language
using openGL based on the game called 'snake' which has been around since the
earliest days of home computing and has re-emerged in recent years on mobile
phones. The game graphics will be in 2D format. The snake is offered food at
random places and it has to eat it. As it goes on eating, its size increases. It has to
eat the food making sure it does not eat itself, in which case it dies.
### 1.1 Aim
To develop a game “Snakes and Ladders” in which two two players can play the
game without any physical board.
The player should make use of graphical dice instead of any physical dice.
To develop this game we are going to use OpenGL a low-level Graphics rendering
API which generates better quality color images composed of geometric and image
primitives.
### 1.2 Objectives and Scope
This game was one of the first game we played in our childhood so converting this
game from a physical board game to the graphical game in which a player can
actually get a feel of that game was our objective. We tried to make it realistic in
every possible way.
To replace with physical dice board so that we can save the paper and contribute to
the environment. To use general concept of c language and openGL to develop a
simple snakes and ladders game that as a whole entertains the user.
### 1.3 Introduction to Project
### PROBLEM STATEMENT: To develop a game “Snakes and Ladders” using OpenGL.
Snakes and Ladders is an ancient Indian board game regarded today as a
worldwide classic.
It is played between two or more players on a gameboard having numbered,
gridded squares.
A number of "ladders" and "snakes" are pictured on the board, each connecting
two specific board squares.
The object of the game is to navigate one's game piece, according to die rolls, from
the start (bottom square) to the finish (top square), helped or hindered by ladders
and snakes respectively.
The game is a simple race contest based on sheer luck and is popular with young
children.
It has been originally used to teach children about good and bad as ladders
represented good deeds and snakes punishment for the bad. Nowadays, though, the
game does not carry any ethical or religious meaning.
### 1.4 Introduction to OpenGL
OpenGL (Open Graphics Library) is a cross-platform, hardware-accelerated,
language-independent, industrial standard API for producing 3D (including 2D)
graphics. Modern computers have dedicated GPU (Graphics Processing Unit) with
its own memory to speed up graphics rendering. OpenGL is the software interface
to graphics hardware. In other words, OpenGL graphic rendering commands issued
by your applications could be directed to the graphic hardware and accelerated.
We use 3 sets of libraries in our OpenGL programs:

**1. Core OpenGL (GL)**: consists of hundreds of commands, which begin with a
prefix "gl" (e.g., glColor, glVertex, glTranslate, glRotate). The Core OpenGL
models an object via a set of geometric primitives such as point, line and polygon.

**2. OpenGL Utility Library (GLU)**: built on-top of the core OpenGL to provide
important utilities (such as setting camera view and projection) and more building
models (such as qradric surfaces and polygon tessellation). GLU commands start
with a prefix "glu" (e.g., gluLookAt, gluPerspective).

**3. OpenGL Utilities Toolkit (GLUT)**: OpenGL is designed to be independent of
the windowing system or operating system. GLUT is needed to interact with the
Operating System (such as creating a window, handling key and mouse inputs); it
also provides more building models (such as sphere and torus). 
GLUT commands start with a prefix of "glut" (e.g., glutCreatewindow, glutMouseFunc). GLUT is
platform independent, which is built on top of platform-specific OpenGL extension
such as GLX for X Window System, WGL for Microsoft Window, and AGL, CGL
or Cocoa for Mac OS. Large applications requiring sophisticated user interfaces are better off using native
window system toolkits. GLUT is simple, easy, and small.

## Chapter 2 :
### 2. IDENTIFICATION OF DIFFERENT GARPHICS OBJECT USED
### 2.1 Graphics object required of project:
```
1. Square: Used in designing the base of Game. The platform consists of rows and columns.
2. Ellipse : Used in designing the head of Snake.
3. Rectangle: Used in designing the structure of Board
```
### 2.2 Primitives and functions used for the project
```
1.glLineLoop(): for making the background grid for snake to move.
2.GLLINES(): for making snake body
3.GlQuads(): for making grid boxes
4.Reshape(): callback function
5.Timer(): callback function
6.Glvertex2d(): for drawing vertex
7. glClear(): for clearing buffer
8. glClearColor():for coloring buffer
9.glColor3f(): for coloring objects
10. glutMainLoop():calling callback functions
```
## Chapter 3 :
### 3. Software Design
![image](https://user-images.githubusercontent.com/40235251/140655875-48c9f88a-4431-4f0a-a3f6-0f56dee860f4.png)
## Chapter 4 :
### Game Interface

![Screenshot from 2021-11-07 23-23-52](https://user-images.githubusercontent.com/40235251/140656457-83f0e12c-6d15-40b2-805c-dd1c21e4792b.png)


![Screenshot from 2021-11-07 23-31-00](https://user-images.githubusercontent.com/40235251/140656419-266d8a28-0bd2-41ba-87f9-1847ca98856b.png)


![Screenshot from 2021-11-07 23-28-37](https://user-images.githubusercontent.com/40235251/140656424-807fb6f6-eee0-4cb3-90fb-738093971386.png)

