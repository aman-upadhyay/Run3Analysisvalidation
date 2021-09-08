// load ttrees test signal and test background 
// assign variable values to reader
// loop evaluate compare
// make list of signal pass signal fail background pass background fail
//calculate significance and signal efficiancy for RCO

#include <iostream> 
#include <cmath>
#include <iomanip>
using namespace std; 
void test(const char *fname="dataset/weights/O2_Cuts.weights.xml"){   //load this function in root

	double h, sign, eff;    //variable for sorting response value, should be double
	float x[15];   // array to store value from application file
	double s_pass=0;  // # of true positives
	double b_pass=0;  // # of false positives
	double s_fail=0;  // # of false negatives
	double b_fail=0;  // # of true negatives
	

	
	TMVA::Reader *reader = new TMVA::Reader("!Color:!Silent");  

  	TFile fs("dataset.root");
	TTree *ts = (TTree*)fs.Get("test_signal");
	TTree *tb = (TTree*)fs.Get("test_background");
	
	
	
	ts->SetBranchAddress("fPt",&x[0]);     //variable loading 
	tb->SetBranchAddress("fPt",&x[0]);
	reader->AddVariable("fPt",&x[0]);
	ts->SetBranchAddress("fImpactParameterProduct",&x[1]);
	tb->SetBranchAddress("fImpactParameterProduct",&x[1]);
	reader->AddVariable("fImpactParameterProduct",&x[1]);
	ts->SetBranchAddress("fCPA",&x[2]);
	tb->SetBranchAddress("fCPA",&x[2]);
	reader->AddVariable("fCPA",&x[2]);
	ts->SetBranchAddress("fCPAXY",&x[3]);
	tb->SetBranchAddress("fCPAXY",&x[3]);
	reader->AddVariable("fCPAXY",&x[3]);
	ts->SetBranchAddress("fDecayLength",&x[4]);
	tb->SetBranchAddress("fDecayLength",&x[4]);
	reader->AddVariable("fDecayLength",&x[4]);
	ts->SetBranchAddress("fDecayLengthNormalised",&x[5]);
	tb->SetBranchAddress("fDecayLengthNormalised",&x[5]);
	reader->AddVariable("fDecayLengthNormalised",&x[5]);
	ts->SetBranchAddress("fDecayLengthXYNormalised",&x[6]);
	tb->SetBranchAddress("fDecayLengthXYNormalised",&x[6]);
	reader->AddVariable("fDecayLengthXYNormalised",&x[6]);
	ts->SetBranchAddress("fImpactParameter0",&x[7]);
	tb->SetBranchAddress("fImpactParameter0",&x[7]);
	reader->AddVariable("fImpactParameter0",&x[7]);
	ts->SetBranchAddress("fImpactParameter1",&x[8]);
	tb->SetBranchAddress("fImpactParameter1",&x[8]);
	reader->AddVariable("fImpactParameter1",&x[8]);
	ts->SetBranchAddress("fM",&x[9]);
	tb->SetBranchAddress("fM",&x[9]);
	reader->AddVariable("fM",&x[9]);
	ts->SetBranchAddress("fPtProng0",&x[10]);
	tb->SetBranchAddress("fPtProng0",&x[10]);
	reader->AddVariable("fPtProng0",&x[10]);
	ts->SetBranchAddress("fPtProng1",&x[11]);
	tb->SetBranchAddress("fPtProng1",&x[11]);
	reader->AddVariable("fPtProng1",&x[11]);
	ts->SetBranchAddress("fImpactParameterNormalised0",&x[12]);
	tb->SetBranchAddress("fImpactParameterNormalised0",&x[12]);
	reader->AddVariable("fImpactParameterNormalised0",&x[12]);
	ts->SetBranchAddress("fImpactParameterNormalised1",&x[13]);
	tb->SetBranchAddress("fImpactParameterNormalised1",&x[13]);
	reader->AddVariable("fImpactParameterNormalised1",&x[13]);
	ts->SetBranchAddress("fCosThetaStar",&x[14]);
	tb->SetBranchAddress("fCosThetaStar",&x[14]);
	reader->AddVariable("fCosThetaStar",&x[14]);

	
	reader->BookMVA("Cuts",fname);
	
	reader->BookMVA("PDERS",fname);
	
	int nents = ts->GetEntries();
	nents = 1000;
 	for(int e=0; e<nents; e++){
		ts->GetEntry(e);
		h=reader->EvaluateMVA("Cuts",0.95);
		if(h>=0.56){
			s_pass=s_pass+1;}
		else{
			s_fail=s_fail+1;}
			}
	int nentb = tb->GetEntries();
	nentb = 1000;
 	for(int e=0; e<nentb; e++){
		tb->GetEntry(e);
		h=reader->EvaluateMVA("Cuts",0.95);
		if(h>=0.56){
			b_pass=b_pass+1;}
		else{
			b_fail=b_fail+1;}
			}
	sign = s_pass/sqrt(s_pass+b_pass);
	eff = s_pass/(s_pass+s_fail);
	
	cout<<"For "<<nents<<" signal and for "<<nentb<<" background the "<<endl;
	cout<<"Significance is "<<sign<<endl;
	cout<<"Signal efficiancy is "<<eff<<endl;
}
