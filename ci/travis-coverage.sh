#!/bin/bash

if [ "$BUILD_TYPE" == "Coverage" ]; then
  cd ${TRAVIS_BUILD_DIR}
  echo ${GCOV}
  echo $GCOV
  gcov-6 --version
  which gcov-6
  alias lcov_="lcov --gcov-tool $(which ${GCOV})"
  lcov_ -d . -c -o coverage.info
  lcov_ -r coverage.info '/usr/*' 'test/*' 'libs/*' -o coverage.info
  lcov_ -l coverage.info
  bash <(curl -s https://codecov.io/bash) || echo "Codecov did not collect coverage reports"
fi
