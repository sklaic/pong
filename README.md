# pong
Pong game in C++ with SDL2.

### Prerequisites
To compile program in Linux following program/libraries have to be installed:
* gcc (base build tools)
* cmake
* SDL2
* SDL2_ttf

On Ubuntu/Debian installing is done by running following command:

        $ sudo apt-get install build-essential cmake libsdl2-dev libsdl2-ttf-dev

### Compiling
Cmake compile options are setup for Linux and to run compilation do following inside source directory:

        $ mkdir build && cd build
        $ cmake ..
        $ cmake --build . --config Release --target pong

### Running the game
The game must have access to the res directory from the current working directory to load the font file.

To launch the game from the build directory, run:

        $ ./pong

Running the game from binary archive require that is run on 64 bit Linux with SDL2 and SDL2_ttf library installed.

To extract and run the game from the directory containing the zip archive, run:

        $ unzip -d pong pong.zip && cd pong
        $ ./pong
