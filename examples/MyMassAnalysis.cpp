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
        std::string outputFile(argv[2]);
        float sigma = atof(argv[3]);

	d_ana::tTreeHandler tree(inputFile.c_str(), "Delphes");
        d_ana::dBranchHandler<Electron> elecs(&tree,"Electron");
        d_ana::dBranchHandler<Muon> muons(&tree,"MuonLoose");
        d_ana::dBranchHandler<Vertex> vertex(&tree,"Vertex");
       
        const Double_t c_light = 2.99792458E8;

        TH1F *massZm = new TH1F("massZm", "", 40, 60, 110);
        TH1F *massNm = new TH1F("massNm", "", 120, 400, 1100);
        TH1F *pthistm = new TH1F("pthistm", "", 40, 20, 500);
        TH1F *dtvertexhistm = new TH1F("dtvertexhistm", "", 40, -2e-9, 2e-9);
        TH1F *dtleptonhistm = new TH1F("dtleptonhistm", "", 40, -2e-9, 2e-9);
        TH1F *dthistm = new TH1F("dthistm", "", 40, 0, 2e-9);
        TH1F *dlvertexhistm = new TH1F("dlvertexhistm", "", 40, 0, 500);
        TH1F *dlleptonhistm = new TH1F("dlleptonhistm", "", 40, 0, 500);
        TH1F *dlhistm = new TH1F("dlhistm", "", 40, 0, 40);
        TH1F *d0vertexhistm = new TH1F("d0vertexhistm", "", 40, 0, 500);
        TH1F *d0leptonhistm = new TH1F("d0leptonhistm", "", 40, 0, 500);
        TH1F *d0histm = new TH1F("d0histm", "", 40, 0, 40);

        TH1F *massZe = new TH1F("massZe", "", 40, 60, 110);
        TH1F *massNe = new TH1F("massNe", "", 40, 400, 1100);
        TH1F *pthiste = new TH1F("pthiste", "", 40, 20, 500);
        TH1F *dtvertexhiste = new TH1F("dtvertexhiste", "", 40, -2e-9, 2e-9);
        TH1F *dtleptonhiste = new TH1F("dtleptonhiste", "", 40, -2e-9, 2e-9);
        TH1F *dthiste = new TH1F("dthiste", "", 40, 0, 2e-9);
        TH1F *dlvertexhiste = new TH1F("dlvertexhiste", "", 40, 0, 500);
        TH1F *dlleptonhiste = new TH1F("dlleptonhiste", "", 40, 0, 500);
        TH1F *dlhiste = new TH1F("dlhiste", "", 40, 0, 40);
        TH1F *d0vertexhiste = new TH1F("d0vertexhiste", "", 40, 0, 500);
        TH1F *d0leptonhiste = new TH1F("d0leptonhiste", "", 40, 0, 500);
        TH1F *d0histe = new TH1F("d0histe", "", 40, 0, 40);

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
                    massZm->Fill(mass_muon_stored);
                    if(fabs(mass_muon_stored-91.2)<10) {
                    float xl = (skimmedmuons.at(index_muon_leading).X + skimmedmuons.at(index_muon_trailing).X)/2.0;
                    float yl = (skimmedmuons.at(index_muon_leading).Y + skimmedmuons.at(index_muon_trailing).Y)/2.0;
                    float zl = (skimmedmuons.at(index_muon_leading).Z + skimmedmuons.at(index_muon_trailing).Z)/2.0;
                    float tl = (skimmedmuons.at(index_muon_leading).T + skimmedmuons.at(index_muon_trailing).T)/2.0;
                    float xv = vertex.at(index_vertex)->X;
                    float yv = vertex.at(index_vertex)->Y;
                    float zv = vertex.at(index_vertex)->Z;
                    float tv = vertex.at(index_vertex)->T;
                    dtvertexhistm->Fill(tv); 
                    dtleptonhistm->Fill(tl);
                    pthistm->Fill(skimmedmuons.at(index_muon_leading).PT); 
                    dthistm->Fill(tl-tv);
                    dlvertexhistm->Fill(sqrt(xv*xv + yv*yv + zv*zv));
                    dlleptonhistm->Fill(sqrt(xl*xl + yl*yl + zl*zl));
                    dlhistm->Fill(sqrt((xl-xv)*(xl-xv) + (yl-yv)*(yl-yv) + (zl-zv)*(zl-zv)));
                    d0vertexhistm->Fill(sqrt(xv*xv + yv*yv));
                    d0leptonhistm->Fill(sqrt(xl*xl + yl*yl));
                    d0histm->Fill(sqrt((xl-xv)*(xl-xv) + (yl-yv)*(yl-yv)));
                    TLorentzVector a, b, c, d;
                    a.SetPtEtaPhiM(skimmedmuons.at(index_muon_leading).PT, skimmedmuons.at(index_muon_leading).Eta, skimmedmuons.at(index_muon_leading).Phi, MASS_MU);
                    b.SetPtEtaPhiM(skimmedmuons.at(index_muon_trailing).PT, skimmedmuons.at(index_muon_trailing).Eta, skimmedmuons.at(index_muon_trailing).Phi, MASS_MU);
                    float betax = (xl-xv)/((tl-tv)*1e3*c_light);
                    float betay = (yl-yv)/((tl-tv)*1e3*c_light);
                    float betaz = (zl-zv)/((tl-tv)*1e3*c_light);
                    float gamma = 1.0/sqrt(1.0-(betax * betax + betay * betay + betaz * betaz));
                    TVector3 boostvector(betax, betay, betaz);
                    //TVector3 boostvector((xl-xv)/(tl-tv), (yl-yv)/(tl-tv), (zl-zv)/(tl-tv));
                    //if(boostvector.Mag() < 1  && fabs(tl-tv) > 3.0 * sigma * 1E-12) { 
                    if(boostvector.Mag() < 1) { 
                        a.Boost(-boostvector);
                        b.Boost(-boostvector);
                        c = a+b; 
                        d.SetPtEtaPhiM(c.Pt(), -c.Eta(), c.Phi() + TMath::Pi(), 1.0);
                        float reco_mass = (a+b+d).M(); 
                        massNm->Fill(reco_mass);
                    }
                    }
                }
                if(index_ele_leading != -1) {
                    massZe->Fill(mass_ele_stored);
                    if(fabs(mass_ele_stored-91.2)<10) {
                    float xl = (skimmedelecs.at(index_ele_leading).X + skimmedelecs.at(index_ele_trailing).X)/2.0;
                    float yl = (skimmedelecs.at(index_ele_leading).Y + skimmedelecs.at(index_ele_trailing).Y)/2.0;
                    float zl = (skimmedelecs.at(index_ele_leading).Z + skimmedelecs.at(index_ele_trailing).Z)/2.0;
		    float tl = (skimmedelecs.at(index_ele_leading).T + skimmedelecs.at(index_ele_trailing).T)/2.0;
                    float xv = vertex.at(index_vertex)->X;
                    float yv = vertex.at(index_vertex)->Y;
                    float zv = vertex.at(index_vertex)->Z;
                    float tv = vertex.at(index_vertex)->T;
                    dtvertexhiste->Fill(tv); 
                    dtleptonhiste->Fill(tl);
                    pthiste->Fill(skimmedelecs.at(index_ele_leading).PT); 
                    dthiste->Fill(tl-tv);
                    dlvertexhiste->Fill(sqrt(xv*xv + yv*yv + zv*zv));
                    dlleptonhiste->Fill(sqrt(xl*xl + yl*yl + zl*zl));
                    dlhiste->Fill(sqrt((xl-xv)*(xl-xv) + (yl-yv)*(yl-yv) + (zl-zv)*(zl-zv)));
                    d0vertexhiste->Fill(sqrt(xv*xv + yv*yv));
                    d0leptonhiste->Fill(sqrt(xl*xl + yl*yl));
                    d0histe->Fill(sqrt((xl-xv)*(xl-xv) + (yl-yv)*(yl-yv)));
                    TLorentzVector a, b, c, d;
                    a.SetPtEtaPhiM(skimmedelecs.at(index_ele_leading).PT, skimmedelecs.at(index_ele_leading).Eta, skimmedelecs.at(index_ele_leading).Phi, MASS_E);
                    b.SetPtEtaPhiM(skimmedelecs.at(index_ele_trailing).PT, skimmedelecs.at(index_ele_trailing).Eta, skimmedelecs.at(index_ele_trailing).Phi, MASS_E);
                    float betax = (xl-xv)/((tl-tv)*1e3*c_light);
                    float betay = (yl-yv)/((tl-tv)*1e3*c_light);
                    float betaz = (zl-zv)/((tl-tv)*1e3*c_light);
                    float gamma = 1.0/sqrt(1.0-(betax * betax + betay * betay + betaz * betaz));
                    TVector3 boostvector(betax, betay, betaz);
                    //TVector3 boostvector((xl-xv)/(tl-tv), (yl-yv)/(tl-tv), (zl-zv)/(tl-tv));
                    //if(boostvector.Mag() < 1 && fabs(tl-tv) > 3.0 * sigma * 1E-12) { 
                    if(boostvector.Mag() < 1) { 
                        a.Boost(-boostvector);
                        b.Boost(-boostvector);
                        c = a+b; 
                        d.SetPtEtaPhiM(c.Pt(), -c.Eta(), c.Phi() + TMath::Pi(), 1.0);
                        float reco_mass = (a+b+d).M(); 
                        massNe->Fill(reco_mass);
                    } 
	 	    }
              }			
 
        }


        TFile *f = new TFile(outputFile.c_str(), "recreate");
        f->cd();
        massZm->Write();
        dtvertexhistm->Write(); 
        dtleptonhistm->Write();
        pthistm->Write();
        pthiste->Write();
        dthistm->Write();
        dlvertexhistm->Write();
        dlleptonhistm->Write();
        dlhistm->Write();
        massNm->Write();
        d0vertexhistm->Write();
        d0leptonhistm->Write();
        d0histm->Write();
        massNm->Write();
        massZe->Write();
        dtvertexhiste->Write(); 
        dtleptonhiste->Write();
        dthiste->Write();
        dlvertexhiste->Write();
        dlleptonhiste->Write();
        dlhiste->Write();
        massNe->Write();
        d0vertexhiste->Write();
        d0leptonhiste->Write();
        d0histe->Write();
        massNe->Write();
        f->Close();
        return 1;

}
//***************************************************************************************************************//

