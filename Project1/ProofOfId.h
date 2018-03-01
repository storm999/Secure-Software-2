#ifndef ProofOfId_h
#define ProofOfId_h
#pragma once

#include <string>

using namespace std;

class ProofOfId
{
private:
	string proofID = "";
public:
	ProofOfId(string newProofID);
	~ProofOfId();

	string getProofId();
	void setProofId(string newProofID);
};

#endif 