//This is for the task of 5.8.
//5130309427  王泽龙

#include "Suffix.h"

bool Suffix::inSuffixDic(string s) {
	return suffixDic.find(s) != suffixDic.end();
}

bool Suffix::isValidN(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= (int)'0' && s[i] <= (int)'9') { continue; }
		else { return false; }
	}

	return true;
}

int Suffix::str2int(string s) {
	stringstream ss;
	ss.str(s);
	int num;
	ss >> num;
	return num;
}

//Suffix

Suffix::Suffix()
{
	//Establish the suffix dictionary

	string fileName = "dictionary.txt";
	ifstream file("res\\" + fileName);


	string s;
	do {
		cout << "pls enter the integer N:";
		cin >> s;
		if (!isValidN(s)) { cout << "Invalid N." << endl; }
	} while (!isValidN(s));
	N = str2int(s);

	cout << "processing..." << endl;
	string tmp;
	while (file >> tmp) {
		if (tmp.size() < N) { continue; }

		string suffix = tmp.substr(tmp.size() - N, N);

		if (inSuffixDic(suffix)) { suffixDic[suffix].push_back(tmp); }
		else {
			vector<string> vec;
			vec.push_back(tmp);
			suffixDic[suffix] = vec;
		}
	}
	cout << "complete!" << endl;

	file.close();

	//Print the top 10 suffix

	const int TOP = 10;
	vector<string> topSuffix(TOP, "");
	vector<int> topSuffixFrequent(TOP, 0);
	for (auto iter = suffixDic.begin(); iter != suffixDic.end(); iter++) {
		for (int i = 0; i < TOP; i++) {
			if (iter->second.size() > topSuffixFrequent[i]) {
				topSuffixFrequent[i] = iter->second.size();
				topSuffix[i] = iter->first;
				break;
			}
		}
	}

	for (int i = 0; i < TOP; i++) {
		cout << "No." << i + 1 << ':' << topSuffix[i] << "   " << "Frequency:" << topSuffixFrequent[i] << endl;
	}
	cout << endl;
}

Suffix::~Suffix()
{

}

void Suffix::find()
{
	string userSuffix;
	cout << "pls enter a suffix:";
	cin >> userSuffix;

	if (!inSuffixDic(userSuffix)) { cout << "Not found." << endl; return; }

	vector<string> letters(suffixDic[userSuffix]);
	const int lettersNum = letters.size();
	cout << "Number of letters:" << lettersNum << endl;

	cout << "------------Letters------------" << endl;
	for (int i = lettersNum - 1; i != 0; i--) {
		cout << letters[i] << endl;
	}
	cout << endl;
}
