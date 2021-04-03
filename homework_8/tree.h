typedef struct Tree
{
	int data;
	struct Tree * left;
	struct Tree * right;
} Tree;

Tree* tInsert(Tree * tree, int data)
{
	Tree* new = (Tree*) malloc(sizeof(Tree));
	new->data = data;
	new->left = NULL;
	new->right = NULL;

	Tree* cur = tree;
	Tree* parent = tree;

	if(tree == NULL)
	{
		tree = new;
	}
	else
	{
		while(true)//(cur->data != data)
		{
			parent = cur;
			if(cur->data > data)
			{
				cur = cur->left;
				if (cur == NULL)
				{
					parent->left = new;

					return tree;
				}
			}
			else
			{
				cur = cur->right;
				if (cur == NULL)
				{
					parent->right = new;

					return tree;
				}				
			}
		}
	}

	return tree;
}

void fillRandomTree(Tree * tree, int count, int border)
{
	for (int i = 0; i < count; ++i)
	{
		tInsert(tree, rand()%border);
	}
}

void fillCountTree(Tree * tree, int count)
{
	for (int i = 1; i <= count; ++i)
	{
		if (i%2)
		{
			tInsert(tree, i);
		}
		else
		{
			tInsert(tree, count - i);
		}
	}
}

Tree * getSuc(Tree * tree)
{
	Tree * cur = tree->right;
	Tree * parent = tree;
	Tree * suc = tree;

	while(cur != NULL)
	{
		parent = suc;
		suc = cur;
		cur = cur->left;
	}
	if (suc != tree->right)
	{
		parent->left = suc->right;
		suc->right = tree->right;
	}
	return suc;
}

bool delItem(Tree* tree, int data)
{
	Tree * cur = tree;
	Tree * parent = tree;
	bool isLeft = true;

	while(cur->data != data)
	{
		parent = cur;
		if(data < cur->data)
		{
			cur = cur->left;
			isLeft = true;
		}
		else
		{
			cur = cur->right;
			isLeft = false;
		}
		if (cur == NULL)
		{
			return false;
		}
	}
	if (cur->left == NULL && cur->right == NULL)
	{
		if (cur == tree)
		{
			tree = NULL;
		}
		else if (isLeft)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}
	else if (cur->right == NULL)
	{
		if (isLeft)
		{
			parent->left = cur->left;
		}
		else
		{
			parent->right = cur->left;
		}
	}
	else if (cur->left == NULL)
	{
		if (isLeft)
		{
			parent->left = cur->right;
		}
		else
		{
			parent->right = cur->right;
		}
	}
	else
	{
		Tree * suc = getSuc(cur);
		if (cur == tree)
		{
			tree = suc;
		}
		else if (isLeft)
		{
			parent->left = suc;
		}
		else
		{
			parent->right = suc;
		}
		suc->left = cur->left;
	}
	return true;
}

void printTree(Tree* tree)
{
	if (tree)
	{
		printf("%d", tree->data);
		if (tree->left || tree->right)
		{
			printf("(");
			if (tree->left)
			{
				printTree(tree->left);
			}
			else
			{
				printf("NULL");
			}
			printf(",");
			if (tree->right)
			{
				printTree(tree->right);
			}
			else
			{
				printf("NULL");
			}
			printf(")");
		}
	}
}

void bypassOrderTree(Tree * tree)
{
	if(tree)
	{
		printf("%d\t", tree->data);
		bypassOrderTree(tree->left);
		bypassOrderTree(tree->right);
	}
}

void bypassCentralTree(Tree * tree)
{
	if(tree)
	{
		bypassCentralTree(tree->left);
		printf("%d\t", tree->data);
		bypassCentralTree(tree->right);
	}
}

void bypassRevOrderTree(Tree * tree)
{
	if(tree)
	{
		bypassRevOrderTree(tree->left);
		bypassRevOrderTree(tree->right);
		printf("%d\t", tree->data);
	}
}

void freeTree(Tree * tree)
{
	if (tree != NULL)
	{
		freeTree(tree->right);
		freeTree(tree->left);
		free(tree);
	}
}