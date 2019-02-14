#include "../interface/basicAnalyzer.h"
#include "../interface/tTreeHandler.h"
#include "../interface/tBranchHandler.h"
#include "../interface/dBranchHandler.h"
#include "classes/DelphesClasses.h"
#include "TLorentzVector.h"
#include "TH1F.h"
#include "TMath.h"


#include <iostream>
#define MASS_E 0.0005
#define MASS_MU 0.105



using namespace d_ana;



bool compareEle(Electron a, Electron b) {return (a.PT < b.PT);} 
bool compareMu(Muon a, Muon b) {return (a.PT < b.PT);} 



//***************************************************************************************************************//
int main(int argc, char **argv) {

	d_ana::tTreeHandler tree(argv[1], "Delphes");
        d_ana::dBranchHandler<Electron> elecs(&tree,"Electron");
        d_ana::dBranchHandler<Muon> muons(&tree,"MuonLoose");
        d_ana::dBranchHandler<Vertex> vertex(&tree,"Vertex");

       
        TH1F *massZ = new TH1F("massZ", "", 20, 60, 110);
        TH1F *massN = new TH1F("massN", "", 20, 400, 1200);
        TH1F *dtvertexhist = new TH1F("dtvertexhist", "", 40, -20e-9, 20e-9);
        TH1F *dtleptonhist = new TH1F("dtleptonhist", "", 40, -20e-9, 20e-9);
        TH1F *dthist = new TH1F("dthist", "", 40, -20e-9, 20e-9);
        TH1F *dlvertexhist = new TH1F("dlvertexhist", "", 40, 0, 40);
        TH1F *dlleptonhist = new TH1F("dlleptonhist", "", 40, 0, 40);
        TH1F *dlhist = new TH1F("dlhist", "", 40, 0, 40);

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
                if(index_muon_leading != -1 && fabs(mass_muon_stored) < 20) {
                    massZ->Fill(mass_muon_stored);
                    float xl = (skimmedmuons.at(index_muon_leading).X + skimmedmuons.at(index_muon_trailing).X)/2.0;
                    float yl = (skimmedmuons.at(index_muon_leading).Y + skimmedmuons.at(index_muon_trailing).Y)/2.0;
                    float zl = (skimmedmuons.at(index_muon_leading).Z + skimmedmuons.at(index_muon_trailing).Z)/2.0;
                    float tl = (skimmedmuons.at(index_muon_leading).T + skimmedmuons.at(index_muon_trailing).T)/2.0;
                    float xv = vertex.at(index_vertex)->X;
                    float yv = vertex.at(index_vertex)->Y;
                    float zv = vertex.at(index_vertex)->Z;
                    float tv = vertex.at(index_vertex)->T;
                    dtvertexhist->Fill(tv); 
                    dtleptonhist->Fill(tl);
                    dthist->Fill(tl-tv);
                    dlvertexhist->Fill(sqrt(xv*xv + yv*yv + zv*zv));
                    dlleptonhist->Fill(sqrt(xl*xl + yl*yl + zl*zl));
                    dlhist->Fill(sqrt((xl-xv)*(xl-xv) + (yl-yv)*(yl-yv) + (zl-zv)*(zl-zv)));

                    TLorentzVector a, b, c, d;
                    a.SetPtEtaPhiM(skimmedmuons.at(index_muon_leading).PT, skimmedmuons.at(index_muon_leading).Eta, skimmedmuons.at(index_muon_leading).Phi, MASS_MU);
                    b.SetPtEtaPhiM(skimmedmuons.at(index_muon_trailing).PT, skimmedmuons.at(index_muon_trailing).Eta, skimmedmuons.at(index_muon_trailing).Phi, MASS_MU);
                    TVector3 boostvector((xl-xv)/(tl-tv), (yl-yv)/(tl-tv), (zl-zv)/(tl-tv));
                    a.Boost(boostvector);
                    b.Boost(boostvector);
                    c = a+b; 
                    d.SetPtEtaPhiM(c.Pt(), -c.Eta(), c.Phi() + TMath::Pi(), 1.0);
                    float reco_mass = (a+b+d).M(); 
                    massN->Fill(reco_mass);
                }
                if(index_ele_leading != -1 && fabs(mass_ele_stored) < 20) {
                    massZ->Fill(mass_ele_stored);
                    float xl = (skimmedelecs.at(index_ele_leading).X + skimmedelecs.at(index_ele_trailing).X)/2.0;
                    float yl = (skimmedelecs.at(index_ele_leading).Y + skimmedelecs.at(index_ele_trailing).Y)/2.0;
                    float zl = (skimmedelecs.at(index_ele_leading).Z + skimmedelecs.at(index_ele_trailing).Z)/2.0;
		    float tl = (skimmedelecs.at(index_ele_leading).T + skimmedelecs.at(index_ele_trailing).T)/2.0;
                    float xv = vertex.at(index_vertex)->X;
                    float yv = vertex.at(index_vertex)->Y;
                    float zv = vertex.at(index_vertex)->Z;
                    float tv = vertex.at(index_vertex)->T;
                    dtvertexhist->Fill(tv); 
                    dtleptonhist->Fill(tl);
                    dthist->Fill(tl-tv);
                    dlvertexhist->Fill(sqrt(xv*xv + yv*yv + zv*zv));
                    dlleptonhist->Fill(sqrt(xl*xl + yl*yl + zl*zl));
                    dlhist->Fill(sqrt((xl-xv)*(xl-xv) + (yl-yv)*(yl-yv) + (zl-zv)*(zl-zv)));
                    
                    TLorentzVector a, b, c, d;
                    a.SetPtEtaPhiM(skimmedmuons.at(index_ele_leading).PT, skimmedmuons.at(index_ele_leading).Eta, skimmedmuons.at(index_ele_leading).Phi, MASS_MU);
                    b.SetPtEtaPhiM(skimmedmuons.at(index_ele_trailing).PT, skimmedmuons.at(index_ele_trailing).Eta, skimmedmuons.at(index_ele_trailing).Phi, MASS_MU);
                    TVector3 boostvector((xl-xv)/(tl-tv), (yl-yv)/(tl-tv), (zl-zv)/(tl-tv));
                    a.Boost(boostvector);
                    b.Boost(boostvector);
                    c = a+b; 
                    d.SetPtEtaPhiM(c.Pt(), -c.Eta(), c.Phi() + TMath::Pi(), 1.0);
                    float reco_mass = (a+b+d).M(); 
                    massN->Fill(reco_mass);
		}			
 
        }


        TFile *f = new TFile("file.root", "recreate");
        f->cd();
        massZ->Write();
        dtvertexhist->Write(); 
        dtleptonhist->Write();
        dthist->Write();
        dlvertexhist->Write();
        dlleptonhist->Write();
        dlhist->Write();
        massN->Write();
        f->Close();

        return 1;

}
//***************************************************************************************************************//

