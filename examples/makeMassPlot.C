#include "tdrstyle.C"
#include "TH1F.h"
#include "TLatex.h" 




float getResolution(TH1F *histo) {


    float val = 0;
    int meanbin = histo->FindBin(700);
    int minbin = histo->FindBin(400);
    
      
    for(size_t i = minbin; i < histo->GetNbinsX(); i++) {
        val = val + histo->GetBinContent(i);
    }

    float val2 = 0;
    float leftval;
    for(size_t i = meanbin; i < histo->GetNbinsX(); i++) {
        if(val2/val >= 0.34) {
            leftval = histo->GetBinCenter(i);
            break;
        }
        val2 = val2 + histo->GetBinContent(i);
    }
    float val3 = 0;
    float rightval;
    for(size_t i = meanbin-1; i > minbin; i--) {
        if(val3/val >= 0.34) {
            rightval = histo->GetBinCenter(i);
            break;
        }
        val3 = val3 + histo->GetBinContent(i);
    } 
    return -(rightval-leftval)/2.0; 
    //return histo->GetRMS(); 

}



     
    

void run(std::string tag, int tres) { 

    setTDRStyle();
    tdrStyle->SetOptFit(0);
    std::string nameFile100 = std::string("file_1000_700_100mm_v3_NOPU") + tag + std::string(".root");
    TFile *f_1000_700_100mm_NoPU = new TFile(nameFile100.c_str());
    TH1F *massN_1000_700_100mm_NoPUm = (TH1F *) f_1000_700_100mm_NoPU->Get("massNm");
    TH1F *massZ_1000_700_100mm_NoPUm = (TH1F *) f_1000_700_100mm_NoPU->Get("massZm");
    TH1F *pthist_1000_700_100mm_NoPUm = (TH1F *) f_1000_700_100mm_NoPU->Get("pthistm");
    TH1F *dthist_1000_700_100mm_NoPUm = (TH1F *) f_1000_700_100mm_NoPU->Get("dthistm");
    TH1F *dlhist_1000_700_100mm_NoPUm = (TH1F *) f_1000_700_100mm_NoPU->Get("dlhistm");
    TH1F *massN_1000_700_100mm_NoPUe = (TH1F *) f_1000_700_100mm_NoPU->Get("massNe");
    TH1F *massZ_1000_700_100mm_NoPUe = (TH1F *) f_1000_700_100mm_NoPU->Get("massZe");
    TH1F *pthist_1000_700_100mm_NoPUe = (TH1F *) f_1000_700_100mm_NoPU->Get("pthiste");
    TH1F *dthist_1000_700_100mm_NoPUe = (TH1F *) f_1000_700_100mm_NoPU->Get("dthiste");
    TH1F *dlhist_1000_700_100mm_NoPUe = (TH1F *) f_1000_700_100mm_NoPU->Get("dlhiste");
    
    std::string nameFile30 = std::string("file_1000_700_30mm_v3_NOPU") + tag + std::string(".root");
    TFile *f_1000_700_30mm_NoPU = new TFile(nameFile30.c_str());
    TH1F *massN_1000_700_30mm_NoPUm = (TH1F *) f_1000_700_30mm_NoPU->Get("massNm");
    TH1F *massZ_1000_700_30mm_NoPUm = (TH1F *) f_1000_700_30mm_NoPU->Get("massZm");
    TH1F *pthist_1000_700_30mm_NoPUm = (TH1F *) f_1000_700_30mm_NoPU->Get("pthistm");
    TH1F *dthist_1000_700_30mm_NoPUm = (TH1F *) f_1000_700_30mm_NoPU->Get("dthistm");
    TH1F *dlhist_1000_700_30mm_NoPUm = (TH1F *) f_1000_700_30mm_NoPU->Get("dlhistm");
    TH1F *massN_1000_700_30mm_NoPUe = (TH1F *) f_1000_700_30mm_NoPU->Get("massNe");
    TH1F *massZ_1000_700_30mm_NoPUe = (TH1F *) f_1000_700_30mm_NoPU->Get("massZe");
    TH1F *pthist_1000_700_30mm_NoPUe = (TH1F *) f_1000_700_30mm_NoPU->Get("pthiste");
    TH1F *dthist_1000_700_30mm_NoPUe = (TH1F *) f_1000_700_30mm_NoPU->Get("dthiste");
    TH1F *dlhist_1000_700_30mm_NoPUe = (TH1F *) f_1000_700_30mm_NoPU->Get("dlhiste");
    
    std::string nameFile10 = std::string("file_1000_700_10mm_v3_NOPU") + tag + std::string(".root");
    TFile *f_1000_700_10mm_NoPU = new TFile(nameFile10.c_str());
    TH1F *massN_1000_700_10mm_NoPUm = (TH1F *) f_1000_700_10mm_NoPU->Get("massNm");
    TH1F *massZ_1000_700_10mm_NoPUm = (TH1F *) f_1000_700_10mm_NoPU->Get("massZm");
    TH1F *pthist_1000_700_10mm_NoPUm = (TH1F *) f_1000_700_10mm_NoPU->Get("pthistm");
    TH1F *dthist_1000_700_10mm_NoPUm = (TH1F *) f_1000_700_10mm_NoPU->Get("dthistm");
    TH1F *dlhist_1000_700_10mm_NoPUm = (TH1F *) f_1000_700_10mm_NoPU->Get("dlhistm");
    TH1F *massN_1000_700_10mm_NoPUe = (TH1F *) f_1000_700_10mm_NoPU->Get("massNe");
    TH1F *massZ_1000_700_10mm_NoPUe = (TH1F *) f_1000_700_10mm_NoPU->Get("massZe");
    TH1F *pthist_1000_700_10mm_NoPUe = (TH1F *) f_1000_700_10mm_NoPU->Get("pthiste");
    TH1F *dthist_1000_700_10mm_NoPUe = (TH1F *) f_1000_700_10mm_NoPU->Get("dthiste");
    TH1F *dlhist_1000_700_10mm_NoPUe = (TH1F *) f_1000_700_10mm_NoPU->Get("dlhiste");
    
    std::string nameFile3 = std::string("file_1000_700_3mm_v3_NOPU") + tag + std::string(".root");
    TFile *f_1000_700_3mm_NoPU = new TFile(nameFile3.c_str());
    TH1F *massN_1000_700_3mm_NoPUm = (TH1F *) f_1000_700_3mm_NoPU->Get("massNm");
    TH1F *massZ_1000_700_3mm_NoPUm = (TH1F *) f_1000_700_3mm_NoPU->Get("massZm");
    TH1F *pthist_1000_700_3mm_NoPUm = (TH1F *) f_1000_700_3mm_NoPU->Get("pthistm");
    TH1F *dthist_1000_700_3mm_NoPUm = (TH1F *) f_1000_700_3mm_NoPU->Get("dthistm");
    TH1F *dlhist_1000_700_3mm_NoPUm = (TH1F *) f_1000_700_3mm_NoPU->Get("dlhistm");
    TH1F *massN_1000_700_3mm_NoPUe = (TH1F *) f_1000_700_3mm_NoPU->Get("massNe");
    TH1F *massZ_1000_700_3mm_NoPUe = (TH1F *) f_1000_700_3mm_NoPU->Get("massZe");
    TH1F *pthist_1000_700_3mm_NoPUe = (TH1F *) f_1000_700_3mm_NoPU->Get("pthiste");
    TH1F *dthist_1000_700_3mm_NoPUe = (TH1F *) f_1000_700_3mm_NoPU->Get("dthiste");
    TH1F *dlhist_1000_700_3mm_NoPUe = (TH1F *) f_1000_700_3mm_NoPU->Get("dlhiste");
    
   std::string nameFile4 = std::string("file_dyjets_NOPU") + tag + std::string(".root");
    TFile *f_dyjets_NoPU = new TFile(nameFile4.c_str());
    TH1F *massN_dyjets_NoPUm = (TH1F *) f_dyjets_NoPU->Get("massNm");
    TH1F *massZ_dyjets_NoPUm = (TH1F *) f_dyjets_NoPU->Get("massZm");
    TH1F *pthist_dyjets_NoPUm = (TH1F *) f_dyjets_NoPU->Get("pthistm");
    TH1F *dthist_dyjets_NoPUm = (TH1F *) f_dyjets_NoPU->Get("dthistm");
    TH1F *dlhist_dyjets_NoPUm = (TH1F *) f_dyjets_NoPU->Get("dlhistm");
    TH1F *massN_dyjets_NoPUe = (TH1F *) f_dyjets_NoPU->Get("massNe");
    TH1F *massZ_dyjets_NoPUe = (TH1F *) f_dyjets_NoPU->Get("massZe");
    TH1F *pthist_dyjets_NoPUe = (TH1F *) f_dyjets_NoPU->Get("pthiste");
    TH1F *dthist_dyjets_NoPUe = (TH1F *) f_dyjets_NoPU->Get("dthiste");
    TH1F *dlhist_dyjets_NoPUe = (TH1F *) f_dyjets_NoPU->Get("dlhiste");

    std::string nameFile5 = std::string("file_ttbar_NOPU") + tag + std::string(".root");
    TFile *f_ttbar_NoPU = new TFile(nameFile5.c_str());
    TH1F *massN_ttbar_NoPUm = (TH1F *) f_ttbar_NoPU->Get("massNm");
    TH1F *massZ_ttbar_NoPUm = (TH1F *) f_ttbar_NoPU->Get("massZm");
    TH1F *pthist_ttbar_NoPUm = (TH1F *) f_ttbar_NoPU->Get("pthistm");
    TH1F *dthist_ttbar_NoPUm = (TH1F *) f_ttbar_NoPU->Get("dthistm");
    TH1F *dlhist_ttbar_NoPUm = (TH1F *) f_ttbar_NoPU->Get("dlhistm");
    TH1F *massN_ttbar_NoPUe = (TH1F *) f_ttbar_NoPU->Get("massNe");
    TH1F *massZ_ttbar_NoPUe = (TH1F *) f_ttbar_NoPU->Get("massZe");
    TH1F *pthist_ttbar_NoPUe = (TH1F *) f_ttbar_NoPU->Get("pthiste");
    TH1F *dthist_ttbar_NoPUe = (TH1F *) f_ttbar_NoPU->Get("dthiste");
    TH1F *dlhist_ttbar_NoPUe = (TH1F *) f_ttbar_NoPU->Get("dlhiste");


    massN_1000_700_100mm_NoPUm->GetXaxis()->SetTitle("M(#chi^{0}_{1}) [GeV]");
    massN_1000_700_30mm_NoPUm->GetXaxis()->SetTitle("M(#chi^{0}_{1}) [GeV]");
    massN_1000_700_10mm_NoPUm->GetXaxis()->SetTitle("M(#chi^{0}_{1}) [GeV]");
    massN_1000_700_3mm_NoPUm->GetXaxis()->SetTitle("M(#chi^{0}_{1}) [GeV]");
    
    massZ_1000_700_100mm_NoPUm->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    massZ_1000_700_30mm_NoPUm->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    massZ_1000_700_10mm_NoPUm->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    massZ_1000_700_3mm_NoPUm->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    massZ_dyjets_NoPUm->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    massZ_ttbar_NoPUm->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    
    dthist_1000_700_100mm_NoPUm->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dthist_1000_700_30mm_NoPUm->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dthist_1000_700_10mm_NoPUm->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dthist_1000_700_3mm_NoPUm->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dthist_dyjets_NoPUm->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dthist_ttbar_NoPUm->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    
    dlhist_1000_700_100mm_NoPUm->GetXaxis()->SetTitle("|P(l^{+}l^{-})-P(PV)| [mm]");
    dlhist_1000_700_30mm_NoPUm->GetXaxis()->SetTitle("|P(l^{+}l^{-})-P(PV)| [mm]");
    dlhist_1000_700_10mm_NoPUm->GetXaxis()->SetTitle("|P(l^{+}l^{-})-P(PV)| [mm]");
    dlhist_1000_700_3mm_NoPUm->GetXaxis()->SetTitle("|P(l^{+}l^{-})-P(PV)| [mm]");
    dlhist_dyjets_NoPUm->GetXaxis()->SetTitle("|P(l^{+}l^{-})-P(PV)| [mm]");
    dlhist_ttbar_NoPUm->GetXaxis()->SetTitle("|P(l^{+}l^{-})-P(PV)| [mm]");

    pthist_1000_700_100mm_NoPUm->GetXaxis()->SetTitle("p_{T} [GeV]");
    pthist_1000_700_30mm_NoPUm->GetXaxis()->SetTitle("p_{T} [GeV]");
    pthist_1000_700_10mm_NoPUm->GetXaxis()->SetTitle("p_{T} [GeV]");
    pthist_1000_700_3mm_NoPUm->GetXaxis()->SetTitle("p_{T} [GeV]");
    pthist_dyjets_NoPUm->GetXaxis()->SetTitle("p_{T} [GeV]");
    pthist_ttbar_NoPUm->GetXaxis()->SetTitle("p_{T} [GeV]");

    massN_1000_700_100mm_NoPUe->GetXaxis()->SetTitle("M(#chi^{0}_{1}) [GeV]");
    massN_1000_700_30mm_NoPUe->GetXaxis()->SetTitle("M(#chi^{0}_{1}) [GeV]");
    massN_1000_700_10mm_NoPUe->GetXaxis()->SetTitle("M(#chi^{0}_{1}) [GeV]");
    massN_1000_700_3mm_NoPUe->GetXaxis()->SetTitle("M(#chi^{0}_{1}) [GeV]");
    
    massZ_1000_700_100mm_NoPUe->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    massZ_1000_700_30mm_NoPUe->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    massZ_1000_700_10mm_NoPUe->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    massZ_1000_700_3mm_NoPUe->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    massZ_dyjets_NoPUe->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    massZ_ttbar_NoPUe->GetXaxis()->SetTitle("M(l^{+}l^{-}) [GeV]");
    
    dthist_1000_700_100mm_NoPUe->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dthist_1000_700_30mm_NoPUe->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dthist_1000_700_10mm_NoPUe->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dthist_1000_700_3mm_NoPUe->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dthist_dyjets_NoPUe->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dthist_ttbar_NoPUe->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    
    dlhist_1000_700_100mm_NoPUe->GetXaxis()->SetTitle("|P(l^{+}l^{-})-P(PV)| [mm]");
    dlhist_1000_700_30mm_NoPUe->GetXaxis()->SetTitle("|P(l^{+}l^{-})-P(PV)| [mm]");
    dlhist_1000_700_10mm_NoPUe->GetXaxis()->SetTitle("|P(l^{+}l^{-})-P(PV)| [mm]");
    dlhist_1000_700_3mm_NoPUe->GetXaxis()->SetTitle("|P(l^{+}l^{-})-P(PV)| [mm]");
    dlhist_dyjets_NoPUe->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    dlhist_ttbar_NoPUe->GetXaxis()->SetTitle("t(l^{+}l^{-}) - t(PV) [ps]");
    
    pthist_1000_700_100mm_NoPUe->GetXaxis()->SetTitle("p_{T} [GeV]");
    pthist_1000_700_30mm_NoPUe->GetXaxis()->SetTitle("p_{T} [GeV]");
    pthist_1000_700_10mm_NoPUe->GetXaxis()->SetTitle("p_{T} [GeV]");
    pthist_1000_700_3mm_NoPUe->GetXaxis()->SetTitle("p_{T} [GeV]");
    pthist_dyjets_NoPUe->GetXaxis()->SetTitle("p_{T} [GeV]");
    pthist_ttbar_NoPUe->GetXaxis()->SetTitle("p_{T} [GeV]");

 

    massN_1000_700_100mm_NoPUm->SetLineColor(kBlue);
    massN_1000_700_30mm_NoPUm->SetLineColor(kRed);
    massN_1000_700_10mm_NoPUm->SetLineColor(kGreen);
    massN_1000_700_3mm_NoPUm->SetLineColor(kMagenta);
    massN_dyjets_NoPUm->SetLineColor(kBlack);
    massN_ttbar_NoPUm->SetLineColor(kOrange);
    
    massZ_1000_700_100mm_NoPUm->SetLineColor(kBlue);
    massZ_1000_700_30mm_NoPUm->SetLineColor(kRed);
    massZ_1000_700_10mm_NoPUm->SetLineColor(kGreen);
    massZ_1000_700_3mm_NoPUm->SetLineColor(kMagenta);
    massZ_dyjets_NoPUm->SetLineColor(kBlack);
    massZ_ttbar_NoPUm->SetLineColor(kOrange);
    
    dthist_1000_700_100mm_NoPUm->SetLineColor(kBlue);
    dthist_1000_700_30mm_NoPUm->SetLineColor(kRed);
    dthist_1000_700_10mm_NoPUm->SetLineColor(kGreen);
    dthist_1000_700_3mm_NoPUm->SetLineColor(kMagenta);
    dthist_dyjets_NoPUm->SetLineColor(kBlack);
    dthist_ttbar_NoPUm->SetLineColor(kOrange);
    
    dlhist_1000_700_100mm_NoPUm->SetLineColor(kBlue);
    dlhist_1000_700_30mm_NoPUm->SetLineColor(kRed);
    dlhist_1000_700_10mm_NoPUm->SetLineColor(kGreen);
    dlhist_1000_700_3mm_NoPUm->SetLineColor(kMagenta);
    dlhist_dyjets_NoPUm->SetLineColor(kBlack);
    dlhist_ttbar_NoPUm->SetLineColor(kOrange);
    
    pthist_1000_700_100mm_NoPUm->SetLineColor(kBlue);
    pthist_1000_700_30mm_NoPUm->SetLineColor(kRed);
    pthist_1000_700_10mm_NoPUm->SetLineColor(kGreen);
    pthist_1000_700_3mm_NoPUm->SetLineColor(kMagenta);
    pthist_dyjets_NoPUm->SetLineColor(kBlack);
    pthist_ttbar_NoPUm->SetLineColor(kOrange);
    
    massN_1000_700_100mm_NoPUm->SetLineWidth(3);
    massN_1000_700_30mm_NoPUm->SetLineWidth(3);
    massN_1000_700_10mm_NoPUm->SetLineWidth(3);
    massN_1000_700_3mm_NoPUm->SetLineWidth(3);
    massN_dyjets_NoPUm->SetLineWidth(3);
    massN_ttbar_NoPUm->SetLineWidth(3);
    
    massZ_1000_700_100mm_NoPUm->SetLineWidth(3);
    massZ_1000_700_30mm_NoPUm->SetLineWidth(3);
    massZ_1000_700_10mm_NoPUm->SetLineWidth(3);
    massZ_1000_700_3mm_NoPUm->SetLineWidth(3);
    massZ_dyjets_NoPUm->SetLineWidth(3);
    massZ_ttbar_NoPUm->SetLineWidth(3);

    dthist_1000_700_100mm_NoPUm->SetLineWidth(3);
    dthist_1000_700_30mm_NoPUm->SetLineWidth(3);
    dthist_1000_700_10mm_NoPUm->SetLineWidth(3);
    dthist_1000_700_3mm_NoPUm->SetLineWidth(3);
    dthist_dyjets_NoPUm->SetLineWidth(3);
    dthist_ttbar_NoPUm->SetLineWidth(3);
    
    pthist_1000_700_100mm_NoPUm->SetLineWidth(3);
    pthist_1000_700_30mm_NoPUm->SetLineWidth(3);
    pthist_1000_700_10mm_NoPUm->SetLineWidth(3);
    pthist_1000_700_3mm_NoPUm->SetLineWidth(3);
    pthist_dyjets_NoPUm->SetLineWidth(3);
    pthist_ttbar_NoPUm->SetLineWidth(3);
    
    dlhist_1000_700_100mm_NoPUm->SetLineWidth(3);
    dlhist_1000_700_30mm_NoPUm->SetLineWidth(3);
    dlhist_1000_700_10mm_NoPUm->SetLineWidth(3);
    dlhist_1000_700_3mm_NoPUm->SetLineWidth(3);
    dlhist_dyjets_NoPUm->SetLineWidth(3);
    dlhist_ttbar_NoPUm->SetLineWidth(3);

    pthist_1000_700_100mm_NoPUe->SetLineColor(kBlue);
    pthist_1000_700_30mm_NoPUe->SetLineColor(kRed);
    pthist_1000_700_10mm_NoPUe->SetLineColor(kGreen);
    pthist_1000_700_3mm_NoPUe->SetLineColor(kMagenta);
    pthist_dyjets_NoPUe->SetLineColor(kBlack);
    pthist_ttbar_NoPUe->SetLineColor(kOrange);

    massN_1000_700_100mm_NoPUe->SetLineColor(kBlue);
    massN_1000_700_30mm_NoPUe->SetLineColor(kRed);
    massN_1000_700_10mm_NoPUe->SetLineColor(kGreen);
    massN_1000_700_3mm_NoPUe->SetLineColor(kMagenta);
    massN_dyjets_NoPUe->SetLineColor(kBlack);
    massN_ttbar_NoPUe->SetLineColor(kOrange);
    
    massZ_1000_700_100mm_NoPUe->SetLineColor(kBlue);
    massZ_1000_700_30mm_NoPUe->SetLineColor(kRed);
    massZ_1000_700_10mm_NoPUe->SetLineColor(kGreen);
    massZ_1000_700_3mm_NoPUe->SetLineColor(kMagenta);
    massZ_dyjets_NoPUe->SetLineColor(kBlack);
    massZ_ttbar_NoPUe->SetLineColor(kOrange);
    
    dthist_1000_700_100mm_NoPUe->SetLineColor(kBlue);
    dthist_1000_700_30mm_NoPUe->SetLineColor(kRed);
    dthist_1000_700_10mm_NoPUe->SetLineColor(kGreen);
    dthist_1000_700_3mm_NoPUe->SetLineColor(kMagenta);
    massZ_dyjets_NoPUe->SetLineColor(kBlack);
    massZ_ttbar_NoPUe->SetLineColor(kOrange);
    
    dlhist_1000_700_100mm_NoPUe->SetLineColor(kBlue);
    dlhist_1000_700_30mm_NoPUe->SetLineColor(kRed);
    dlhist_1000_700_10mm_NoPUe->SetLineColor(kGreen);
    dlhist_1000_700_3mm_NoPUe->SetLineColor(kMagenta);
    dlhist_dyjets_NoPUe->SetLineColor(kBlack);
    dlhist_ttbar_NoPUe->SetLineColor(kOrange);
    
    massN_1000_700_100mm_NoPUe->SetLineWidth(3);
    massN_1000_700_30mm_NoPUe->SetLineWidth(3);
    massN_1000_700_10mm_NoPUe->SetLineWidth(3);
    massN_1000_700_3mm_NoPUe->SetLineWidth(3);
    massN_dyjets_NoPUe->SetLineWidth(3);
    massN_ttbar_NoPUe->SetLineWidth(3);
    
    massZ_1000_700_100mm_NoPUe->SetLineWidth(3);
    massZ_1000_700_30mm_NoPUe->SetLineWidth(3);
    massZ_1000_700_10mm_NoPUe->SetLineWidth(3);
    massZ_1000_700_3mm_NoPUe->SetLineWidth(3);
    massZ_dyjets_NoPUe->SetLineWidth(3);
    massZ_ttbar_NoPUe->SetLineWidth(3);

    dthist_1000_700_100mm_NoPUe->SetLineWidth(3);
    dthist_1000_700_30mm_NoPUe->SetLineWidth(3);
    dthist_1000_700_10mm_NoPUe->SetLineWidth(3);
    dthist_1000_700_3mm_NoPUe->SetLineWidth(3);
    dthist_dyjets_NoPUe->SetLineWidth(3);
    dthist_ttbar_NoPUe->SetLineWidth(3);

    pthist_1000_700_100mm_NoPUe->SetLineWidth(3);
    pthist_1000_700_30mm_NoPUe->SetLineWidth(3);
    pthist_1000_700_10mm_NoPUe->SetLineWidth(3);
    pthist_1000_700_3mm_NoPUe->SetLineWidth(3);
    pthist_dyjets_NoPUe->SetLineWidth(3);
    pthist_ttbar_NoPUe->SetLineWidth(3);
    
    dlhist_1000_700_100mm_NoPUe->SetLineWidth(3);
    dlhist_1000_700_30mm_NoPUe->SetLineWidth(3);
    dlhist_1000_700_10mm_NoPUe->SetLineWidth(3);
    dlhist_1000_700_3mm_NoPUe->SetLineWidth(3);
    dlhist_dyjets_NoPUe->SetLineWidth(3);
    dlhist_ttbar_NoPUe->SetLineWidth(3);

    TLegend *legn =  new TLegend(0.6, 0.3, 0.8, 0.6);
    legn->SetFillColor(kWhite);
    legn->SetTextFont(42);
    legn->SetTextSize(0.035);
    legn->SetLineWidth(0);
    legn->SetBorderSize(0);
    legn->AddEntry(massN_1000_700_100mm_NoPUm, "c#tau = 100mm", "L");
    legn->AddEntry(massN_1000_700_30mm_NoPUm, "c#tau = 30mm", "L");
    legn->AddEntry(massN_1000_700_10mm_NoPUm, "c#tau = 10mm", "L");
    legn->AddEntry(massN_1000_700_3mm_NoPUm, "c#tau = 3mm", "L");

    TLatex latex;
    latex.SetNDC();
    latex.SetTextAngle(0);
    latex.SetTextColor(kBlack);
    latex.SetTextFont(42);
    latex.SetTextAlign(31);
    latex.SetTextSize(0.03);
    TLegend *leg =  new TLegend(0.6, 0.4, 0.85, 0.75);
    leg->SetFillColor(kWhite);
    leg->SetTextFont(42);
    leg->SetTextSize(0.035);
    leg->SetLineWidth(0);
    leg->SetBorderSize(0);
    leg->AddEntry(massN_1000_700_100mm_NoPUm, "c#tau = 100mm", "L");
    leg->AddEntry(massN_1000_700_30mm_NoPUm, "c#tau = 30mm", "L");
    leg->AddEntry(massN_1000_700_10mm_NoPUm, "c#tau = 10mm", "L");
    leg->AddEntry(massN_1000_700_3mm_NoPUm, "c#tau = 3mm", "L");
    leg->AddEntry(massN_dyjets_NoPUm, "DY+Jets", "L");
    leg->AddEntry(massN_ttbar_NoPUm, "TT+Jets", "L");

    TLegend *legdt =  new TLegend(0.6, 0.4, 0.85, 0.75);
    legdt->SetFillColor(kWhite);
    legdt->SetTextFont(42);
    legdt->SetTextSize(0.035);
    legdt->SetLineWidth(0);
    legdt->SetBorderSize(0);
    legdt->AddEntry(massN_1000_700_100mm_NoPUm, "c#tau = 100mm", "L");
    legdt->AddEntry(massN_1000_700_30mm_NoPUm, "c#tau = 30mm", "L");
    legdt->AddEntry(massN_1000_700_10mm_NoPUm, "c#tau = 10mm", "L");
    legdt->AddEntry(massN_1000_700_3mm_NoPUm, "c#tau = 3mm", "L");
    legdt->AddEntry(massN_dyjets_NoPUm, "DY+Jets", "L");
    legdt->AddEntry(massN_ttbar_NoPUm, "TT+Jets", "L");

    TLegend *legpt =  new TLegend(0.6, 0.4, 0.85, 0.75);
    legpt->SetFillColor(kWhite);
    legpt->SetTextFont(42);
    legpt->SetTextSize(0.035);
    legpt->SetLineWidth(0);
    legpt->SetBorderSize(0);
    legpt->AddEntry(massN_1000_700_100mm_NoPUm, "c#tau = 100mm", "L");
    legpt->AddEntry(massN_1000_700_30mm_NoPUm, "c#tau = 30mm", "L");
    legpt->AddEntry(massN_1000_700_10mm_NoPUm, "c#tau = 10mm", "L");
    legpt->AddEntry(massN_1000_700_3mm_NoPUm, "c#tau = 3mm", "L");
    legpt->AddEntry(massN_dyjets_NoPUm, "DY+Jets", "L");
    legpt->AddEntry(massN_ttbar_NoPUm, "TT+Jets", "L");

    TLegend *leg2 =  new TLegend(0.2, 0.35, 0.5, 0.65);
    leg2->SetFillColor(kWhite);
    leg2->SetTextFont(42);
    leg2->SetTextSize(0.035);
    leg2->SetLineWidth(0);
    leg2->SetBorderSize(0);
    leg2->AddEntry(massN_1000_700_100mm_NoPUm, "c#tau = 100mm", "L");
    leg2->AddEntry(massN_1000_700_30mm_NoPUm, "c#tau = 30mm", "L");
    leg2->AddEntry(massN_1000_700_10mm_NoPUm, "c#tau = 10mm", "L");
    leg2->AddEntry(massN_1000_700_3mm_NoPUm, "c#tau = 3mm", "L");
    leg2->AddEntry(massN_dyjets_NoPUm, "DY+Jets", "L");
    leg2->AddEntry(massN_ttbar_NoPUm, "TT+Jets", "L");

 
    TCanvas *can_massNm = new TCanvas("can_massNm", "can_massNm");
    can_massNm->cd();
    TF1 *f100m = new TF1("f100m", "gaus");
    TF1 *f30m = new TF1("f30m", "gaus");
    TF1 *f10m = new TF1("f10m", "gaus");
    TF1 *f3m = new TF1("f3m", "gaus");
    massN_1000_700_100mm_NoPUm->Draw();
    massN_1000_700_100mm_NoPUm->Fit("f100m", "", "", 500, 900);
    massN_1000_700_30mm_NoPUm->Draw();
    massN_1000_700_30mm_NoPUm->Fit("f30m", "", "", 500, 900);
    massN_1000_700_10mm_NoPUm->Draw();
    massN_1000_700_10mm_NoPUm->Fit("f10m", "", "", 500, 900);
    massN_1000_700_3mm_NoPUm->Draw();
    massN_1000_700_3mm_NoPUm->Fit("f3m", "", "", 500, 900);
    massN_1000_700_100mm_NoPUm->GetFunction("f100m")->SetBit(TF1::kNotDraw);
    massN_1000_700_30mm_NoPUm->GetFunction("f30m")->SetBit(TF1::kNotDraw);
    massN_1000_700_10mm_NoPUm->GetFunction("f10m")->SetBit(TF1::kNotDraw);
    massN_1000_700_3mm_NoPUm->GetFunction("f3m")->SetBit(TF1::kNotDraw);
    massN_1000_700_100mm_NoPUm->GetYaxis()->SetRangeUser(0, 450);
    massN_1000_700_100mm_NoPUm->Draw();
    massN_1000_700_30mm_NoPUm->Draw("SAME");
    massN_1000_700_10mm_NoPUm->Draw("SAME");
    massN_1000_700_3mm_NoPUm->Draw("SAME");
    legn->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");
    std::string namemassesm = std::string("Masses") + tag + std::string("muon.png");
    std::string namemassesmpdf = std::string("Masses") + tag + std::string("muon.pdf");
    can_massNm->SaveAs(namemassesm.c_str());
    can_massNm->SaveAs(namemassesmpdf.c_str());

    TCanvas *can_massZm = new TCanvas("can_massZm", "can_massZm");
    can_massZm->cd();
    massZ_1000_700_100mm_NoPUm->Scale(1.0/massZ_1000_700_100mm_NoPUm->Integral());
    massZ_1000_700_30mm_NoPUm->Scale(1.0/massZ_1000_700_30mm_NoPUm->Integral());
    massZ_1000_700_10mm_NoPUm->Scale(1.0/massZ_1000_700_10mm_NoPUm->Integral());
    massZ_1000_700_3mm_NoPUm->Scale(1.0/massZ_1000_700_3mm_NoPUm->Integral());
    massZ_dyjets_NoPUm->Scale(1.0/massZ_dyjets_NoPUm->Integral());
    massZ_ttbar_NoPUm->Scale(1.0/massZ_ttbar_NoPUm->Integral());

    massZ_1000_700_100mm_NoPUm->GetYaxis()->SetRangeUser(0, 0.22);
    massZ_1000_700_100mm_NoPUm->Draw("hist");
    massZ_1000_700_30mm_NoPUm->Draw("SAME,hist");
    massZ_1000_700_10mm_NoPUm->Draw("SAME,hist");
    massZ_1000_700_3mm_NoPUm->Draw("SAME,hist");
    massZ_dyjets_NoPUm->Draw("SAME,hist");
    massZ_ttbar_NoPUm->Draw("SAME,hist");
    leg2->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");
    std::string namemassesZm = std::string("MassesZ") + tag + std::string("muon.png");
    std::string namemassesZmpdf = std::string("MassesZ") + tag + std::string("muon.pdf");
    can_massZm->SaveAs(namemassesZm.c_str());
    can_massZm->SaveAs(namemassesZmpdf.c_str());

    TCanvas *can_ptm = new TCanvas("can_ptm", "can_ptm");
    can_ptm->cd();
    can_ptm->SetLogy();
    pthist_1000_700_100mm_NoPUm->Scale(1.0/pthist_1000_700_100mm_NoPUm->Integral());
    pthist_1000_700_30mm_NoPUm->Scale(1.0/pthist_1000_700_30mm_NoPUm->Integral());
    pthist_1000_700_10mm_NoPUm->Scale(1.0/pthist_1000_700_10mm_NoPUm->Integral());
    pthist_1000_700_3mm_NoPUm->Scale(1.0/pthist_1000_700_3mm_NoPUm->Integral());
    pthist_dyjets_NoPUm->Scale(1.0/pthist_dyjets_NoPUm->Integral());
    pthist_ttbar_NoPUm->Scale(1.0/pthist_ttbar_NoPUm->Integral());

    pthist_dyjets_NoPUm->Draw("hist");
    pthist_ttbar_NoPUm->Draw("SAME,hist");
    pthist_1000_700_100mm_NoPUm->Draw("SAME,hist");
    pthist_1000_700_30mm_NoPUm->Draw("SAME,hist");
    pthist_1000_700_10mm_NoPUm->Draw("SAME,hist");
    pthist_1000_700_3mm_NoPUm->Draw("SAME,hist");
    legpt->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");
    std::string nameptm = std::string("pt") + tag + std::string("muon.png");
    std::string nameptmpdf = std::string("pt") + tag + std::string("muon.pdf");
    can_ptm->SaveAs(nameptm.c_str());
    can_ptm->SaveAs(nameptmpdf.c_str());


    TCanvas *can_dthistm = new TCanvas("can_dthistm", "can_dthistm");
    can_dthistm->cd();
    dthist_1000_700_3mm_NoPUm->Draw();
    dthist_1000_700_10mm_NoPUm->Draw("SAME");
    dthist_1000_700_30mm_NoPUm->Draw("SAME");
    dthist_1000_700_100mm_NoPUm->Draw("SAME");
    legdt->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");
    std::string namedtm = std::string("dt") + tag + std::string("muon.png");
    std::string namedtmpdf = std::string("dt") + tag + std::string("muon.pdf");
    can_dthistm->SaveAs(namedtm.c_str());
    can_dthistm->SaveAs(namedtmpdf.c_str());

    TCanvas *can_dlhistm = new TCanvas("can_dlhistm", "can_dlhistm");
    can_dlhistm->cd();
    dlhist_1000_700_3mm_NoPUm->Draw();
    dlhist_1000_700_10mm_NoPUm->Draw("SAME");
    dlhist_1000_700_30mm_NoPUm->Draw("SAME");
    dlhist_1000_700_100mm_NoPUm->Draw("SAME");
    leg->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    std::string namedlm = std::string("dl") + tag + std::string("muon.png");
    std::string namedlmpdf = std::string("dl") + tag + std::string("muon.pdf");
    can_dlhistm->SaveAs(namedlm.c_str());
    can_dlhistm->SaveAs(namedlmpdf.c_str());


    TCanvas *can_massNe = new TCanvas("can_massNe", "can_massNe");
    can_massNe->cd();
    TF1 *f100e = new TF1("f100e", "gaus");
    TF1 *f30e = new TF1("f30e", "gaus");
    TF1 *f10e = new TF1("f10e", "gaus");
    TF1 *f3e = new TF1("f3e", "gaus");
    massN_1000_700_100mm_NoPUe->Draw();
    massN_1000_700_100mm_NoPUe->Fit("f100e", "", "", 500, 900);
    massN_1000_700_30mm_NoPUe->Draw();
    massN_1000_700_30mm_NoPUe->Fit("f30e", "", "", 500, 900);
    massN_1000_700_10mm_NoPUe->Draw();
    massN_1000_700_10mm_NoPUe->Fit("f10e", "", "", 500, 900);
    massN_1000_700_3mm_NoPUe->Draw();
    massN_1000_700_3mm_NoPUe->Fit("f3e", "", "", 500, 900);
    massN_1000_700_100mm_NoPUe->GetFunction("f100e")->SetBit(TF1::kNotDraw);
    massN_1000_700_30mm_NoPUe->GetFunction("f30e")->SetBit(TF1::kNotDraw);
    massN_1000_700_10mm_NoPUe->GetFunction("f10e")->SetBit(TF1::kNotDraw);
    massN_1000_700_3mm_NoPUe->GetFunction("f3e")->SetBit(TF1::kNotDraw);
    massN_1000_700_100mm_NoPUe->GetYaxis()->SetRangeUser(0, 550);
    massN_1000_700_100mm_NoPUe->Draw();
    massN_1000_700_30mm_NoPUe->Draw("SAME");
    massN_1000_700_10mm_NoPUe->Draw("SAME");
    massN_1000_700_3mm_NoPUe->Draw("SAME");
    legn->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");
    std::string namemassese = std::string("Masses") + tag + std::string("electron.png");
    std::string namemassesepdf = std::string("Masses") + tag + std::string("electron.pdf");
    can_massNe->SaveAs(namemassese.c_str());
    can_massNe->SaveAs(namemassesepdf.c_str());

    TCanvas *can_massZe = new TCanvas("can_massZe", "can_massZe");
    can_massZe->cd();
    massZ_1000_700_100mm_NoPUe->Scale(1.0/massZ_1000_700_100mm_NoPUe->Integral());
    massZ_1000_700_30mm_NoPUe->Scale(1.0/massZ_1000_700_30mm_NoPUe->Integral());
    massZ_1000_700_10mm_NoPUe->Scale(1.0/massZ_1000_700_10mm_NoPUe->Integral());
    massZ_1000_700_3mm_NoPUe->Scale(1.0/massZ_1000_700_3mm_NoPUe->Integral());
    massZ_dyjets_NoPUe->Scale(1.0/massZ_dyjets_NoPUe->Integral());
    massZ_ttbar_NoPUe->Scale(1.0/massZ_ttbar_NoPUe->Integral());

    massZ_dyjets_NoPUe->GetYaxis()->SetRangeUser(0, 0.22);
    massZ_dyjets_NoPUe->Draw("hist");
    massZ_1000_700_100mm_NoPUe->Draw("SAME,hist");
    massZ_1000_700_30mm_NoPUe->Draw("SAME,hist");
    massZ_1000_700_10mm_NoPUe->Draw("SAME,hist");
    massZ_1000_700_3mm_NoPUe->Draw("SAME,hist");
    massZ_dyjets_NoPUe->Draw("SAME,hist");
    massZ_ttbar_NoPUe->Draw("SAME,hist");
    leg2->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");
    std::string namemassesZe = std::string("MassesZ") + tag + std::string("electron.png");
    std::string namemassesZepdf = std::string("MassesZ") + tag + std::string("electron.pdf");
    can_massZe->SaveAs(namemassesZe.c_str());
    can_massZe->SaveAs(namemassesZepdf.c_str());

    TCanvas *can_pte = new TCanvas("can_pte", "can_pte");
    can_pte->cd();
    can_pte->SetLogy();
    pthist_1000_700_100mm_NoPUe->Scale(1.0/pthist_1000_700_100mm_NoPUe->Integral());
    pthist_1000_700_30mm_NoPUe->Scale(1.0/pthist_1000_700_30mm_NoPUe->Integral());
    pthist_1000_700_10mm_NoPUe->Scale(1.0/pthist_1000_700_10mm_NoPUe->Integral());
    pthist_1000_700_3mm_NoPUe->Scale(1.0/pthist_1000_700_3mm_NoPUe->Integral());
    pthist_dyjets_NoPUe->Scale(1.0/pthist_dyjets_NoPUe->Integral());
    pthist_ttbar_NoPUe->Scale(1.0/pthist_ttbar_NoPUe->Integral());

    pthist_dyjets_NoPUe->Draw("hist");
    pthist_ttbar_NoPUe->Draw("SAME,hist");
    pthist_1000_700_100mm_NoPUe->Draw("SAME,hist");
    pthist_1000_700_30mm_NoPUe->Draw("SAME,hist");
    pthist_1000_700_10mm_NoPUe->Draw("SAME,hist");
    pthist_1000_700_3mm_NoPUe->Draw("SAME,hist");
    legpt->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");
    std::string namepte = std::string("pt") + tag + std::string("electron.png");
    std::string nameptepdf = std::string("pt") + tag + std::string("electron.pdf");
    can_pte->SaveAs(namepte.c_str());
    can_pte->SaveAs(nameptepdf.c_str());

 


    TCanvas *can_dthiste = new TCanvas("can_dthiste", "can_dthiste");
    can_dthiste->cd();
    dthist_1000_700_3mm_NoPUe->Draw();
    dthist_1000_700_10mm_NoPUe->Draw("SAME");
    dthist_1000_700_30mm_NoPUe->Draw("SAME");
    dthist_1000_700_100mm_NoPUe->Draw("SAME");
    legdt->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");


    std::string namedte = std::string("dt") + tag + std::string("electron.png");
    std::string namedtepdf = std::string("dt") + tag + std::string("electron.pdf");
    can_dthiste->SaveAs(namedte.c_str());
    can_dthiste->SaveAs(namedtepdf.c_str());

    TCanvas *can_dlhiste = new TCanvas("can_dlhiste", "can_dlhiste");
    can_dlhiste->cd();
    dlhist_1000_700_3mm_NoPUe->Draw();
    dlhist_1000_700_10mm_NoPUe->Draw("SAME");
    dlhist_1000_700_30mm_NoPUe->Draw("SAME");
    dlhist_1000_700_100mm_NoPUe->Draw("SAME");
    leg->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    std::string namedle = std::string("dl") + tag + std::string("electron.png");
    std::string namedlepdf = std::string("dl") + tag + std::string("electron.pdf");
    can_dlhiste->SaveAs(namedle.c_str());
    can_dlhiste->SaveAs(namedlepdf.c_str());

    std::cout << "1000 700 100 " << tres << " " << getResolution(massN_1000_700_100mm_NoPUe)/7.0 << " " << f100e->GetParameter(2)/7.0 << " " << getResolution(massN_1000_700_100mm_NoPUm)/7.0 << " " << f100m->GetParameter(2)/7.0 << std::endl;

    std::cout << "1000 700 30 " << tres << " " << getResolution(massN_1000_700_30mm_NoPUe)/7.0 << " " << f30e->GetParameter(2)/7.0 << " " << getResolution(massN_1000_700_30mm_NoPUm)/7.0 << " " << f30m->GetParameter(2)/7.0 << std::endl;
    std::cout << "1000 700 10 " << tres << " " << getResolution(massN_1000_700_10mm_NoPUe)/7.0 << " " << f10e->GetParameter(2)/7.0 << " " << getResolution(massN_1000_700_10mm_NoPUm)/7.0 << " " << f10m->GetParameter(2)/7.0 << std::endl;
    std::cout << "1000 700 3 " << tres << " " << getResolution(massN_1000_700_3mm_NoPUe)/7.0 << " " << f3e->GetParameter(2)/7.0 << " " << getResolution(massN_1000_700_3mm_NoPUm)/7.0 << " " << f3m->GetParameter(2)/7.0 << std::endl;

}
