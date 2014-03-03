Source code for training and testing of NCAA data is in NCAA_ANN_src

The rest of the files and folders are a part of the Fast Artificial Neural Network Library (FANN)

The instructions below require you to be inside NCAA_ANN_src folder

Run the following commands as needed:

=> Regenerate data stored in ncaa.data file: ruby randomData.rb

=> Compilation: make clean && make

=> Train Data: ./ncaa_train

=> Test Network: ./ncaa_test

=> Compile, Train and Test: make runtest
