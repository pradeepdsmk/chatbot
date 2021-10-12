# ChatBot

## Building (in Ubuntu terminal)

Install `cmake` and `build-essential`

    sudo apt install cmake build-essential

Make `build.sh` file executable and run it

    chmod +x ./build.sh
    ./build.sh

This will create a temporary `./build` folder, generates native build tool files specific to your compiler and platform in that folder, builds the cpp source files and deletes the folder after the building was complete.

The newly built binaries are found in `./dist` folder.


&nbsp;
### MIT License
