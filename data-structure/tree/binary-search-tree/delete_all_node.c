// Postorder Traverse 사용 (Inorfer를 하는 경우, 부모노드가 자식노드보다 먼저 삭제되므로 문제가 발생하기 때문)
void Delete_All_Node(SCORE * p)
{
	if (p->left) Delete_All_Node(p->left);
	if (p->right) Delete_All_Node(p->right);
	if (p == Root) Root  = (SCORE *)0; // 마지막으로 root노드만 남았다면 이를 null로 만듦
	free(p);
}
