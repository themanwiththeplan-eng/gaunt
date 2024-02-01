#!/bin/bash

ROOT_DIR = $(pwd)
dir = $ROOT_DIR/$(dirname $0)

if [ -d "$ROOT_DIR/$dir/build.clang" ]; then
    echo "Removing build.clang directory"
    rm -rf $ROOT_DIR/$dir/build.clang
fi