#include "tdrstyle.C"
#include "TH1F.h"
#include "TLatex.h" 



void run(std::string tag) { 

    setTDRStyle();

    std::vector<float> sigma100, res100m;
    std::vector<float> sigma30, res30m;
    std::vector<float> sigma10, res10m;
    std::vector<float> sigma3, res3m;
    std::vector<float> res100e;
    std::vector<float> res30e;
    std::vector<float> res10e;
    std::vector<float> res3e;
    std::vector<float> ctau30ps;
    std::vector<float> ctau50ps;
    std::vector<float> ctau70ps;
    std::vector<float> ctau90ps;
    std::vector<float> res30pse;
    std::vector<float> res50pse;
    std::vector<float> res70pse;
    std::vector<float> res90pse;
    std::vector<float> res30psm;
    std::vector<float> res50psm;
    std::vector<float> res70psm;
    std::vector<float> res90psm;

    std::fstream a("numbersMass.txt");
    while(!a.eof()) {
        float m1, m2, ctau, sigma, res1e, res2e, res1m, res2m;
        a >> m1 >> m2 >> ctau >> sigma >> res1e >> res2e >> res1m >> res2m;
        if(a.eof()) break;
        if(ctau == 100) {
            sigma100.push_back(sigma);
            res100m.push_back(res1m);
            res100e.push_back(res1e);
        }
        if(ctau == 30) {
            sigma30.push_back(sigma);
            res30m.push_back(res1m);
            res30e.push_back(res1e);
        }
        if(ctau == 10) {
            sigma10.push_back(sigma);
            res10m.push_back(res1m);
            res10e.push_back(res1e);
        }
        if(ctau == 3) {
            sigma3.push_back(sigma);
            res3m.push_back(res1m);
            res3e.push_back(res1e);
        }
        if(sigma == 30) {
            ctau30ps.push_back(ctau);
            res30psm.push_back(res1m);
            res30pse.push_back(res1e);
        }
        if(sigma == 50) {
            ctau50ps.push_back(ctau);
            res50psm.push_back(res1m);
            res50pse.push_back(res1e);
        }
        if(sigma == 70) {
            ctau70ps.push_back(ctau);
            res70psm.push_back(res1m);
            res70pse.push_back(res1e);
        }
        if(sigma == 90) {
            ctau90ps.push_back(ctau);
            res90psm.push_back(res1m);
            res90pse.push_back(res1e);
        }
    }
    std::cout << "Building" << std::endl;

    TH1F *f = new TH1F("dummy", "", 1, 9, 300);
    f->SetMaximum(200);
    f->SetMinimum(9);
    f->GetYaxis()->SetRangeUser(1, 200);
    f->GetXaxis()->SetRangeUser(9, 300);
    f->GetXaxis()->SetTitle("MTD resolution #sigma_{t} [ps]");
    f->GetXaxis()->SetTitleSize(0.035);
    f->GetXaxis()->CenterTitle();
    f->GetYaxis()->SetTitle("1 #sigma Mass Resolution [%]");
    f->GetXaxis()->SetTitleOffset(1.5);
    f->GetYaxis()->CenterTitle();
    f->GetYaxis()->SetTitleSize(0.035);
    f->GetYaxis()->SetTitleOffset(1.5);

    TH1F *f2 = new TH1F("dummy2", "", 1, 0, 110);
    f2->SetMaximum(200);
    f2->SetMinimum(9);
    f2->GetYaxis()->SetRangeUser(9, 200);
    f2->GetXaxis()->SetRangeUser(0, 110);
    f2->GetXaxis()->SetTitle("c#tau [mm]");
    f2->GetXaxis()->SetTitleSize(0.035);
    f2->GetXaxis()->CenterTitle();
    f2->GetYaxis()->SetTitle("Mass Resolution [%]");
    f2->GetXaxis()->SetTitleOffset(1.5);
    f2->GetYaxis()->CenterTitle();
    f2->GetYaxis()->SetTitleSize(0.035);
    f2->GetYaxis()->SetTitleOffset(1.5);
 
    float *a_sigma100 = new float[sigma100.size()];
    float *a_res100e = new float[res100e.size()];
    float *a_res100m = new float[res100m.size()];
    for(size_t i = 0; i < sigma100.size(); i++) {
        a_sigma100[i] = sigma100[i];
        a_res100e[i] = res100e[i];
        a_res100m[i] = res100m[i];
    }
    float *a_sigma30 = new float[sigma30.size()];
    float *a_res30e = new float[res30e.size()];
    float *a_res30m = new float[res30m.size()];
    for(size_t i = 0; i < sigma30.size(); i++) {
        a_sigma30[i] = sigma30[i];
        a_res30e[i] = res30e[i];
        a_res30m[i] = res30m[i];
    }
    float *a_sigma10 = new float[sigma10.size()];
    float *a_res10e = new float[res10e.size()];
    float *a_res10m = new float[res10m.size()];
    for(size_t i = 0; i < sigma10.size(); i++) {
        a_sigma10[i] = sigma10[i];
        a_res10e[i] = res10e[i];
        a_res10m[i] = res10m[i];
    }
    float *a_sigma3 = new float[sigma3.size()];
    float *a_res3e = new float[res3e.size()];
    float *a_res3m = new float[res3m.size()];
    for(size_t i = 0; i < sigma3.size(); i++) {
        a_sigma3[i] = sigma3[i];
        a_res3e[i] = res3e[i];
        a_res3m[i] = res3m[i];
    } 

    float *a_ctau30ps = new float[ctau30ps.size()];
    float *a_res30pse = new float[res30pse.size()];
    float *a_res30psm = new float[res30psm.size()];
    for(size_t i = 0; i < ctau30ps.size(); i++) {
        a_ctau30ps[i] = ctau30ps[i];
        a_res30pse[i] = res30pse[i];
        a_res30psm[i] = res30psm[i];
    } 
  
    float *a_ctau50ps = new float[ctau50ps.size()];
    float *a_res50pse = new float[res50pse.size()];
    float *a_res50psm = new float[res50psm.size()];
    for(size_t i = 0; i < ctau50ps.size(); i++) {
        a_ctau50ps[i] = ctau50ps[i];
        a_res50pse[i] = res50pse[i];
        a_res50psm[i] = res50psm[i];
    } 
 
    float *a_ctau70ps = new float[ctau70ps.size()];
    float *a_res70pse = new float[res70pse.size()];
    float *a_res70psm = new float[res70psm.size()];
    for(size_t i = 0; i < ctau70ps.size(); i++) {
        a_ctau70ps[i] = ctau70ps[i];
        a_res70pse[i] = res70pse[i];
        a_res70psm[i] = res70psm[i];
    } 
 
 
    float *a_ctau90ps = new float[ctau90ps.size()];
    float *a_res90pse = new float[res90pse.size()];
    float *a_res90psm = new float[res90psm.size()];
    for(size_t i = 0; i < ctau90ps.size(); i++) {
        a_ctau90ps[i] = ctau90ps[i];
        a_res90pse[i] = res90pse[i];
        a_res90psm[i] = res90psm[i];
    } 
 
    TGraph ctau100e(sigma100.size(), a_sigma100, a_res100e);
    TGraph ctau30e(sigma30.size(), a_sigma30, a_res30e);
    TGraph ctau10e(sigma10.size(), a_sigma10, a_res10e);
    TGraph ctau3e(sigma3.size(), a_sigma3, a_res3e);
    TGraph ctau100m(sigma100.size(), a_sigma100, a_res100m);
    TGraph ctau30m(sigma30.size(), a_sigma30, a_res30m);
    TGraph ctau10m(sigma10.size(), a_sigma10, a_res10m);
    TGraph ctau3m(sigma3.size(), a_sigma3, a_res3m);
    TGraph sigma30pse(ctau30ps.size(), a_ctau30ps, a_res30pse);
    TGraph sigma50pse(ctau50ps.size(), a_ctau50ps, a_res50pse);
    TGraph sigma70pse(ctau70ps.size(), a_ctau70ps, a_res70pse);
    TGraph sigma90pse(ctau90ps.size(), a_ctau90ps, a_res90pse);
    TGraph sigma30psm(ctau30ps.size(), a_ctau30ps, a_res30psm);
    TGraph sigma50psm(ctau50ps.size(), a_ctau50ps, a_res50psm);
    TGraph sigma70psm(ctau70ps.size(), a_ctau70ps, a_res70psm);
    TGraph sigma90psm(ctau90ps.size(), a_ctau90ps, a_res90psm);

    ctau100e.SetMarkerColor(kBlue);
    ctau30e.SetMarkerColor(kRed);
    ctau10e.SetMarkerColor(kGreen);
    ctau3e.SetMarkerColor(kMagenta);
    ctau100m.SetMarkerColor(kBlue);
    ctau30m.SetMarkerColor(kRed);
    ctau10m.SetMarkerColor(kGreen);
    ctau3m.SetMarkerColor(kMagenta);
    

    sigma30pse.SetMarkerColor(kBlue);
    sigma50pse.SetMarkerColor(kRed);
    sigma70pse.SetMarkerColor(kGreen);
    sigma90pse.SetMarkerColor(kMagenta);

    sigma30psm.SetMarkerColor(kBlue);
    sigma50psm.SetMarkerColor(kRed);
    sigma70psm.SetMarkerColor(kGreen);
    sigma90psm.SetMarkerColor(kMagenta);

    sigma30pse.SetLineColor(kBlue);
    sigma50pse.SetLineColor(kRed);
    sigma70pse.SetLineColor(kGreen);
    sigma90pse.SetLineColor(kMagenta);

    sigma30psm.SetLineColor(kBlue);
    sigma50psm.SetLineColor(kRed);
    sigma70psm.SetLineColor(kGreen);
    sigma90psm.SetLineColor(kMagenta);

    ctau100e.SetMarkerStyle(29);
    ctau30e.SetMarkerStyle(22);
    ctau10e.SetMarkerStyle(33);
    ctau3e.SetMarkerStyle(23);
    ctau100e.SetMarkerSize(1.3);
    ctau30e.SetMarkerSize(1.3);
    ctau10e.SetMarkerSize(1.3);
    ctau3e.SetMarkerSize(1.3);
    sigma30pse.SetMarkerStyle(29);
    sigma50pse.SetMarkerStyle(22);
    sigma70pse.SetMarkerStyle(33);
    sigma90pse.SetMarkerStyle(23);
    sigma30pse.SetMarkerSize(1.3);
    sigma50pse.SetMarkerSize(1.3);
    sigma70pse.SetMarkerSize(1.3);
    sigma90pse.SetMarkerSize(1.3);


    ctau100m.SetMarkerStyle(29);
    ctau30m.SetMarkerStyle(22);
    ctau10m.SetMarkerStyle(33);
    ctau3m.SetMarkerStyle(23);
    ctau100m.SetMarkerSize(1.3);
    ctau30m.SetMarkerSize(1.3);
    ctau10m.SetMarkerSize(1.3);
    ctau3m.SetMarkerSize(1.3);
    sigma30psm.SetMarkerStyle(29);
    sigma50psm.SetMarkerStyle(22);
    sigma70psm.SetMarkerStyle(33);
    sigma90psm.SetMarkerStyle(23);
    sigma30psm.SetMarkerSize(1.3);
    sigma50psm.SetMarkerSize(1.3);
    sigma70psm.SetMarkerSize(1.3);
    sigma90psm.SetMarkerSize(1.3);

    TLatex latex;
    latex.SetNDC();
    latex.SetTextAngle(0);
    latex.SetTextColor(kBlack);
    latex.SetTextFont(42);
    latex.SetTextAlign(31);
    latex.SetTextSize(0.03);
    TLegend *leg =  new TLegend(0.2, 0.2, 0.4, 0.4);
    leg->SetFillColor(kWhite);
    leg->SetTextFont(42);
    leg->SetTextSize(0.04);
    leg->SetLineWidth(0);
    leg->SetBorderSize(0);
    leg->AddEntry(&ctau100e, "c#tau = 100mm", "P");
    leg->AddEntry(&ctau30e, "c#tau = 30mm", "P");
    leg->AddEntry(&ctau10e, "c#tau = 10mm", "P");
    leg->AddEntry(&ctau3e, "c#tau = 3mm", "P");

    TLegend *legsigma =  new TLegend(0.2, 0.2, 0.4, 0.4);
    legsigma->SetFillColor(kWhite);
    legsigma->SetTextFont(42);
    legsigma->SetTextSize(0.04);
    legsigma->SetLineWidth(0);
    legsigma->SetBorderSize(0);
    legsigma->AddEntry(&sigma30pse, "#sigma = 30 ps", "P");
    legsigma->AddEntry(&sigma50pse, "#sigma = 50 ps", "P");
    legsigma->AddEntry(&sigma70pse, "#sigma = 70 ps", "P");
    //legsigma->AddEntry(&sigma90pse, "#sigma = 90 ps", "P");


    TCanvas *cane = new TCanvas("cane", "cane");
    cane->cd();
    cane->SetGrid();
    cane->SetLogx();
    cane->SetLogy();
    f->Draw();
    ctau100e.Draw("P");
    ctau30e.Draw("P");
    ctau10e.Draw("P");
    ctau3e.Draw("P");
    leg->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    std::string namee = std::string("res_sigma") + std::string("electron.png");
    std::string nameepdf = std::string("res_sigma") + std::string("electron.pdf");
    cane->SaveAs(namee.c_str());
    cane->SaveAs(nameepdf.c_str());


    TCanvas *canm = new TCanvas("canm", "canm");
    canm->cd();
    canm->SetGrid();
    canm->SetLogx();
    canm->SetLogy();
    f->Draw();
    ctau100m.Draw("P");
    ctau30m.Draw("P");
    ctau10m.Draw("P");
    ctau3m.Draw("P");
    leg->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    std::string namem = std::string("res_sigma") + std::string("muon.png");
    std::string namempdf = std::string("res_sigma") + std::string("muon.pdf");
    canm->SaveAs(namem.c_str());
    canm->SaveAs(namempdf.c_str());


    TCanvas *canesigma = new TCanvas("canesigma", "canesigma");
    canesigma->cd();
    canesigma->SetGrid();
    canesigma->SetLogy();
    f2->Draw();
    sigma30pse.Draw("PL");
    sigma50pse.Draw("PL");
    sigma70pse.Draw("PL");
    //sigma90psm.Draw("PL");
    legsigma->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");

    std::string nameesigma = std::string("res_ps") + std::string("electron.png");
    std::string nameepdfsigma = std::string("res_ps") + std::string("electron.pdf");
    canesigma->SaveAs(nameesigma.c_str());
    canesigma->SaveAs(nameepdfsigma.c_str());

    TCanvas *canmsigma = new TCanvas("canmsigma", "canmsigma");
    canmsigma->cd();
    canmsigma->SetGrid();
    canmsigma->SetLogy();
    f2->Draw();
    sigma30psm.Draw("PL");
    sigma50psm.Draw("PL");
    sigma70psm.Draw("PL");
    //sigma90psm.Draw("PL");
    legsigma->Draw();
    latex.DrawLatex(0.43, 0.93, "#bf{CMS} #it{Delphes Simulation}");
    latex.DrawLatex(0.85, 0.85,  "#tilde{t} #rightarrow #chi_{1}^{0} + t, #chi_{1}^{0} #rightarrow Z + #tilde{G}, Z #rightarrow e^{+}e^{-}");
    latex.DrawLatex(0.85, 0.80, "M(#tilde{t}) = 1000 GeV, M(#chi_{1}^{0}) = 700 GeV, M(#tilde{G}) = 1 GeV");
    std::string namemsigma = std::string("res_ps") + std::string("muon.png");
    std::string namempdfsigma = std::string("res_ps") + std::string("muon.pdf");
    canmsigma->SaveAs(namemsigma.c_str());
    canmsigma->SaveAs(namempdfsigma.c_str());


}
