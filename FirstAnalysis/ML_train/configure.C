//take tree as input
//create one final signal/background tree
// get all the directries
//loop over all the directeries
//save vars in trees according to sig/bg and do/dobar
#include <cmath>
#include <iostream>
void configure(){


	float tmp;
	float pT, IPP, CPA, CPAXY, decLength, decLengthNorm, decLengthXYNorm, DCAprong0, DCAprong1, InvMass, pTprong0, pTprong1, DCAprong0Norm, DCAprong1Norm, cos_theta_star;
	char MCflag;
	
	TFile *fout = new TFile("dataset.root","RECREATE");
		
	TTree  *t_tr_Sg = new TTree("train_signal","");
	TTree  *t_te_Sg = new TTree("test_signal","");
	TTree  *t_tr_Bg = new TTree("train_background","");
	TTree  *t_te_Bg = new TTree("test_background","");
	t_tr_Sg->SetDirectory(fout);
	t_tr_Bg->SetDirectory(fout);
	t_te_Sg->SetDirectory(fout);
	t_te_Bg->SetDirectory(fout);
	
	t_tr_Sg->Branch("fPt",&pT);
	t_tr_Sg->Branch("fImpactParameterProduct",&IPP);
	t_tr_Sg->Branch("fCPA",&CPA);
	t_tr_Sg->Branch("fCPAXY",&CPAXY);
	t_tr_Sg->Branch("fDecayLength",&decLength);
	t_tr_Sg->Branch("fDecayLengthNormalised",&decLengthNorm);
	t_tr_Sg->Branch("fDecayLengthXYNormalised",&decLengthXYNorm);
	t_tr_Sg->Branch("fImpactParameter0",&DCAprong0);
	t_tr_Sg->Branch("fImpactParameter1",&DCAprong1);
	t_tr_Sg->Branch("fM",&InvMass);
	t_tr_Sg->Branch("fPtProng0",&pTprong0);
	t_tr_Sg->Branch("fPtProng1",&pTprong1);
	t_tr_Sg->Branch("fImpactParameterNormalised0",&DCAprong0Norm);
	t_tr_Sg->Branch("fImpactParameterNormalised1",&DCAprong1Norm);
	t_tr_Sg->Branch("fCosThetaStar",&cos_theta_star);
	
	t_te_Sg->Branch("fPt",&pT);
	t_te_Sg->Branch("fImpactParameterProduct",&IPP);
	t_te_Sg->Branch("fCPA",&CPA);
	t_te_Sg->Branch("fCPAXY",&CPAXY);
	t_te_Sg->Branch("fDecayLength",&decLength);
	t_te_Sg->Branch("fDecayLengthNormalised",&decLengthNorm);
	t_te_Sg->Branch("fDecayLengthXYNormalised",&decLengthXYNorm);
	t_te_Sg->Branch("fImpactParameter0",&DCAprong0);
	t_te_Sg->Branch("fImpactParameter1",&DCAprong1);
	t_te_Sg->Branch("fM",&InvMass);
	t_te_Sg->Branch("fPtProng0",&pTprong0);
	t_te_Sg->Branch("fPtProng1",&pTprong1);
	t_te_Sg->Branch("fImpactParameterNormalised0",&DCAprong0Norm);
	t_te_Sg->Branch("fImpactParameterNormalised1",&DCAprong1Norm);
	t_te_Sg->Branch("fCosThetaStar",&cos_theta_star);
	
	t_tr_Bg->Branch("fPt",&pT);
	t_tr_Bg->Branch("fImpactParameterProduct",&IPP);
	t_tr_Bg->Branch("fCPA",&CPA);
	t_tr_Bg->Branch("fCPAXY",&CPAXY);
	t_tr_Bg->Branch("fDecayLength",&decLength);
	t_tr_Bg->Branch("fDecayLengthNormalised",&decLengthNorm);
	t_tr_Bg->Branch("fDecayLengthXYNormalised",&decLengthXYNorm);
	t_tr_Bg->Branch("fImpactParameter0",&DCAprong0);
	t_tr_Bg->Branch("fImpactParameter1",&DCAprong1);
	t_tr_Bg->Branch("fM",&InvMass);
	t_tr_Bg->Branch("fPtProng0",&pTprong0);
	t_tr_Bg->Branch("fPtProng1",&pTprong1);
	t_tr_Bg->Branch("fImpactParameterNormalised0",&DCAprong0Norm);
	t_tr_Bg->Branch("fImpactParameterNormalised1",&DCAprong1Norm);
	t_tr_Bg->Branch("fCosThetaStar",&cos_theta_star);
	
	t_te_Bg->Branch("fPt",&pT);
	t_te_Bg->Branch("fImpactParameterProduct",&IPP);
	t_te_Bg->Branch("fCPA",&CPA);
	t_te_Bg->Branch("fCPAXY",&CPAXY);
	t_te_Bg->Branch("fDecayLength",&decLength);
	t_te_Bg->Branch("fDecayLengthNormalised",&decLengthNorm);
	t_te_Bg->Branch("fDecayLengthXYNormalised",&decLengthXYNorm);
	t_te_Bg->Branch("fImpactParameter0",&DCAprong0);
	t_te_Bg->Branch("fImpactParameter1",&DCAprong1);
	t_te_Bg->Branch("fM",&InvMass);
	t_te_Bg->Branch("fPtProng0",&pTprong0);
	t_te_Bg->Branch("fPtProng1",&pTprong1);
	t_te_Bg->Branch("fImpactParameterNormalised0",&DCAprong0Norm);
	t_te_Bg->Branch("fImpactParameterNormalised1",&DCAprong1Norm);
	t_te_Bg->Branch("fCosThetaStar",&cos_theta_star);
	
	TFile T("../../codeHF/AnalysisResults_trees_O2.root");
	for (auto k : *T.GetListOfKeys()){
	auto key = dynamic_cast<TKey*>(k);
	//std::cout << "Key name: " << key->GetName() << " Type: " << key->GetClassName() << std::endl;
	TTree *t1 = (TTree*)T.Get(Form("%s/O2hfcandp2full",key->GetName()));
	//t1->Print();
	
	//check if branch exists
	TBranch *check = t1->GetBranch("fPt");
	if(check == NULL){
	cout<<Form("WARNING: O2hfcandp2full TTree in dir %s has no TBranch fPt.",key->GetName())<<endl;
	cout<<Form("WARNING: Skipping dir %s.",key->GetName())<<endl;
	continue;
	}

	t1->SetBranchAddress("fPt",&pT);
	t1->SetBranchAddress("fImpactParameterProduct",&IPP);
	t1->SetBranchAddress("fCPA",&CPA);
	t1->SetBranchAddress("fCPAXY",&CPAXY);
	t1->SetBranchAddress("fDecayLength",&decLength);
	t1->SetBranchAddress("fDecayLengthNormalised",&decLengthNorm);
	t1->SetBranchAddress("fDecayLengthXYNormalised",&decLengthXYNorm);
	t1->SetBranchAddress("fImpactParameter0",&DCAprong0);
	t1->SetBranchAddress("fImpactParameter1",&DCAprong1);
	t1->SetBranchAddress("fM",&InvMass);
	t1->SetBranchAddress("fPtProng0",&pTprong0);
	t1->SetBranchAddress("fPtProng1",&pTprong1);
	t1->SetBranchAddress("fImpactParameterNormalised0",&DCAprong0Norm);
	t1->SetBranchAddress("fImpactParameterNormalised1",&DCAprong1Norm);
	t1->SetBranchAddress("fCosThetaStar",&cos_theta_star);
	t1->SetBranchAddress("fMCflag",&MCflag);
	
	int nent = t1->GetEntries();
	for(int e=0; e<nent; e++){
		t1->GetEntry(e);
		if (isnan(DCAprong0Norm) || isnan(DCAprong1Norm)) continue;
		if (MCflag==1) {
		//fill signal particle
		if (e<nent*0.8) t_tr_Sg->Fill();
		else t_te_Sg->Fill();
		}
		else if (MCflag==-1){
		//fill signal antiparticle
		tmp = pTprong0;
		pTprong0 = pTprong1;
		pTprong1 = tmp;
		tmp = DCAprong0;
		DCAprong0 = DCAprong1;
		DCAprong1 = tmp;
		tmp = DCAprong0Norm;
		DCAprong0Norm = DCAprong1Norm;
		DCAprong1Norm = tmp;
		
		if (e<nent*0.8) t_tr_Sg->Fill();
		else t_te_Sg->Fill();
		}
		else {//fill bg trees
		if (e<nent*0.8) t_tr_Bg->Fill();
		else t_te_Bg->Fill();
		}
		}
	delete t1;
	}

	fout->cd();
	t_tr_Sg->Write();
	t_te_Sg->Write();
	t_tr_Bg->Write();
	t_te_Bg->Write(); 
	T.Close();
	fout->Close();
	cout<<"tasks completed successfully"<<endl;
    }
