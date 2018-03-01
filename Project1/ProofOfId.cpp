#include "ProofOfId.h"

ProofOfId::ProofOfId(string newProofID) : proofID(newProofID)
{
	
}

ProofOfId::~ProofOfId()
{
}


string ProofOfId::getProofId()
{
	return proofID;
}

void ProofOfId::setProofId(string newProofID)
{
	proofID = newProofID;
}