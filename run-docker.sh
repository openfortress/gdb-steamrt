#!/bin/bash

docker run -it -v $PWD:/gdb -v $PWD/ccache:/root.ccache -w /gdb jimbly/steamrt-amd64-gcc $@
