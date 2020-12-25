# gdb-steamrt

Since the latest versions of gdb shipped with most distibutions are becoming incompatable with Steam's linux runtime, here is the resources and tweeks needed in order to build gdb for the linux runtime, specifically targeting for use with source engine mods.

For pre-built binaries, check the [releases](https://github.com/Fenteale/gdb-steamrt/releases).

### To Use:

Launch steam with the command:
```
GAME_DEBUGGER=/path/to/gdb-steamrt/gdb\ --args steam
```

Where the path to gdb-steamrt is the folder you downloaded the binary to.  Launching any game through steam will now run it through gdb, so check the terminal you ran the command above in to be able to interact with gdb.

### Building from source:
Make sure you have docker installed.  Download the repo, change directory inside, and run:
```
./run-docker.sh ./configure
```
Then when that is finished, run make through docker:
```
./run-docker.sh make
```
The binary will then be built as `gdb` in the `gdb` sub folder.