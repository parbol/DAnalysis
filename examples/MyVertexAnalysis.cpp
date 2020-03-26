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





//***************************************************************************************************************//
int main(int argc, char **argv) {

        std::string inputFile(argv[1]);
        std::string outputFile(argv[2]);

	d_ana::tTreeHandler tree(inputFile.c_str(), "Delphes");
        d_ana::dBranchHandler<Vertex> genvertex(&tree,"GenVertex");
        d_ana::dBranchHandler<Vertex> vertex(&tree,"Vertex");
        d_ana::dBranchHandler<Vertex> vertex4D(&tree,"Vertex4D");


        TH1I *ngenvertex = new TH1I("ngenvertex", "", 100, 0, 400);
        TH1I *nvertex = new TH1I("nvertex", "", 100, 0, 400);
        TH1I *nvertex4D = new TH1I("nvertex4D", "", 100, 0, 400);

        TH1F *vertexz = new TH1F("vertexz", "", 100, -0.5, 0.5);
        TH1F *vertex4Dz = new TH1F("vertex4Dz", "", 100, -0.5, 0.5);
        TH1F *vertex4Dt = new TH1F("vertex4Dt", "", 100, -100, 100);
       
        size_t nevents = tree.entries();
	for(size_t i=0;i<nevents;i++) {
            tree.setEntry(i); 
            ngenvertex->Fill(genvertex.size());
            nvertex->Fill(vertex.size());
            nvertex4D->Fill(vertex4D.size());
            float maxDistance;
            float distZ;
            int index;
            for(size_t j = 0; j < vertex.size(); j++) {
                maxDistance = 10000.0;
                distZ = 10000.0;
                index = -1;
                for(size_t k = 0; k < genvertex.size(); k++) {
		    distZ = fabs(genvertex.at(k)->Z - vertex.at(j)->Z);
                    if(distZ < maxDistance) {
                        maxDistance = distZ;
                        index = k;
                    } 
                }
                vertexz->Fill(-1.0*(genvertex.at(index)->Z - vertex.at(j)->Z));
            }
            for(size_t j = 0; j < vertex4D.size(); j++) {
                maxDistance = 10000.0;
                distZ = 10000.0;
                index = -1;
                for(size_t k = 0; k < genvertex.size(); k++) {
		    distZ = fabs(genvertex.at(k)->Z - vertex4D.at(j)->Z);
                    if(distZ < maxDistance) {
                        maxDistance = distZ;
                        index = k;
                    } 
                }
                vertex4Dz->Fill(-1.0*(genvertex.at(index)->Z - vertex4D.at(j)->Z));
                vertex4Dt->Fill(-1e12*(genvertex.at(index)->T - vertex4D.at(j)->T));
            }     
        }


        TFile *f = new TFile(outputFile.c_str(), "recreate");
        f->cd();
        ngenvertex->Write();
	nvertex->Write();
	nvertex4D->Write();
        vertexz->Write();
        vertex4Dz->Write();
        vertex4Dt->Write();
        f->Close();
 
        return 1;

}
//***************************************************************************************************************//

