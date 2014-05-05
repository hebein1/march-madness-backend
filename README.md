March Madness Engine
=======

**Build C5**
* cd c5_mmp/c5_source/ && make # builds c5.0 executable
* cd .. && make init # compiles gtest
* make # compiles c5_mmp code and unit tests

**Run C5**
* ./mmp_c5_tests # run c5_mmp automated test cases

**Build ANN**
* cd neuralNetwork
* cmake . # installation step 1 for FANN
* sudo make install # installation step 2 for FANN
* cd NCAA_ANN_src
* make && make init # compiles algorithm code, unit tests and gtest

**Run ANN**
* cd NCAA_ANN_src
* ./ann_test # run annTest automated test cases

**Build Engine**
* make sure you are in the root directory of the project
* make init # compiles gtest, you only need to run this once
* cd build && make # compiles both the engine and the unit tests

**Run Engine**
* ./bin/mme to run the engine (start the rails server in production mode first)
* ./bin/mmetest to run the tests (start the rails integration test first)

**Dependencies**
* gtest 1.7.0
* sqlite3

