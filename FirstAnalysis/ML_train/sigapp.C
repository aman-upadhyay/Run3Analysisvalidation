// load ttrees test signal and test background 
// finds the NON ml response using hit function
// loop evaluate compare
// make list of signal pass signal fail background pass background fail
//calculate significance and signal efficiancy for non_ML method

#include <iostream> 
#include <cmath>
#include <iomanip>
using namespace std; 

bool hit(float a[15]){
	if(a[0]>=0.0 && a[0]<0.5){
	if(abs(a[9]-1.86)<1.825 && a[4]>0.035 && abs(a[14])<0.55 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.17 && abs(a[7])<0.17 && a[1]<-0.00094 && a[2]>0.53 && a[3]>-0.99 && a[6]>1.165 ) return true; //bin 1
	else return false;
	}
	else if(a[0]>=0.5 && a[0]<1.0){
	if(abs(a[9]-1.86)<1.835 && a[4]>0.035 && abs(a[14])<1.03 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.21 && abs(a[7])<0.21 && a[1]<-0.0009 && a[2]>0.53 && a[3]>-0.99 && a[6]>1.175 ) return true; //bin 2
	else return false;
	}
	else if(a[0]>=1.0 && a[0]<1.5){
	if(abs(a[9]-1.86)<1.815 && a[4]>0.035 && abs(a[14])<0.97 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.21 && abs(a[7])<0.21 && a[1]<-0.00094 && a[2]>0.69 && a[3]>0.65 && a[6]>1.275 ) return true; //bin 3
	else return false;
	}
	else if(a[0]>=1.5 && a[0]<2.0){
	if(abs(a[9]-1.86)<1.835 && a[4]>0.045 && abs(a[14])<0.87 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.29 && abs(a[7])<0.29 && a[1]<-0.001 && a[2]>0.67 && a[3]>0.75 && a[6]>1.325 ) return true; //bin 4
	else return false;
	}
	else if(a[0]>=2.0 && a[0]<2.5){
	if(abs(a[9]-1.86)<1.845 && a[4]>0.035 && abs(a[14])<1.01 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.25 && abs(a[7])<0.25 && a[1]<-0.00014 && a[2]>0.79 && a[3]>0.87 && a[6]>1.425 ) return true; //bin 5
	else return false;
	}
	else if(a[0]>=2.5 && a[0]<3.0){
	if(abs(a[9]-1.86)<1.845 && a[4]>0.035 && abs(a[14])<1.01 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.21 && abs(a[7])<0.21 && a[1]<-0.00006 && a[2]>0.85 && a[3]>0.93 && a[6]>1.465 ) return true; //bin 6
	else return false;
	}
	else if(a[0]>=3.0 && a[0]<3.5){
	if(abs(a[9]-1.86)<1.845 && a[4]>0.035 && abs(a[14])<1.01 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.21 && abs(a[7])<0.21 && a[1]<-0.00005 && a[2]>0.83 && a[3]>0.93 && a[6]>1.465 ) return true; //bin 7
	else return false;
	}
	else if(a[0]>=3.5 && a[0]<4.0){
	if(abs(a[9]-1.86)<1.835 && a[4]>0.015 && abs(a[14])<1.01 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.27 && abs(a[7])<0.27 && a[1]<-0.00002 && a[2]>0.87 && a[3]>0.93 && a[6]>1.465 ) return true; //bin 8
	else return false;
	}
	else if(a[0]>=4.0 && a[0]<4.5){
	if(abs(a[9]-1.86)<1.835 && a[4]>0.005 && abs(a[14])<0.91 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.21 && abs(a[7])<0.21 && a[1]<-0.00002 && a[2]>0.87 && a[3]>0.95 && a[6]>1.045 ) return true; //bin 9
	else return false;
	}
	else if(a[0]>=4.5 && a[0]<5.0){
	if(abs(a[9]-1.86)<1.805 && a[4]>0.015 && abs(a[14])<0.89 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.23 && abs(a[7])<0.23 && a[1]<-0.00002 && a[2]>0.91 && a[3]>0.95 && a[6]>1.105 ) return true; //bin 10
	else return false;
	}
	else if(a[0]>=5.0 && a[0]<5.5){
	if(abs(a[9]-1.86)<1.795 && a[4]>0.005 && abs(a[14])<0.91 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.27 && abs(a[7])<0.27 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.95 && a[6]>0.735 ) return true; //bin 11
	else return false;
	}
	else if(a[0]>=5.5 && a[0]<6.0){
	if(abs(a[9]-1.86)<1.765 && a[4]>0.005 && abs(a[14])<0.93 && a[11]>1.5 && a[10]>1.5 && abs(a[8])<0.33 && abs(a[7])<0.33 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.95 && a[6]>1.145 ) return true; //bin 12
	else return false;
	}
	else if(a[0]>=6.0 && a[0]<6.5){
	if(abs(a[9]-1.86)<1.755 && a[4]>0.005 && abs(a[14])<0.93 && a[11]>1.5 && a[10]>1.5 && abs(a[8])<0.25 && abs(a[7])<0.25 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.95 && a[6]>0.065 ) return true; //bin 13
	else return false;
	}
	else if(a[0]>=6.5 && a[0]<7.0){
	if(abs(a[9]-1.86)<1.735 && a[4]>0.005 && abs(a[14])<0.95 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.27 && abs(a[7])<0.27 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.95 && a[6]>0.165 ) return true; //bin 14
	else return false;
	}
	else if(a[0]>=7.0 && a[0]<7.5){
	if(abs(a[9]-1.86)<1.725 && a[4]>0.005 && abs(a[14])<0.77 && a[11]>1.5 && a[10]>1.5 && abs(a[8])<0.27 && abs(a[7])<0.27 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.97 && a[6]>0.495 ) return true; //bin 15
	else return false;
	}
	else if(a[0]>=7.5 && a[0]<8.0){
	if(abs(a[9]-1.86)<1.705 && a[4]>0.005 && abs(a[14])<0.95 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.25 && abs(a[7])<0.25 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.97 && a[6]>0.095 ) return true; //bin 16
	else return false;
	}
	else if(a[0]>=8.0 && a[0]<9.0){
	if(abs(a[9]-1.86)<1.705 && a[4]>0.005 && abs(a[14])<0.97 && a[11]>1.5 && a[10]>1.5 && abs(a[8])<0.23 && abs(a[7])<0.23 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.95 && a[6]>0.145 ) return true; //bin 17
	else return false;
	}
	else if(a[0]>=9.0 && a[0]<10.0){
	if(abs(a[9]-1.86)<1.715 && a[4]>0.005 && abs(a[14])<1.07 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.33 && abs(a[7])<0.33 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.97 && a[6]>0.725 ) return true; //bin 18
	else return false;
	}
	else if(a[0]>=10.0 && a[0]<12.0){
	if(abs(a[9]-1.86)<1.685 && a[4]>0.005 && abs(a[14])<0.97 && a[11]>1.5 && a[10]>1.5 && abs(a[8])<0.41 && abs(a[7])<0.41 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.99 && a[6]>0.935 ) return true; //bin 19
	else return false;
	}
	else if(a[0]>=12.0 && a[0]<16.0){
	if(abs(a[9]-1.86)<1.355 && a[4]>0.025 && abs(a[14])<1.09 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.31 && abs(a[7])<0.31 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.97 && a[6]>1.055 ) return true; //bin 20
	else return false;
	}
	else if(a[0]>=16.0 && a[0]<20.0){
	if(abs(a[9]-1.86)<1.685 && a[4]>0.035 && abs(a[14])<1.03 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.31 && abs(a[7])<0.31 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.99 && a[6]>2.0 ) return true; //bin 21
	else return false;
	}
	else if(a[0]>=20.0 && a[0]<24.0){
	if(abs(a[9]-1.86)<1.725 && a[4]>0.035 && abs(a[14])<1.09 && a[11]>0.5 && a[10]>0.5 && abs(a[8])<0.33 && abs(a[7])<0.33 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.99 && a[6]>1.855 ) return true; //bin 22
	else return false;
	}
	else if(a[0]>=24.0 && a[0]<36.0){
	if(abs(a[9]-1.86)<1.075 && a[4]>0.035 && abs(a[14])<0.99 && a[11]>3.5 && a[10]>3.5 && abs(a[8])<0.21 && abs(a[7])<0.21 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.93 && a[6]>2.0 ) return true; //bin 23
	else return false;
	}
	else if(a[0]>=36.0&& a[0]<50.0){
	if(abs(a[9]-1.86)<0.005 && a[4]>0.155 && abs(a[14])<1.03 && a[11]>2.5 && a[10]>2.5 && abs(a[8])<0.11 && abs(a[7])<0.11 && a[1]<-0.00002 && a[2]>0.53 && a[3]>0.99 && a[6]>2.0 ) return true; //bin 24
	else return false;
	}
	else if(a[0]>=50.0 && a[0]<100.0){
	if(abs(a[9]-1.86)<1.825 && a[4]>2.0 && abs(a[14])<1.01 && a[11]>51.5 && a[10]>51.5 && abs(a[8])<0.17 && abs(a[7])<0.17 && a[1]<-0.0023 && a[2]>0.53 && a[3]>0.99 && a[6]>2.0 ) return true; //bin 25
	else return false;
	}
	else{
	return false;
	}
}
void test(){   //load this function in root

	double h, sign, eff;    //variable for sorting response value, should be double
	float x[15];   // array to store value from application file
	double s_pass=0;  // # of true positives
	double b_pass=0;  // # of false positives
	double s_fail=0;  // # of false negatives
	double b_fail=0;  // # of true negatives
	

	


  	TFile fs("dataset.root");
	TTree *ts = (TTree*)fs.Get("test_signal");
	TTree *tb = (TTree*)fs.Get("test_background");
	
	
	
	ts->SetBranchAddress("fPt",&x[0]);     //variable loading 
	tb->SetBranchAddress("fPt",&x[0]);

	ts->SetBranchAddress("fImpactParameterProduct",&x[1]);
	tb->SetBranchAddress("fImpactParameterProduct",&x[1]);

	ts->SetBranchAddress("fCPA",&x[2]);
	tb->SetBranchAddress("fCPA",&x[2]);

	ts->SetBranchAddress("fCPAXY",&x[3]);
	tb->SetBranchAddress("fCPAXY",&x[3]);

	ts->SetBranchAddress("fDecayLength",&x[4]);
	tb->SetBranchAddress("fDecayLength",&x[4]);

	ts->SetBranchAddress("fDecayLengthNormalised",&x[5]);
	tb->SetBranchAddress("fDecayLengthNormalised",&x[5]);

	ts->SetBranchAddress("fDecayLengthXYNormalised",&x[6]);
	tb->SetBranchAddress("fDecayLengthXYNormalised",&x[6]);

	ts->SetBranchAddress("fImpactParameter0",&x[7]);
	tb->SetBranchAddress("fImpactParameter0",&x[7]);

	ts->SetBranchAddress("fImpactParameter1",&x[8]);
	tb->SetBranchAddress("fImpactParameter1",&x[8]);

	ts->SetBranchAddress("fM",&x[9]);
	tb->SetBranchAddress("fM",&x[9]);

	ts->SetBranchAddress("fPtProng0",&x[10]);
	tb->SetBranchAddress("fPtProng0",&x[10]);

	ts->SetBranchAddress("fPtProng1",&x[11]);
	tb->SetBranchAddress("fPtProng1",&x[11]);

	ts->SetBranchAddress("fImpactParameterNormalised0",&x[12]);
	tb->SetBranchAddress("fImpactParameterNormalised0",&x[12]);

	ts->SetBranchAddress("fImpactParameterNormalised1",&x[13]);
	tb->SetBranchAddress("fImpactParameterNormalised1",&x[13]);

	ts->SetBranchAddress("fCosThetaStar",&x[14]);
	tb->SetBranchAddress("fCosThetaStar",&x[14]);
	

	
	int nents = ts->GetEntries();
	nents = 1000;
 	for(int e=0; e<nents; e++){
		ts->GetEntry(e);
		h=hit(x);
		if(h==true){
			s_pass=s_pass+1;}
		else{
			s_fail=s_fail+1;}
			}
	int nentb = tb->GetEntries();
	nentb = 1000;
 	for(int e=0; e<nentb; e++){
		tb->GetEntry(e);
		h=hit(x);
		if(h>=true){
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
