void train(){

  TMVA::Tools::Instance();

  TFile *fo = new TFile("tmp.root","recreate");
  TMVA::Factory *factory = new TMVA::Factory("O2", fo,"!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D");
  TMVA::DataLoader *dataloader = new TMVA::DataLoader("dataset");
  
  dataloader->AddVariable("fPt");
  dataloader->AddVariable("fImpactParameterProduct");
  dataloader->AddVariable("fCPA");
  dataloader->AddVariable("fCPAXY");
  dataloader->AddVariable("fDecayLength");
  dataloader->AddVariable("fDecayLengthNormalised");
  dataloader->AddVariable("fDecayLengthXYNormalised");
  dataloader->AddVariable("fImpactParameter0");
  dataloader->AddVariable("fImpactParameter1");
  dataloader->AddVariable("fM");
  dataloader->AddVariable("fPtProng0");
  dataloader->AddVariable("fPtProng1");
  dataloader->AddVariable("fImpactParameterNormalised0");
  dataloader->AddVariable("fImpactParameterNormalised1");
  dataloader->AddVariable("fCosThetaStar");


  TFile Tr("dataset.root");
  TTree *ts = (TTree*)Tr.Get("train_signal");
  TTree *tb = (TTree*)Tr.Get("train_background");
  TTree *qs = (TTree*)Tr.Get("test_signal");
  TTree *qb = (TTree*)Tr.Get("test_background");

  // the 1's are event weights (setting both to 1 ignores that)
  dataloader->AddSignalTree(ts,1,TMVA::Types::kTraining);
  dataloader->AddBackgroundTree(tb,1,TMVA::Types::kTraining);
  dataloader->AddSignalTree(qs,1,TMVA::Types::kTesting);
  dataloader->AddBackgroundTree(qb,1,TMVA::Types::kTesting);

  
 // AdaBoost BDT
 factory->BookMethod(dataloader,TMVA::Types::kBDT,"BDT","!H:!V:NTrees=1000:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=20");

 // Rectangular Cuts
 factory->BookMethod(dataloader,TMVA::Types::kCuts,"Cuts","H:!V:FitMethod=GA");
/*
 //MLP
 factory->BookMethod(dataloader,TMVA::Types::kMLP,"MLP","");
 
 //DNN
 factory->BookMethod(dataloader,TMVA::Types::kDNN,"DNN","Architecture=CPU:Layout=TANH|1024,TANH|512,TANH|512,LINEAR:TrainingStrategy=LearningRate=1e-1,Momentum=0.3,Repetitions=3,ConvergenceSteps=50,BatchSize=30,TestRepetitions=7,WeightDecay=0.0,Renormalize=L2,DropConfig=0.0+0.3+0.3,DropRepetitions=5|LearningRate=1e-4,Momentum=0.3,Repetitions=3,ConvergenceSteps=50,BatchSize=20,TestRepetitions=7,WeightDecay=0.001,Renormalize=L2,DropConfig=0.0+0.7+0.7,DropRepetitions=5,Multithreading=True");
*/
 //Likelihood
 factory->BookMethod(dataloader,TMVA::Types::kLikelihood, "Likelihood","!H:!V");
 factory->BookMethod(dataloader,TMVA::Types::kPDERS,"PDERS","!H:!V:KernelEstimator=Gauss:NEventsMin=100:NEventsMax=200:MaxVIterations=150:VolumeRangeMode=Adaptive");

 //train
 factory->TrainAllMethods();
 factory->TestAllMethods();
 factory->EvaluateAllMethods();

 //clean-up
 fo->Close();
 delete factory;
 delete dataloader;

 //TMVA::TMVAGui("tmp.root");
}
