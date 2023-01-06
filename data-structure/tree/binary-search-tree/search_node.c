SCORE * Search_Node(SCORE * head, int id)
{
	SCORE* node = head;
	while (node) { // node가 존재할 때
		if (node->id == id) return node;
		else if (node->id > id) node = ndoe->left;
		else node = node->right;
	}
	return (SCORE*)0; //탐색 실패시 NULL pointer 리턴
}
