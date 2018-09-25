#!/bin/bash

if [ "$BUILD_TYPE" == "Coverage" ]; then
  cd ${TRAVIS_BUILD_DIR}
  echo ${GCOV}
  echo $GCOV
  gcov-6 --version
  which gcov-6
  alias lcov="lcov --gcov-tool $(which ${GCOV})"
  lcov -d . -c -o coverage.info
  lcov -r coverage.info '/usr/*' 'test/*' 'libs/*' -o coverage.info
  lcov -l coverage.info
  bash <(curl -s https://codecov.io/bash) || echo "Codecov did not collect coverage reports"
fi
