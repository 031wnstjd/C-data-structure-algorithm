SCORE * Create_Node(SCORE * d)
{
	SCORE * p;

	p = calloc(1, sizeof(SCORE));
	if (p == (void *)0x0) return p;
	*p = *d;

	p->parent = p->left = p->right = (SCORE*)0; // 연결 정보는 null pointer로 초기화

	return p;
}

int Insert_Node(SCORE * head, SCORE * d) // head : root node의 주소, d : 추가 데이터의 주소
{
	SCORE *newnode = Create_Node(d);
	if (newnode == (SCORE*)0) return -1;

	if (head == (SCORE*)0) { // root node가 null이라면 (tree에 데이터가 하나도 없다면)
		Root = newnode; // root node의 부모와 자식은 모두 null이므로, newnode 할당 외에 별다른 데이터 수정 X
	}
	else { // tree에 node가 존재한다면
		SCORE *parent = head; // head부터 탐색 시작
		
		while (parent) { // 부모노드가 존재할 때만 탐색
			if (parent->id == newnode->id) { // id가 같은 노드가 이미 존재하면 insert 실패
				free(newnode);
				return -2;
			}
			
       // 1. 왼쪽 연결
			if (parent->id > newnode->id) {
				// (1) 왼쪽 자식이 존재하는 경우
				if (parent->left) parent = parent->left; // parent를 왼쪽 자식으로 변경
				// (2) 왼쪽 자식이 존재하지 않는 경우
				else {
					parent->left = newnode;
					newnode->parent = parent;
					break;
				}
			}
      // 2. 오른쪽 연결
			else {
        // (1) 오른쪽 자식이 존재하는 경우
				if (parent->right) parent = parent->right;
				// (2) 오른쪽 자식이 존재하지 않는 경우
        else {
					parent->right = newnode;
					newnode->parent = parent;
					break;
				}
			}
		}
	}
	return 1;
}
