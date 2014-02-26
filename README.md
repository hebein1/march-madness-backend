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
* make # compiles both the engine and the unit tests

**Other Commands**
* make mme # just build the engine
* make mmetest # just build the tests
* make clean # remove object code not including third-parties binaries

**Run**
* ./mme to run the engine
* ./mmetest to run the tests

**Dependencies**
* gtest 1.7.0
* sqlite3

