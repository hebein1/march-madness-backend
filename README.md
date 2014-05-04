March Madness Engine
=======

**Build**
* make init # compiles gtest, you only need to run this once
* cd build && make # compiles both the engine and the unit tests

**Run**
* ./bin/mme to run the engine (start the rails server in production mode first)
* ./bin/mmetest to run the tests (start the rails integration test first)

**Dependencies**
* gtest 1.7.0
* sqlite3

