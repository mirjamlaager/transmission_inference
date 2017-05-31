//
//  export.cpp
//  inference_test
//
//  Created by David Eyre on 08/09/2016.
//  Copyright © 2016 David Eyre. All rights reserved.
//

#include "export.hpp"

void exportChain(vector<Parm> &chain, vector<vector<int>> &chainInfTimes, vector<vector<int>> &chainInfSources, vector<vector<int>> &chainInfSourceTypes,
                 vector<vector<int>> &chainRecTimes, int steps, string filePath) {
    FILE *fp;
    string fileName = filePath+"/chain_parameters.txt";
    fp = fopen(fileName.c_str(), "wb");
    fprintf(fp, "beta0\tbeta1\tbeta2\tsampleSize\tsampleMu\tdirectNe\tintroNe\tmu\tstart_inf\tbetacomm\tspore_prob\trec_size\trec_mu\tposterior\tll_trans\tll_genetic\tll_sampling\tll_recovery\n"); //header
    for(int i=0; i<steps; i++) {
        fprintf(fp, "%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\t%0.10f\n", chain[i].betaBgroundHosp, chain[i].betaWard, chain[i].betaHosp, chain[i].sampleSize, chain[i].sampleMu, chain[i].directNe, chain[i].introNe, chain[i].mu, chain[i].betaComm, chain[i].sporeProbLogit, chain[i].probStartInfLogit, chain[i].recSize, chain[i].recMu, chain[i].currentLL, chain[i].currentLLTrans, chain[i].currentLLGenetic, chain[i].currentLLSample, chain[i].currentLLRecovery);
    }
    fclose(fp);
    
    

    
    //write infection times from chain
    fileName = filePath+"/chain_inf_times.txt";
    int nInf = (int)chainInfTimes[1].size();
    string headerText;
    for (int j=0; j<nInf; j++){
        if (chainInfTimes[1][j]!=-1) {headerText += "patient_"+to_string(j)+"\t";}
    }
    headerText += "\n";
    fp = fopen(fileName.c_str(), "wb");
    fprintf(fp, headerText.c_str()); //header
    for(int i=0; i<steps; i++) {
        for (int j=0; j<nInf; j++){
            if (chainInfTimes[1][j]!=-1) {fprintf(fp, "%d\t", chainInfTimes[i][j]);}
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    
    //write recovery times
    fileName = filePath+"/chain_rec_times.txt";
    headerText = "";
    for (int j=0; j<nInf; j++){
        if (chainRecTimes[1][j]!=-1) {headerText += "patient_"+to_string(j)+"\t";}
    }
    headerText += "\n";
    fp = fopen(fileName.c_str(), "wb");
    fprintf(fp, headerText.c_str()); //header
    for(int i=0; i<steps; i++) {
        for (int j=0; j<nInf; j++){
            if (chainRecTimes[1][j]!=-1) {fprintf(fp, "%d\t", chainRecTimes[i][j]);}
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    
    
    //write infection sources
    fileName = filePath+"/chain_inf_sources.txt";
    headerText = "";
    for (int j=0; j<nInf; j++){
        if (chainInfTimes[1][j]!=-1) {headerText += "patient_"+to_string(j)+"\t";}
    }
    headerText += "\n";
    fp = fopen(fileName.c_str(), "wb");
    fprintf(fp, headerText.c_str()); //header
    for(int i=0; i<steps; i++) {
        for (int j=0; j<nInf; j++){
            if (chainInfTimes[1][j]!=-1) {fprintf(fp, "%d\t", chainInfSources[i][j]);}
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    
    //write infection source types
    fileName = filePath+"/chain_inf_source_types.txt";
    headerText = "";
    for (int j=0; j<nInf; j++){
        if (chainInfTimes[1][j]!=-1) {headerText += "patient_"+to_string(j)+"\t";}
    }
    headerText += "\n";
    fp = fopen(fileName.c_str(), "wb");
    fprintf(fp, headerText.c_str()); //header
    for(int i=0; i<steps; i++) {
        for (int j=0; j<nInf; j++){
            if (chainInfTimes[1][j]!=-1) {fprintf(fp, "%d\t", chainInfSourceTypes[i][j]);}
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    
    
}
