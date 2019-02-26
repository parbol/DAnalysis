# DAnalysis

Repository for generic (Delphes based) analysis code and scripts for lxbatch. 

This program was developed by Jan Kieseler and later modified by me.

#Install instructions

Before installing DAnalysis you need to get a copy of Delphes. If you want to work on timing issues get it from my repo.

git clone https://github.com/parbol/delphes.git -b DelphesForTiming

cd delphes

make

git clone https://github.com/parbol/DAnalysis.git -b LLPAnalysis

cd DAnalysis

source myenv.sh

#Compiling instructions

The analyzer is an standalone C++ program called MyMassAnalysis.cpp. To compile it just:

cd examples

compileExample.sh MyMassAnalysis.cpp
 

