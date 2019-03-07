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



using namespace d_ana;



bool compareEle(Electron a, Electron b) {return (a.PT < b.PT);} 
bool compareMu(Muon a, Muon b) {return (a.PT < b.PT);} 



//***************************************************************************************************************//
int main(int argc, char **argv) {



        std::string inputFile(argv[1]);
        float sigma = atof(argv[2]);
        float ctau = atof(argv[3]);

        int totalEventsm = 0;
        int passingEventsm = 0;
        int totalEventse = 0;
        int passingEventse = 0;
        int totalEventswithdz = 0;
        int passingEventswithdz = 0;

	d_ana::tTreeHandler tree(inputFile.c_str(), "Delphes");
        d_ana::dBranchHandler<Electron> elecs(&tree,"Electron");
        d_ana::dBranchHandler<Muon> muons(&tree,"MuonLoose");
        d_ana::dBranchHandler<Vertex> vertex(&tree,"Vertex");
       
        const Double_t c_light = 2.99792458E8;

        size_t nevents = tree.entries();
	for(size_t i=0;i<nevents;i++) {

                tree.setEntry(i); 
               //======================Electrons===============================
                size_t index_ele_leading = -1, index_ele_trailing = -1;
                float mass_ele_stored = -100000;
                std::vector<Electron> skimmedelecs; 
                if(elecs.size() > 1) {
                    for(size_t elec=0;elec<elecs.size();elec++){
                        if(elecs.at(elec)->PT < 20 ) continue;
                        if(fabs(elecs.at(elec)->Eta) > 2.9) continue;
                        skimmedelecs.push_back(*elecs.at(elec));
                    }
         	    std::sort(skimmedelecs.begin(), skimmedelecs.end(), compareEle);
                    for(size_t j = 0; j < skimmedelecs.size(); j++) {
                        for(size_t k = 0; k < skimmedelecs.size(); k++) {
                                 if(j >= k) continue;
                                 if(skimmedelecs.at(j).Charge * skimmedelecs.at(k).Charge > 0) continue;
                                 TLorentzVector a, b;
                                 a.SetPtEtaPhiM(skimmedelecs.at(j).PT, skimmedelecs.at(j).Eta, skimmedelecs.at(j).Phi, MASS_E); 
                                 b.SetPtEtaPhiM(skimmedelecs.at(k).PT, skimmedelecs.at(k).Eta, skimmedelecs.at(k).Phi, MASS_E);
                                 float mass = (a+b).M();
                                 if(fabs(91.2-mass) < fabs(91.2-mass_ele_stored)) {
                                     index_ele_leading = j; 
                                     index_ele_trailing = k;
                                     mass_ele_stored = mass;
                                 }

		        }
                    }
                }

                //======================Muons===============================
                size_t index_muon_leading = -1, index_muon_trailing = -1;
                float mass_muon_stored = -100000;
                std::vector<Muon> skimmedmuons; 
 
                if(muons.size() > 1) {
                    for(size_t muonc=0;muonc<muons.size();muonc++){
                        if(muons.at(muonc)->PT < 20 ) continue;
                        if(fabs(muons.at(muonc)->Eta) > 2.9) continue;
                        skimmedmuons.push_back(*muons.at(muonc));
                    }
         	    std::sort(skimmedmuons.begin(), skimmedmuons.end(), compareMu);
                    for(size_t j = 0; j < skimmedmuons.size(); j++) {
                        for(size_t k = 0; k < skimmedmuons.size(); k++) {
                                 if(j >= k) continue;
                                 if(skimmedmuons.at(j).Charge * skimmedmuons.at(k).Charge > 0) continue;
                                 TLorentzVector a, b;
                                 a.SetPtEtaPhiM(skimmedmuons.at(j).PT, skimmedmuons.at(j).Eta, skimmedmuons.at(j).Phi, MASS_MU); 
                                 b.SetPtEtaPhiM(skimmedmuons.at(k).PT, skimmedmuons.at(k).Eta, skimmedmuons.at(k).Phi, MASS_MU);
                                 float mass = (a+b).M();
                                 if(fabs(91.2-mass) < fabs(91.2-mass_muon_stored)) {
                                     index_muon_leading = j; 
                                     index_muon_trailing = k;
                                     mass_muon_stored = mass;
                                 }

		        }
                    }
                }
                //======================Vertex===============================
                size_t index_vertex = -1;
                float sum_pt_stored = -1;
                for(size_t vertexc=0; vertexc < vertex.size(); vertexc++){
                    if(sum_pt_stored < vertex.at(vertexc)->SumPT2) {
                        index_vertex = vertexc;
                        sum_pt_stored = vertex.at(vertexc)->SumPT2;
                    }                          
                }

                if(index_vertex == -1) continue;
                if(index_muon_leading != -1) {
                    if(fabs(91.2-mass_muon_stored) > 10.) continue;
                    float xl = (skimmedmuons.at(index_muon_leading).X + skimmedmuons.at(index_muon_trailing).X)/2.0;
                    float yl = (skimmedmuons.at(index_muon_leading).Y + skimmedmuons.at(index_muon_trailing).Y)/2.0;
                    float zl = (skimmedmuons.at(index_muon_leading).Z + skimmedmuons.at(index_muon_trailing).Z)/2.0;
                    float tl = (skimmedmuons.at(index_muon_leading).T + skimmedmuons.at(index_muon_trailing).T)/2.0;
                    float xv = vertex.at(index_vertex)->X;
                    float yv = vertex.at(index_vertex)->Y;
                    float zv = vertex.at(index_vertex)->Z;
                    float tv = vertex.at(index_vertex)->T;
                    if(fabs(tl-tv) > 3 * sigma * 1E-12) {
                        passingEventsm++; 
                    }
                    totalEventsm++;
                }
                if(index_ele_leading != -1) {
                    if(fabs(91.2-mass_ele_stored) > 10.) continue;
                    float xl = (skimmedelecs.at(index_ele_leading).X + skimmedelecs.at(index_ele_trailing).X)/2.0;
                    float yl = (skimmedelecs.at(index_ele_leading).Y + skimmedelecs.at(index_ele_trailing).Y)/2.0;
                    float zl = (skimmedelecs.at(index_ele_leading).Z + skimmedelecs.at(index_ele_trailing).Z)/2.0;
		    float tl = (skimmedelecs.at(index_ele_leading).T + skimmedelecs.at(index_ele_trailing).T)/2.0;
                    float xv = vertex.at(index_vertex)->X;
                    float yv = vertex.at(index_vertex)->Y;
                    float zv = vertex.at(index_vertex)->Z;
                    float tv = vertex.at(index_vertex)->T;
                    if(fabs(tl-tv) > 3.0 * sigma * 1E-12) { 
                        passingEventse++;
                    }
		    totalEventse++; 
		}			
 
        }

        std::cout << "1000 700 " << ctau << " " << sigma << " " << passingEventsm << " " << totalEventsm << " " << (float)passingEventsm/(float)totalEventsm
                                                         << " " << passingEventse << " " << totalEventse << " " << (float)passingEventse/(float)totalEventse << std::endl;

        return 1;

}
//***************************************************************************************************************//

