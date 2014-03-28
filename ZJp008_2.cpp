#include <iostream>
#include <sstream>

using namespace std;
struct Contest {
	int id, TimeOfFinish, FinishProblem[9], TakePart, NumOfFinish;

};
bool cmp(Contest a, Contest b) {
	if (a.NumOfFinish > b.NumOfFinish)
		return 1;
	else if (a.NumOfFinish == b.NumOfFinish && a.TimeOfFinish < b.TimeOfFinish)
		return 1;
	else if (a.NumOfFinish == b.NumOfFinish && a.TimeOfFinish == b.TimeOfFinish
			&& a.id < b.id)
		return 1;
	return 0;
}
int main() {
	int Contestant = 0, Problem = 0, Time = 0, NumOfTest = 0;
	char State = 0;
	Contest contest[105];
	stringstream sstm;
	string line;
	cin >> NumOfTest;
	for (getline(cin, line); NumOfTest-- + 1;) {
		int IfProcessing = 0;
		for (int j = 0; j < 105; j++) {
			contest[j].id = j;
			memset(contest[j].FinishProblem, 0, sizeof(contest[j].FinishProblem));
			contest[j].NumOfFinish = 0;
			contest[j].TimeOfFinish = 0;
			contest[j].TakePart = 0;
		}
		for (; getline(cin, line) && !line.empty() && line != "\n";
				line.clear(), sstm.clear(), sstm.str("")) {
			IfProcessing = 1;
			sstm << line;
			sstm >> Contestant >> Problem >> Time >> State;
			if (!contest[Contestant - 1].FinishProblem[Problem - 1])
				switch (State) {
				case 'I':
					contest[Contestant - 1].TimeOfFinish += 20;
					contest[Contestant - 1].TakePart = 1;
					contest[Contestant - 1].id = Contestant;
					break;
				case 'C':
					contest[Contestant - 1].TimeOfFinish += Time;
					contest[Contestant - 1].FinishProblem[Problem - 1] = 1;
					contest[Contestant - 1].NumOfFinish++;
				default:
					contest[Contestant - 1].TakePart = 1;
					contest[Contestant - 1].id = Contestant;
					break;
				}
		}
		if (IfProcessing) {
			stable_sort(contest, contest + 105, cmp);
			for (int i = 0; i < 105; i++)
				if (contest[i].TakePart)
					cout << contest[i].id << ' ' << contest[i].NumOfFinish
							<< ' '
							<< !!contest[i].NumOfFinish
									* contest[i].TimeOfFinish << '\n';
			if (NumOfTest + 1)
				cout << endl;
		}
	}
	return 0;
}
