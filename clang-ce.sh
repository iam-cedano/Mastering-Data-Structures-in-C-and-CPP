#! /bin/sh

clang "$1" -o /tmp/crun_temp && /tmp/crun_temp "$@"
rm /tmp/crun_temp