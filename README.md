# SpaceCraft

This is 2D space craft game. Game software is developed via C++ using SFML. For more information about SFML please check the [link](https://www.sfml-dev.org/).


## Project Scheme

All source(.cpp) files are placed inside the source folder **src** and all header(.hpp) files are placed inside the folder **include**. Images that are used to render the textures are placed inside the folder **image**. Fonts that are used for diplaying message box text are placed inside the folder **fonts**. There is also **GameView** folder that contains some game scenes and gameplay videos. Besides there are also **Makefile** and **README** files.


## Build Instructions

If SFML is not available in your system, you need to install it before building the project. There is a **Makefile** to compile the source codes, link object files with SFML files and create the executable game file. To build the project go to root directory **SpaceCraft** and simply type below command:

**make**

During first build, all the source files will be compiled and the executable game file will be created. However in later builds, only the modified and dependent source files will be compiled again.

When building the project, object folder **obj** will be created and corresponding object files will be created under this folder. Then binary folder **bin** will be created and executable game file will be created under this folder after objects and SFML files are linked.

If you want to make a clean build by removing output folders and files, type below command:

**make clean**

This will remove **bin** and **obj** folders and all their contents. Then type **make** commmand again.

## Initial look

![View_1](https://user-images.githubusercontent.com/34675907/135908583-8330c8b5-6b11-46b1-9558-40a821f81225.png)

In progress!
