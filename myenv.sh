#export EXROOT_INCLUDE_PATH=/gpfs/users/parbol/delphes/external/ExRootAnalysis
export EXROOT_INCLUDE_PATH=/afs/cern.ch/work/p/pablom/private/DelphesForJets/delphes/external
export ROOT_INCLUDE_PATH=$EXROOT_INCLUDE_PATH:$ROOT_INCLUDE_PATH
export DELPHES_PATH=/afs/cern.ch/work/p/pablom/private/DelphesForJets/delphes/
export LD_LIBRARY_PATH=$DELPHES_PATH:$LD_LIBRARY_PATH
export BASEDIR=`pwd`
export DANALYSISPATH=$BASEDIR
export LD_LIBRARY_PATH=$BASEDIR:$EXROOT_INCLUDE_PATH:$LD_LIBRARY_PATH
export PATH=$PATH:$BASEDIR

