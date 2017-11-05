#!/bin/bash

rm -rf build
make build
make all
./build/proto_aplicacao
