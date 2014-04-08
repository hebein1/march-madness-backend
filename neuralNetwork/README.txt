Source code for training and testing of NCAA data is in NCAA_ANN_src

The rest of the files and folders are a part of the Fast Artificial Neural Network Library (FANN)

First, you need to be inside the neuralNetwork folder and run the follwoing commands to install FANN: 

cmake .
sudo make install

The instructions below require you to be inside NCAA_ANN_src folder

=> To install the gtest library: make init

=> Compilation: make clean && make

NOTE: If "error while loading shared libraries: libfann.so.2: cannot open shared object" shows up run "sudo ldconfig"
