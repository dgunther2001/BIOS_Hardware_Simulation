#!/usr/bin/env bash

IMAGE_NAME="bios_sim"

docker build -t $IMAGE_NAME .
docker run --rm $IMAGE_NAME