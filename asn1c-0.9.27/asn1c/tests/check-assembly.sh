#!/bin/sh

#
# This script is designed to quickly create lots of files in underlying
# test-* directories, do lots of other magic stuff and exit cleanly.
#

if [ "x$1" = "x" ]; then
	echo "Usage: $0 <check-NN.c>"
	exit
fi

set -e

# Compute the .asn1 spec name by the given file name.
source_full=$1
source_short=`echo "$source_full" | sed -e 's/.*\///'`
testno=`echo "$source_short" | cut -f2 -d'-' | cut -f1 -d'.'`

args=`echo "$source_short" | sed -e 's/\.c[c]*$//'`
testdir=test-${args}

OFS=$IFS
IFS="."
set $args
shift
IFS=$OFS
AFLAGS="$@"

# Assume the test fails. Will be removed when it passes well.
touch ${testdir}-FAILED

mkdir -p $testdir
cd $testdir
rm -f $source_short
ln -fns ../$source_full

asn_module=`echo ../${top_srcdir}/tests/${testno}-*.asn1`

# Create a Makefile for the project.
cat > Makefile <<EOM
# This file is autogenerated by ../$0

COMMON_FLAGS= -I.
CFLAGS = \${COMMON_FLAGS} ${CFLAGS} -g -O0
CPPFLAGS = -DSRCDIR=../${srcdir}
CXXFLAGS = \${COMMON_FLAGS} ${CXXFLAGS}

CC ?= ${CC}

all: check-executable
check-executable: compiled-module *.c*
	@rm -f *.core
	\$(CC) \$(CPPFLAGS) \$(CFLAGS) -o check-executable *.c* -lm

# Compile the corresponding .asn1 spec.
compiled-module: ${asn_module} ../${top_builddir}/asn1c/asn1c
	../${top_builddir}/asn1c/asn1c -S ../${top_srcdir}/skeletons -Wdebug-compiler	\\
		${AFLAGS} ${asn_module}
	rm -f converter-sample.c
	@touch compiled-module

check-succeeded: check-executable
	@rm -f check-succeeded
	./check-executable
	@touch check-succeeded

check: check-succeeded

clean:
	@rm -f *.o check-executable
EOM

# Perform building and checking
make check

# Make sure the test is not marked as failed any longer.
rm -f ../${testdir}-FAILED