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
#define nTracksMax 2000


using namespace d_ana;


//*******************************************************************************//
//Some global variables for the tree
Int_t nJetsPUPPI_;
Float_t jetPUPPIPT_[nJetsPUPPIMax];
Float_t jetPUPPIEta_[nJetsPUPPIMax];
Float_t jetPUPPIPhi_[nJetsPUPPIMax];
Float_t jetPUPPIMass_[nJetsPUPPIMax];
Float_t jetPUPPIX_[nJetsPUPPIMax];
Float_t jetPUPPIY_[nJetsPUPPIMax];
Float_t jetPUPPIZ_[nJetsPUPPIMax];
Float_t jetPUPPIT_[nJetsPUPPIMax];
Float_t jetPUPPIXMTD_[nJetsPUPPIMax];
Float_t jetPUPPIYMTD_[nJetsPUPPIMax];
Float_t jetPUPPIZMTD_[nJetsPUPPIMax];
Float_t jetPUPPITMTD_[nJetsPUPPIMax];
Float_t jetPUPPIDXY_[nJetsPUPPIMax];
Float_t jetPUPPIDZ_[nJetsPUPPIMax];
Float_t jetPUPPIDT_[nJetsPUPPIMax];
Float_t jetPUPPITcorr_[nJetsPUPPIMax];
Float_t jetPUPPITuncorr_[nJetsPUPPIMax];
Int_t nTracks_;
Float_t TrackPT_[nTracksMax];
Float_t TrackEta_[nTracksMax];
Float_t TrackPhi_[nTracksMax];
Float_t TrackX_[nTracksMax];
Float_t TrackY_[nTracksMax];
Float_t TrackZ_[nTracksMax];
Float_t TrackT_[nTracksMax];
Float_t TrackXMTD_[nTracksMax];
Float_t TrackYMTD_[nTracksMax];
Float_t TrackZMTD_[nTracksMax];
Float_t TrackTMTD_[nTracksMax];
Float_t PVX_;
Float_t PVY_;
Float_t PVZ_;
Float_t PVT_;

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
        d_ana::dBranchHandler<Track> tracks(&tree,"EFlowTrack");
       
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

                PVX_ = vertex.at(index_vertex)->X;
                PVY_ = vertex.at(index_vertex)->Y;
                PVZ_ = vertex.at(index_vertex)->Z;
                PVT_ = vertex.at(index_vertex)->T;
 
                if(tracks.size() == 0) continue;
                
                nTracks_ = 0;
 
                for(int trackc = 0; trackc < tracks.size(); trackc++){
                    if(tracks.at(trackc)->PT < 1 ) continue;
                    float x = tracks.at(trackc)->X;
                    float y = tracks.at(trackc)->Y;
                    float z = tracks.at(trackc)->Z;
                    float t = tracks.at(trackc)->T;
                    float xMTD = tracks.at(trackc)->XMTD;
                    float yMTD = tracks.at(trackc)->YMTD;
                    float zMTD = tracks.at(trackc)->ZMTD;
                    float tMTD = tracks.at(trackc)->TMTD;
                    
                    TrackX_[nTracks_] = tracks.at(trackc)->X;
                    TrackY_[nTracks_] = tracks.at(trackc)->Y;
                    TrackZ_[nTracks_] = tracks.at(trackc)->Z;
                    TrackT_[nTracks_] = tracks.at(trackc)->T;
                    TrackXMTD_[nTracks_] = tracks.at(trackc)->XMTD;
                    TrackYMTD_[nTracks_] = tracks.at(trackc)->YMTD;
                    TrackZMTD_[nTracks_] = tracks.at(trackc)->ZMTD;
                    TrackTMTD_[nTracks_] = tracks.at(trackc)->TMTD;
                    TrackPT_[nTracks_] = tracks.at(trackc)->PT;
                    TrackEta_[nTracks_] = tracks.at(trackc)->Eta;
                    TrackPhi_[nTracks_] = tracks.at(trackc)->Phi;
                    nTracks_++; 
                }

                if(jets.size() == 0) continue;

                nJetsPUPPI_ = 0;
 
                for(int jetc = 0; jetc < jets.size(); jetc++){
                    if(jets.at(jetc)->PT < 20 ) continue;
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
                    jetPUPPIX_[nJetsPUPPI_] = x;
                    jetPUPPIY_[nJetsPUPPI_] = y;
                    jetPUPPIZ_[nJetsPUPPI_] = z;
                    jetPUPPIT_[nJetsPUPPI_] = t;
                    jetPUPPIXMTD_[nJetsPUPPI_] = xMTD;
                    jetPUPPIYMTD_[nJetsPUPPI_] = yMTD;
                    jetPUPPIZMTD_[nJetsPUPPI_] = zMTD;
                    jetPUPPITMTD_[nJetsPUPPI_] = tMTD;
                    jetPUPPIDXY_[nJetsPUPPI_] = distancexy;
                    jetPUPPIDZ_[nJetsPUPPI_] = distancez;
                    jetPUPPIDT_[nJetsPUPPI_] = distancet ;
                    jetPUPPITcorr_[nJetsPUPPI_] = distancetMTD - 1e-3 * distancetMTD/c_light;
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
  t1->Branch("jetPUPPIX_", jetPUPPIX_, "jetPUPPIX_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIY_", jetPUPPIY_, "jetPUPPIY_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIZ_", jetPUPPIZ_, "jetPUPPIZ_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIT_", jetPUPPIT_, "jetPUPPIT_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIXMTD_", jetPUPPIXMTD_, "jetPUPPIXMTD_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIYMTD_", jetPUPPIYMTD_, "jetPUPPIYMTD_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIZMTD_", jetPUPPIZMTD_, "jetPUPPIZMTD_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPITMTD_", jetPUPPITMTD_, "jetPUPPITMTD_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIDXY_", jetPUPPIDXY_, "jetPUPPIDXY_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIDZ_", jetPUPPIDZ_, "jetPUPPIDZ_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPIDT_", jetPUPPIDT_, "jetPUPPIDT_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPITcorr_", jetPUPPITcorr_, "jetPUPPITcorr_[nJetsPUPPI_]/F");
  t1->Branch("jetPUPPITuncorr_", jetPUPPITuncorr_, "jetPUPPITuncorr_[nJetsPUPPI_]/F");
  t1->Branch("nTracks_",&nTracks_,"nTracks_/I");
  t1->Branch("TrackPT_", TrackPT_, "TrackPT_[nTracks_]/F");
  t1->Branch("TrackEta_", TrackEta_, "TrackEta_[nTracks_]/F");
  t1->Branch("TrackPhi_", TrackPhi_, "TrackPhi_[nTracks_]/F");
  t1->Branch("TrackX_", TrackX_, "TrackX_[nTracks_]/F");
  t1->Branch("TrackY_", TrackY_, "TrackY_[nTracks_]/F");
  t1->Branch("TrackZ_", TrackZ_, "TrackZ_[nTracks_]/F");
  t1->Branch("TrackT_", TrackT_, "TrackT_[nTracks_]/F");
  t1->Branch("TrackXMTD_", TrackXMTD_, "TrackXMTD_[nTracks_]/F");
  t1->Branch("TrackYMTD_", TrackYMTD_, "TrackYMTD_[nTracks_]/F");
  t1->Branch("TrackZMTD_", TrackZMTD_, "TrackZMTD_[nTracks_]/F");
  t1->Branch("TrackTMTD_", TrackTMTD_, "TrackTMTD_[nTracks_]/F");
  t1->Branch("PVX_", &PVX_, "PVX/F");
  t1->Branch("PVY_", &PVY_, "PVY/F");
  t1->Branch("PVZ_", &PVZ_, "PVZ/F");
  t1->Branch("PVT_", &PVT_, "PVT/F");
     
} 
//***************************************************************************************************************//
