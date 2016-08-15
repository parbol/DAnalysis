#ifndef TTZANALYSIS_ANALYSIS_INTERFACE_BASICANALYZER_H_
#define TTZANALYSIS_ANALYSIS_INTERFACE_BASICANALYZER_H_
/** \class d_ana::basicAnalyzer
 *
 * user-friendly parallel delphes analysis class
 *
 * \original author: Jan Kieseler
 *
 * more docu
 *
 */


#include "../interface/fileForker.h"
#include "TString.h"
#include <vector>


/**
 * quick and dirty generic analysis interface
 */
namespace d_ana{
class basicAnalyzer : public fileForker{
public:
	basicAnalyzer();


	void readFileList(const std::string& );





	void setDataSetDirectory(const TString& dir){datasetdirectory_=dir;}

	void setOutDir(const TString& dir);
	TString getOutDir(){return outdir_;}

	TString getOutPath(){return outdir_+getOutFileName();}


	//setters
	void setLumi(double Lumi){lumi_=Lumi;}
	void setSyst(TString syst){syst_=syst;}

	void setFilePostfixReplace(const TString& file,const TString& pf,bool clear=false);
	void setFilePostfixReplace(const std::vector<TString>& files,const std::vector<TString>& pf);

	void setTestMode(bool test){testmode_=test;}

	//getters
	TString getSyst(){return syst_;}


	virtual TString getOutFileName(){
		if(syst_.Length()){
			//   std::cout<<"Hallo   "<<getOutputFileName()<<std::endl;
			return  (TString)getOutputFileName()+"_"+syst_;}
		else{
			//    std::cout<<"Hallo2   "<<getOutputFileName()<<std::endl;
			return getOutputFileName();}
	}

	void start(){
		runParallels(5);
	}


protected:

	/**
	 * Implements the event loop
	 */
	virtual void analyze(size_t )=0;
	/**
	 * for child processes
	 * reports the Status (% of events already processed) to the main program
	 */
	void reportStatus(const Long64_t& entry,const Long64_t& nEntries);

	const TString& getSampleFile()const{return inputfile_;}
	TString getSamplePath()const{return datasetdirectory_+"/"+inputfile_;}
	const TString& getLegendName()const{return legendname_;}
	const int& getColor()const{return col_;}
	const double& getNorm()const{return norm_;}
	const size_t& getLegendOrder()const{return legorder_;}
	const bool& getIsSignal()const{return signal_;}
	void setIsSignal(bool set){signal_=set;}

	bool isTestMode()const{return testmode_;}

private:

	void process();



	fileForker::fileforker_status  writeOutput();
	fileForker::fileforker_status  runParallels(int displaystatusinterval);

	bool createOutFile()const;

	TString replaceExtension(TString filename );


	std::vector<TString> infiles_,legentries_;
	std::vector<int> colz_;
	std::vector<double> norms_;
	std::vector<size_t> legords_;
	std::vector<bool> issignal_;
	std::vector<TString> extraopts_;

	///child variables
	TString inputfile_;
	TString legendname_;
	int col_;
	double norm_;
	size_t legorder_;
	bool signal_;

	TString datasetdirectory_;

	TString syst_;
	double lumi_;
	std::vector<TString> fwithfix_,ftorepl_;
	int freplaced_;
	bool testmode_;

	bool isMC_;

	TString datalegend_;
	TString outdir_;
};



}
#endif /* TTZANALYSIS_ANALYSIS_INTERFACE_BASICANALYZER_H_ */