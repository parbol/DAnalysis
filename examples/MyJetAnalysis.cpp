#include "../interface/basicAnalyzer.h"
#include "../interface/tTreeHandler.h"
#include "../interface/tBranchHandler.h"
#include "../interface/dBranchHandler.h"
#include "classes/DelphesClasses.h"
#include "TLorentzVector.h"
#include "TH1F.h"
#include "TMath.h"
#include <string>


#include <iostream>
#define MASS_E 0.0005
#define MASS_MU 0.105
#define nJetsPUPPIMax 20


using namespace d_ana;


//*******************************************************************************//
//Some global variables for the tree
Int_t nJetsPUPPI_;
Float_t jetPUPPIPT_[nJetsPUPPIMax];
Float_t jetPUPPIEta_[nJetsPUPPIMax];
Float_t jetPUPPIPhi_[nJetsPUPPIMax];
Float_t jetPUPPIMass_[nJetsPUPPIMax];
Float_t jetPUPPIDXY_[nJetsPUPPIMax];
Float_t jetPUPPIDZ_[nJetsPUPPIMax];
Float_t jetPUPPIDT_[nJetsPUPPIMax];
Float_t jetPUPPITcorr_[nJetsPUPPIMax];
Float_t jetPUPPITuncorr_[nJetsPUPPIMax];
//*******************************************************************************//


//*******************************************************************************//
void setTreeBranches(TTree *);
bool compareEle(Electron a, Electron b) {return (a.PT < b.PT);} 
bool compareMu(Muon a, Muon b) {return (a.PT < b.PT);} 
bool compareJet(Jet a, Jet b) {return (a.PT < b.PT);} 
//*******************************************************************************//


//***************************************************************************************************************//
int main(int argc, char **argv) {

        if(argc != 3) {
            std::cout << "Usage: " << argv[0] << " InputFile.root OutputFile.root" << std::endl;
            return -1;
        }

        std::string inputFile(argv[1]);
        std::string outputFile(argv[2]);

	d_ana::tTreeHandler tree(inputFile.c_str(), "Delphes");
        d_ana::dBranchHandler<Jet> jets(&tree,"JetPUPPI");
        d_ana::dBranchHandler<Vertex> vertex(&tree,"Vertex");
       
        const Double_t c_light = 2.99792458E8;
        TFile *f = new TFile(outputFile.c_str(), "recreate");
        f->cd();

        TTree *t1 = new TTree("t1","a simple Tree with simple variables");
        setTreeBranches(t1);

        TH1F *jdistance = new TH1F("jdistance", "", 50, 0, 200);
        TH1F *jdistancexy = new TH1F("jdistancexy", "", 50, 0, 200);
        TH1F *jt = new TH1F("jt", "", 50, 0, 1e-9);

        //Looping over full set of events
        size_t nevents = tree.entries();
	for(size_t i=0;i<nevents;i++) {

                tree.setEntry(i); 
                
                size_t index_vertex = -1;
                float sum_pt_stored = -1;
                for(size_t vertexc=0; vertexc < vertex.size(); vertexc++){
                    if(sum_pt_stored < vertex.at(vertexc)->SumPT2) {
                        index_vertex = vertexc;
                        sum_pt_stored = vertex.at(vertexc)->SumPT2;
                    }                          
                }
                if(index_vertex == -1) continue;
                if(jets.size() == 0) continue;

                nJetsPUPPI_ = 0;
 
                for(int jetc = 0; jetc < jets.size(); jetc++){
                    if(jets.at(jetc)->PT < 30 ) continue;
                    if(fabs(jets.at(jetc)->Eta) > 2.9) continue;
                    float x = jets.at(jetc)->X;
                    float y = jets.at(jetc)->Y;
                    float z = jets.at(jetc)->Z;
                    float t = jets.at(jetc)->T;
                    float xMTD = jets.at(jetc)->XMTD;
                    float yMTD = jets.at(jetc)->YMTD;
                    float zMTD = jets.at(jetc)->ZMTD;
                    float tMTD = jets.at(jetc)->TMTD;
                    float vx = vertex.at(index_vertex)->X;
                    float vy = vertex.at(index_vertex)->Y;
                    float vz = vertex.at(index_vertex)->Z;
                    float vt = vertex.at(index_vertex)->T;
                    float distance = sqrt( (x-vx) * (x-vx) + (y - vy) * (y - vy) + (z - vz) * (z - vz));
                    float distancexy = sqrt( (x-vx) * (x-vx) + (y - vy) * (y - vy));
                    float distancez = z - vz;
                    float distancet = t - vt;
                    float distancetMTD = tMTD - vt;
                    jdistance->Fill(distance);
                    jdistancexy->Fill(distancexy);
                    jt->Fill(distancet);
                    
                    jetPUPPIPT_[nJetsPUPPI_] = jets.at(jetc)->PT;
                    jetPUPPIEta_[nJetsPUPPI_] = jets.at(jetc)->Eta;
                    jetPUPPIPhi_[nJetsPUPPI_] = jets.at(jetc)->Phi;
                    jetPUPPIMass_[nJetsPUPPI_] = jets.at(jetc)->Mass;
                    jetPUPPIDXY_[nJetsPUPPI_] = distancexy;
                    jetPUPPIDZ_[nJetsPUPPI_] = distancez;
                    jetPUPPIDT_[nJetsPUPPI_] = distancet ;
                    jetPUPPITcorr_[nJetsPUPPI_] = distancetMTD - 1e-3 * distance/c_light;
                    jetPUPPITuncorr_[nJetsPUPPI_] = distancetMTD;
                    nJetsPUPPI_++; 
                }
                t1->Fill();
        }


        jdistance->Write();
        jdistancexy->Write();
        jt->Write();
        t1->Write();
        f->Close();
        return 1;

}
//***************************************************************************************************************//




//***************************************************************************************************************//
void setTreeBranches(TTree *t1) {
 
  t1->Branch("nJetsPUPPI_",&nJetsPUPPI_,"nJetsPUPPI_/I");
  t1->Branch("jetPUPPIPT_", jetPUPPIPT_, "jetPUPPIPT_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIEta_", jetPUPPIEta_, "jetPUPPIEta_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIPhi_", jetPUPPIPhi_, "jetPUPPIPhi_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIMass_", jetPUPPIMass_, "jetPUPPIMass_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIDXY_", jetPUPPIDXY_, "jetPUPPIDXY_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIDZ_", jetPUPPIDZ_, "jetPUPPIDZ_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIDT_", jetPUPPIDT_, "jetPUPPIDT_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPITcorr_", jetPUPPITcorr_, "jetPUPPITcorr_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPITuncorr_", jetPUPPITuncorr_, "jetPUPPITuncorr_[nJetsPUPPI_]/F");
    
} 
//***************************************************************************************************************//
