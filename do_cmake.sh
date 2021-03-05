: ${BUILD_DIR:=build}
: ${GIT_DIR:=..}

rm ${BUILD_DIR}
mkdir ${BUILD_DIR}
cd ${BUILD_DIR}

CMAKE=cmake3
${CMAKE} $ARGS "$@" ${GIT_DIR} || exit 1

echo done.
