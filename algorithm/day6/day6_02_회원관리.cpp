#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> ht;
int cnt_login;

void UserInit() {
	ht.clear();
	cnt_login = 0;
}

int ChkJoin(string name) {
	auto iter = ht.find(name);
	return iter != ht.end();
}

int ChkLogin(string name) {
	auto iter = ht.find(name);
	return iter != ht.end() && iter->second; // 가입 되어 있고, 로그인 되어 있으면 
}

int Joining(string name) {
	if (ChkJoin(name) != 1) { // 가입 안 돼있으면 등록  
		ht.insert({ name, false });
	}
	return ht.size();
}

int DeleteJoin(string name) {
	if (ChkLogin(name) == 1) cnt_login--; // 로그인 중이었다면 로그인 카운트 1 감소 
	ht.erase(name);
	return ht.size();
}

int Login(string name) {
	if (ChkJoin(name) == 1 && ChkLogin(name) != 1) { // 가입 돼있고, 로그인 안 했으면 
		auto iter = ht.find(name);
		iter->second = true;
		cnt_login++;

	}
	return cnt_login;
}

int Logout(string name) {
	if (ChkLogin(name) == 1) { // 로그인 중이면 
		auto iter = ht.find(name);
		iter->second = false;
		cnt_login--;
	}
	return cnt_login;
}

int main(void) {
	int N;//명령개수
	int cmd;
	string name;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	UserInit();
	for (int i = 0; i < N; i++) {
		cin >> cmd >> name;
		switch (cmd) {
		case 1://가입유무
			cout << ChkJoin(name) << "\n";
			break;
		case 2://로그인유무
			cout << ChkLogin(name) << "\n";
			break;
		case 3:
			cout << Joining(name) << "\n";
			break;
		case 4:
			cout << DeleteJoin(name) << "\n";
			break;
		case 5:
			cout << Login(name) << "\n";
			break;
		case 6:
			cout << Logout(name) << "\n";
		}
	}
	return 0;
}
