#!/bin/bash

if [ "$BUILD_TYPE" == "Coverage" ]; then
  cd ${TRAVIS_BUILD_DIR}
  gcov_tool="--gcov-tool $(which ${GCOV})"
  lcov ${gcov_tool} -d . -c -o coverage.info
  lcov ${gcov_tool} -r coverage.info '/usr/*' 'test/*' 'libs/*' -o coverage.info
  lcov ${gcov_tool} -l coverage.info
  bash <(curl -s https://codecov.io/bash) || echo "Codecov did not collect coverage reports"
fi
