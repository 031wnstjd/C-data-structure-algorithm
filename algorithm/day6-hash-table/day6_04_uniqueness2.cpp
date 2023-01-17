#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

#define MAX_N (100000)

using namespace std;

int N;

unordered_map<string, int> ht;
struct WORDINFO {
	string word;
	list<int> pos_list;
};

int idx_info;
WORDINFO word_infos[MAX_N+10];

void Input_Data(void) {
	cin >> N;
	idx_info = 0;
	string input_word;

	for (int i = 1; i <= N; i++) {
		cin >> input_word;
		auto iter = ht.find(input_word);
		if (iter == ht.end()) { // 처음 입력된 단어일 때
			// 1. 해시 테이블에 정보 추가 (순서 보장 X) - 해시 인덱스 생성
			ht.insert({ input_word, idx_info }); 
			
			// 2. word_infos 배열에 정보 추가(순서 보장 O)
			word_infos[idx_info].word = input_word;
			word_infos[idx_info].pos_list.push_back(i); // 인덱스 위치 추가
			idx_info++;
		}
		else { // 기존에 있는 단어일 때
			word_infos[iter->second].pos_list.push_back(i); // iter->second : 해당 단어의 info_idx 값
		}
	}
}

void Solve(void) {
	if (idx_info == N) { // 해시 테이블에 추가된 단어의 개수가 입력된 문자열의 개수와 같다면 "unique" 리턴
		cout << "unique";
		return;
	}

	for (int i = 0; i < idx_info; i++) { // (idx_info == 해시 테이블에 추가된 단어 개수)
		if (word_infos[i].pos_list.size() > 1) { // 문자열이 여럿 발견된 경우
			cout << word_infos[i].word << " ";
			for (int pos : word_infos[i].pos_list) {
				cout << pos << " ";
			}
			cout << "\n";
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input_Data();

	Solve();

	return 0;
}
