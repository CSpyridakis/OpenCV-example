# OpenCV-example ![MIT license](https://img.shields.io/github/license/CSpyridakis/OpenCV-example.svg?style=plastic) 
This is a demo, 'hello world' like, [OpenCV](https://opencv.org/) project usign C++. 

You can use it to check that the library is properly installed in your Linux setup.

## Structure
Follows basic C++ project tree structure
* <b>include/</b> folder is used for header files
* <b>src/</b> dir for source files

## Usage
Run `./handle -h` to see all available options. `handle` script is responsible to handle  actions such as build, clean and run.

E.g. In order to build project just run: `./handle -b`

## Notes
1. To install [OpenCV](https://opencv.org/) on your Linux system visit [this](https://docs.opencv.org/master/df/d65/tutorial_table_of_content_introduction.html) link, or download and run [this](https://raw.githubusercontent.com/CSpyridakis/SCTT/master/shellScripts/Debian/install-opencv-debian-x86.sh) bash script (only for Debian-based systems) to automatically install from sources a basic version of [OpenCV](https://opencv.org/).
To download and install using one command the script that is mentioned above, run:
```
wget -O - https://raw.githubusercontent.com/CSpyridakis/SCTT/master/shellScripts/Debian/install-opencv-debian-x86.sh | bash -s -- --install
```

2. If you want to change files' names, you may need to update `handle` script also.

