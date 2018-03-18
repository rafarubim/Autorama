#pragma once
#include <vector>
using namespace std;

class ColGen
{
public:
	ColGen(void);
	~ColGen(void);
	vector<vector<char>> Load(char* name);
	void Save(vector<vector<char>> vet, char* name);
};

