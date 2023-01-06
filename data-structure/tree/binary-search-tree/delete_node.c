SCORE* Find_Candidate(SCORE* delnode) {
	SCORE* cand = delnode->left;
	while (cand->right) cand = cand->right; // 후보자 보다 큰 값이 있으면 계속 탐색
	return cand; // 결과적으로, delnode보다 작은 놈들 중에 가장 큰 놈을 찾아서 리턴
}

void _Delete_Node(SCORE *delnode) {
	int cnt_child = 0; // delnode의 자식 노드 수 카운트
	if (delnode->left) cnt_child++;
	if (delnode->right) cnt_child++;
	SCORE* child;
	SCORE* cand; // 후보자 변수

	switch (cnt_child) { // 자식 노드 수에 따라 삭제 코드가 달라짐
		case 0: // delnode의 자식 노드가 없을 때
			if (delnode->parent == (SCORE*)0) { // 삭제할 노드가 루트 노드일 때
				Root = (SCORE*)0; // 루트 노드 삭제
			}
			else {
				if (delnode->parent->left == delnode) delnode->parent->left = (SCORE*)0; // delnode가 왼쪽 자식 노드일 때
				else delnode->parent->right = (SCORE*)0; // delnode가 오른쪽 자식 노드일 때
			}
			free(delnode);
			break;
		case 1:
			child = delnode->left ? delnode->left : delnode->right; // delnode의 자식 중 null이 아닌 쪽의 자식 반환
			if (delnode->parent == (SCORE*)0) { // 삭제할 노드가 루트 노드일 때
				Root = child; // 루트 노드를 child로
				child->parent = (SCORE*)0;
			}
			else { // 삭제할 노드의 부모가 존재할 때
				child->parent = delnode->parent;
			
				if (delnode->parent->left == delnode) delnode->parent->left = child; // 삭제할 노드가 부모의 왼쪽 자식이었으면
				else delnode->parent->right = child; // 삭제할 노드가 부모의 오른쪽 자식이었으면
			}

			free(delnode); // 삭제한 노드 메모리 할당 해제
			break;
		case 2:
			cand = Find_Candidate(delnode);

			// 후보자 정보를 delnode 위치로 복사하고, 후보자 노드를 삭제
			delnode->id = cand->id;
			delnode->jumsu = cand->jumsu;
			strcpy(delnode->name, cand->name);
			_Delete_Node(cand);
			break;
	}

}


int Delete_Node(SCORE * head, int id)
{
	SCORE *delnode = Search_Node(head, id);
	if (delnode == (SCORE*)0) return -1;
	
	_Delete_Node(delnode);

	return 1;
}
