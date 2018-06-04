# tral-qml


### Introduction

`tral-qml` at the moment is just an example of C++, CMake and QML integration.

Written in C++ using Qt 5 framework with CMake.


### How to install (you will need CMake and Qt5 installed)

```
 1. (make directory for binary): mkdir <directory-name>
 2. (enter created directory):   cd <directory-name>
 3. (to bind with your Qt repo): export CMAKE_PREFIX_PATH=<Qt-path>/Qt5.10.1/5.10.1-mingw64/lib/cmake/
 4. (make the asseble):          cmake <tral-qml-path>
 5. (just type):                 make
 6. If your Qt assembled dinamycally you may need to copy Qt dll`s to your binary directory.
```


### License

![](http://www.gnu.org/graphics/lgplv3-147x51.png)

Copyright (C) 2018 tremr

This library is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library. If not, see <http://www.gnu.org/licenses/>.
