#!/bin/bash

if [ "$BUILD_TYPE" == "Coverage" ]; then
  cd ${TRAVIS_BUILD_DIR}
  alias lcov="lcov --gcov-tool $(which ${GCOV})"
  lcov -d . -c -o coverage.info
  lcov -r coverage.info '/usr/*' 'test/*' 'libs/*' -o coverage.info
  lcov -l coverage.info
  bash <(curl -s https://codecov.io/bash) || echo "Codecov did not collect coverage reports"
fi
