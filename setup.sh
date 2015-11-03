#!/bin/bash

set -e

EXERCISES_DIR=exercises
DEMOS_DIR=demos
CGAL_DIR=CGAL-3.8
MAKE_ARGS=$1

function build {
	for proj in `ls $1`; do
		pushd $1/$proj
		qmake >/dev/null || continue
		make $MAKE_ARGS
		popd
	done
}

echo "Setting up geoc viewer installation"

echo "Compiling CGAL"
pushd $CGAL_DIR
cmake .
make $1
popd

echo "Making initial library build (release mode)"
make $MAKE_ARGS

echo "Compiling exercises"
build $EXERCISES_DIR

echo "Compiling demos"
build $DEMOS_DIR

echo "Compiling additional demos"
build $DEMOS_DIR/make_grid
