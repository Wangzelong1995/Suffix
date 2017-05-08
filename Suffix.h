#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Suffix
{
private:
	int N;
	map<string, vector<string>> suffixDic;
	bool inSuffixDic(string);
	bool isValidN(string);
	int str2int(string);
public:
	Suffix();
	~Suffix();
	void find();
};
