#include "tdrstyle.C"
#include "TH1F.h"
#include "TLatex.h" 



void run(std::string tag) { 

    setTDRStyle();

    std::vector<float> sigma100, eff100m;
    std::vector<float> sigma30, eff30m;
    std::vector<float> sigma10, eff10m;
    std::vector<float> sigma3, eff3m;
    std::vector<float> eff100e;
    std::vector<float> eff30e;
    std::vector<float> eff10e;
    std::vector<float> eff3e;

    std::vector<float> ctau30ps;
    std::vector<float> ctau50ps;
    std::vector<float> ctau70ps;
    std::vector<float> ctau90ps;
    
    std::vector<float> eff30psm;
    std::vector<float> eff50psm;
    std::vector<float> eff70psm;
    std::vector<float> eff90psm;
    
    std::vector<float> eff30pse;
    std::vector<float> eff50pse;
    std::vector<float> eff70pse;
    std::vector<float> eff90pse;


    std::fstream a("numbersEff.txt");
    while(!a.eof()) {
        float m1, m2, ctau, sigma, numm, denm, effm, nume, dene, effe;
        a >> m1 >> m2 >> ctau >> sigma >> numm >> denm >> effm >> nume >> dene >> effe;
        if(a.eof()) break;
        if(ctau == 100) {
            sigma100.push_back(sigma);
            eff100m.push_back(effm);
            eff100e.push_back(effe);
        }
        if(ctau == 30) {
            sigma30.push_back(sigma);
            eff30m.push_back(effm);
            eff30e.push_back(effe);
        }
        if(ctau == 10) {
            sigma10.push_back(sigma);
            eff10m.push_back(effm);
            eff10e.push_back(effe);
        }
        if(ctau == 3) {
            sigma3.push_back(ctau);
            eff3m.push_back(effm);
            eff3e.push_back(effe);
        }
        if(sigma == 30) {
            if(ctau != 0 && ctau != 1) { 
            ctau30ps.push_back(ctau);
            eff30psm.push_back(effm);
            eff30pse.push_back(effe);
            }
        }
        if(sigma == 50) {
            if(ctau != 0 && ctau != 1) { 
            ctau50ps.push_back(ctau);
            eff50psm.push_back(effm);
            eff50pse.push_back(effe);
            }
        }
        if(sigma == 70) {
            if(ctau != 0 && ctau != 1) { 
            ctau70ps.push_back(ctau);
            eff70psm.push_back(effm);
            eff70pse.push_back(effe);
            }
        }
        if(sigma == 90) {
            if(ctau != 0 && ctau != 1) { 
            ctau90ps.push_back(ctau);
            eff90psm.push_back(effm);
            eff90pse.push_back(effe);
            }
        }
    }
    std::cout << "Building" << std::endl;

    TH1F *f = new TH1F("dummy", "", 1, 9, 300);
    f->SetMaximum(2);
    f->SetMinimum(0.0001);
    f->GetYaxis()->SetRangeUser(0.0001, 2);
    f->GetXaxis()->SetRangeUser(5, 300);
    f->GetXaxis()->SetTitle("MTD resolution #sigma_{t} [ps]");
    f->GetXaxis()->SetTitleSize(0.035);
    f->GetXaxis()->CenterTitle();
    f->GetYaxis()->SetTitle("Efficiency secondary vertex selection");
    f->GetXaxis()->SetTitleOffset(1.5);
    f->GetYaxis()->CenterTitle();
    f->GetYaxis()->SetTitleSize(0.035);
    f->GetYaxis()->SetTitleOffset(1.5);
    

    TH1F *f2 = new TH1F("dummy2", "", 1, 0, 110);
    f2->SetMaximum(10);
    f2->SetMinimum(0.0001);
    f2->GetYaxis()->SetRangeUser(0.0001, 10);
    f2->GetXaxis()->SetRangeUser(0, 110);
    f2->GetXaxis()->SetTitle("c#tau [mm]");
    f2->GetXaxis()->SetTitleSize(0.035);
    f2->GetXaxis()->CenterTitle();
    f2->GetYaxis()->SetTitle("Efficiency secondary vertex selection");
    f2->GetXaxis()->SetTitleOffset(1.5);
    f2->GetYaxis()->CenterTitle();
    f2->GetYaxis()->SetTitleSize(0.035);
    f2->GetYaxis()->SetTitleOffset(1.5);
    

 
    float *a_sigma100 = new float[sigma100.size()];
    float *a_eff100m = new float[eff100m.size()];
    float *a_eff100e = new float[eff100e.size()];
    for(size_t i = 0; i < sigma100.size(); i++) {
        a_sigma100[i] = sigma100[i];
        a_eff100m[i] = eff100m[i];
        a_eff100e[i] = eff100e[i];
    }
    float *a_sigma30 = new float[sigma30.size()];
    float *a_eff30m = new float[eff30m.size()];
    float *a_eff30e = new float[eff30e.size()];
    for(size_t i = 0; i < sigma30.size(); i++) {
        a_sigma30[i] = sigma30[i];
        a_eff30m[i] = eff30m[i];
        a_eff30e[i] = eff30e[i];
    }
    float *a_sigma10 = new float[sigma10.size()];
    float *a_eff10m = new float[eff10m.size()];
    float *a_eff10e = new float[eff10e.size()];
    for(size_t i = 0; i < sigma10.size(); i++) {
        a_sigma10[i] = sigma10[i];
        a_eff10m[i] = eff10m[i];
        a_eff10e[i] = eff10e[i];
    }
    float *a_sigma3 = new float[sigma3.size()];
    float *a_eff3m = new float[eff3m.size()];
    float *a_eff3e = new float[eff3e.size()];
    for(size_t i = 0; i < sigma3.size(); i++) {
        a_sigma3[i] = sigma3[i];
        a_eff3m[i] = eff3m[i];
        a_eff3e[i] = eff3e[i];
    } 

    float *a_ctau30ps = new float[ctau30ps.size()];
    float *a_eff30psm = new float[eff30psm.size()];
    float *a_eff30pse = new float[eff30pse.size()];
    for(size_t i = 0; i < ctau30ps.size(); i++) {
        a_ctau30ps[i] = ctau30ps[i];
        a_eff30psm[i] = eff30psm[i];
        a_eff30pse[i] = eff30pse[i];
    }
    
    float *a_ctau50ps = new float[ctau30ps.size()];
    float *a_eff50psm = new float[eff30psm.size()];
    float *a_eff50pse = new float[eff30pse.size()];
    for(size_t i = 0; i < ctau50ps.size(); i++) {
        a_ctau50ps[i] = ctau50ps[i];
        a_eff50psm[i] = eff50psm[i];
        a_eff50pse[i] = eff50pse[i];
    }
    
    float *a_ctau70ps = new float[ctau30ps.size()];
    float *a_eff70psm = new float[eff30psm.size()];
    float *a_eff70pse = new float[eff30pse.size()];
    for(size_t i = 0; i < ctau70ps.size(); i++) {
        a_ctau70ps[i] = ctau70ps[i];
        a_eff70psm[i] = eff70psm[i];
        a_eff70pse[i] = eff70pse[i];
    }
    
    float *a_ctau90ps = new float[ctau90ps.size()];
    float *a_eff90psm = new float[eff90psm.size()];
    float *a_eff90pse = new float[eff90pse.size()];
    for(size_t i = 0; i < ctau90ps.size(); i++) {
        a_ctau90ps[i] = ctau90ps[i];
        a_eff90psm[i] = eff90psm[i];
        a_eff90pse[i] = eff90pse[i];
    }
    

    TGraph ctau100m(sigma100.size(), a_sigma100, a_eff100m);
    TGraph ctau30m(sigma30.size(), a_sigma30, a_eff30m);
    TGraph ctau10m(sigma10.size(), a_sigma10, a_eff10m);
    TGraph ctau3m(sigma3.size(), a_sigma3, a_eff3m);
    
    TGraph sigma30psm(ctau30ps.size(), a_ctau30ps, a_eff30psm);
    TGraph sigma50psm(ctau50ps.size(), a_ctau50ps, a_eff50psm);
    TGraph sigma70psm(ctau70ps.size(), a_ctau70ps, a_eff70psm);
    TGraph sigma90psm(ctau90ps.size(), a_ctau90ps, a_eff90psm);

    ctau100m.SetMarkerColor(kBlue);
    ctau30m.SetMarkerColor(kRed);
    ctau10m.SetMarkerColor(kGreen);
    ctau3m.SetMarkerColor(kMagenta);
    
    ctau100m.SetMarkerStyle(29);
    ctau30m.SetMarkerStyle(22);
    ctau10m.SetMarkerStyle(33);
    ctau3m.SetMarkerStyle(23);
    
    ctau100m.SetMarkerSize(1.3);
    ctau30m.SetMarkerSize(1.3);
    ctau10m.SetMarkerSize(1.3);
    ctau3m.SetMarkerSize(1.3);

    sigma30psm.SetMarkerColor(kBlue);
    sigma50psm.SetMarkerColor(kRed);
    sigma70psm.SetMarkerColor(kGreen);
    sigma90psm.SetMarkerColor(kMagenta);
    
    sigma30psm.SetMarkerStyle(29);
    sigma50psm.SetMarkerStyle(22);
    sigma70psm.SetMarkerStyle(33);
    sigma90psm.SetMarkerStyle(23);
    
    sigma30psm.SetMarkerSize(1.3);
    sigma50psm.SetMarkerSize(1.3);
    sigma70psm.SetMarkerSize(1.3);
    sigma90psm.SetMarkerSize(1.3);
    
    sigma30psm.SetLineColor(kBlue);
    sigma50psm.SetLineColor(kRed);
    sigma70psm.SetLineColor(kGreen);
    sigma90psm.SetLineColor(kMagenta);

 
    TGraph ctau100e(sigma100.size(), a_sigma100, a_eff100e);
    TGraph ctau30e(sigma30.size(), a_sigma30, a_eff30e);
    TGraph ctau10e(sigma10.size(), a_sigma10, a_eff10e);
    TGraph ctau3e(sigma3.size(), a_sigma3, a_eff3e);

    TGraph sigma30pse(ctau30ps.size(), a_ctau30ps, a_eff30pse);
    TGraph sigma50pse(ctau50ps.size(), a_ctau50ps, a_eff50pse);
    TGraph sigma70pse(ctau70ps.size(), a_ctau70ps, a_eff70pse);
    TGraph sigma90pse(ctau90ps.size(), a_ctau90ps, a_eff90pse);
    
    ctau100e.SetMarkerColor(kBlue);
    ctau30e.SetMarkerColor(kRed);
    ctau10e.SetMarkerColor(kGreen);
    ctau3e.SetMarkerColor(kMagenta);
    
    ctau100e.SetMarkerStyle(29);
    ctau30e.SetMarkerStyle(22);
    ctau10e.SetMarkerStyle(33);
    ctau3e.SetMarkerStyle(23);
    
    ctau100e.SetMarkerSize(1.3);
    ctau30e.SetMarkerSize(1.3);
    ctau10e.SetMarkerSize(1.3);
    ctau3e.SetMarkerSize(1.3);

    sigma30pse.SetMarkerColor(kBlue);
    sigma50pse.SetMarkerColor(kRed);
    sigma70pse.SetMarkerColor(kGreen);
    sigma90pse.SetMarkerColor(kMagenta);
    
    sigma30pse.SetLineColor(kBlue);
    sigma50pse.SetLineColor(kRed);
    sigma70pse.SetLineColor(kGreen);
    sigma90pse.SetLineColor(kMagenta);
    
    sigma30pse.SetMarkerStyle(29);
    sigma50pse.SetMarkerStyle(22);
    sigma70pse.SetMarkerStyle(33);
    sigma90pse.SetMarkerStyle(23);
    
    sigma30pse.SetMarkerSize(1.3);
    sigma50pse.SetMarkerSize(1.3);
    sigma70pse.SetMarkerSize(1.3);
    sigma90pse.SetMarkerSize(1.3);

    TLatex latex2;
    latex2.SetNDC();
    latex2.SetTextAngle(0);
    latex2.SetTextColor(kBlack);
    latex2.SetTextFont(42);
    latex2.SetTextAlign(31);
    latex2.SetTextSize(0.03);
    

 
    TLatex latex;
    latex.SetNDC();
    latex.SetTextAngle(0);
    latex.SetTextColor(kBlack);
    latex.SetTextFont(42);
    latex.SetTextAlign(31);
    latex.SetTextSize(0.03);
    TLegend *leg =  new TLegend(0.15, 0.2, 0.35, 0.4);
    leg->SetFillColor(kWhite);
    leg->SetTextFont(42);
    leg->SetTextSize(0.03);
    leg->SetLineWidth(0);
    leg->SetBorderSize(0);
    leg->AddEntry(&ctau100e, "c#tau = 100mm", "P");
    leg->AddEntry(&ctau30e, "c#tau = 30mm", "P");
    leg->AddEntry(&ctau10e, "c#tau = 10mm", "P");
    leg->AddEntry(&ctau3e, "c#tau = 3mm", "P");

    TLegend *legsigma =  new TLegend(0.45, 0.25, 0.75, 0.55);
    legsigma->SetFillColor(kWhite);
    legsigma->SetTextFont(42);
    legsigma->SetTextSize(0.035);
    legsigma->SetLineWidth(0);
    legsigma->SetBorderSize(0);
    legsigma->AddEntry(&sigma30pse, "#sigma = 30 ps", "P");
    legsigma->AddEntry(&sigma50pse, "#sigma = 50 ps", "P");
    legsigma->AddEntry(&sigma70pse, "#sigma = 70 ps", "P");
    //legsigma->AddEntry(&sigma90pse, "#sigma = 90 ps", "P");

    TCanvas *canm = new TCanvas("canm", "canm");
    canm->cd();
    canm->SetLogy();
    canm->SetLogx();
    canm->SetGrid();
    f->Draw();
    ctau100m.Draw("P");
    ctau30m.Draw("P");
    ctau10m.Draw("P");
    ctau3m.Draw("P");
    leg->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");

    std::string namem = std::string("eff_mm_sigma") + std::string(".png");
    std::string namempdf = std::string("eff_mm_sigma") + std::string(".pdf");
    canm->SaveAs(namem.c_str());
    canm->SaveAs(namempdf.c_str());

    TCanvas *cane = new TCanvas("cane", "cane");
    cane->cd();
    cane->SetLogy();
    cane->SetLogx();
    cane->SetGrid();
    f->Draw();
    ctau100e.Draw("P");
    ctau30e.Draw("P");
    ctau10e.Draw("P");
    ctau3e.Draw("P");
    leg->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    std::string namee = std::string("eff_ee_sigma") + std::string(".png");
    std::string nameepdf = std::string("eff_ee_sigma") + std::string(".pdf");
    canm->SaveAs(namee.c_str());
    canm->SaveAs(nameepdf.c_str());

    TCanvas *canmps = new TCanvas("canmps", "canmps");
    canmps->cd();
    canmps->SetLogy();
    //canmps->SetLogx();
    canmps->SetGrid();
    f2->Draw();
    sigma30psm.Draw("PL");
    sigma50psm.Draw("PL");
    sigma70psm.Draw("PL");
    //sigma90psm.Draw("PL");
    legsigma->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");
    std::string namemps = std::string("eff_mm_ps") + std::string(".png");
    std::string namempdfps = std::string("eff_mm_ps") + std::string(".pdf");
    canmps->SaveAs(namemps.c_str());
    canmps->SaveAs(namempdfps.c_str());

    TCanvas *caneps = new TCanvas("caneps", "caneps");
    caneps->cd();
    caneps->SetLogy();
    //caneps->SetLogx();
    caneps->SetGrid();
    f2->Draw();
    sigma30pse.Draw("PL");
    sigma50pse.Draw("PL");
    sigma70pse.Draw("PL");
    //sigma90pse.Draw("PL");
    legsigma->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");
    std::string nameeps = std::string("eff_ee_ps") + std::string(".png");
    std::string nameepdfps = std::string("eff_ee_ps") + std::string(".pdf");
    caneps->SaveAs(nameeps.c_str());
    caneps->SaveAs(nameepdfps.c_str());


}
