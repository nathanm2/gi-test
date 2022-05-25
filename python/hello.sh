#!/usr/bin/env bash

SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]:-$0}"; )" &> /dev/null && pwd 2> /dev/null; )";
BUILD_DIR=$(readlink -f ${SCRIPT_DIR}/../build)

export LD_LIBRARY_PATH=${BUILD_DIR}
export GI_TYPELIB_PATH=${BUILD_DIR}
exec python3 ${SCRIPT_DIR}/hello.py $@
