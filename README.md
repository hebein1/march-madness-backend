March Madness Engine
=======

**This is the backend for the march madness prediction algorithm. Some things 
we wish to account for in the algorithm**
* W/L (decision tree with all teams)
* Strength of schedule
* Past 5 games
* Defensive Rank (take in account past defensive stats)
* Offensive Rank (ditto)
* Home/ Away
* Player injuries
* More, Hoping to make it modular

**Build**
* make init # compiles gtest, you only need to run this once
* cd build && make # compiles both the engine and the unit tests

**Run**
* ./bin/mme to run the engine (start the rails server in production mode first)
* ./bin/mmetest to run the tests (start the rails integration test first)

**Dependencies**
* gtest 1.7.0
* sqlite3

