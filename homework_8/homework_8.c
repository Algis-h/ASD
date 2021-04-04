#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"


int height(Tree * tree)
{
	int hl=0,hr=0;

	if(tree==NULL)
	{
		return 0;
	}
	
	hl=height(tree->left);
	hr=height(tree->right);
	
	if(hl>hr)
	{
		return hl+1;
	}
	else
	{
		return hr+1;
	}
}

int isBalanced(Tree * tree)
{
	int hl, hr;
	if(tree==NULL)
	{
		return true;
	}
	hl=height(tree->left);
	hr=height(tree->right);
	if(abs(hl-hr)<=1 && isBalanced(tree->left) && isBalanced(tree->right))
	{
		return true;
	}
	return false;

}

Tree * searchTree(Tree * tree, int data)
{
	Tree * cur = tree;

	if (tree == NULL)
	{
		return NULL;
	}
	if(tree->data == data)
	{
		return tree;
	}

	if (data < cur->data)
	{
		searchTree(cur->left, data);
	}
	else
	{
		searchTree(cur->right, data);
	}
	if(cur == NULL)
	{
		return NULL;
	}
}


int main(int argc, char const *argv[])
{

	// Task 1

	Tree* tree = tInsert(NULL, 10);
	tInsert(tree, 8);
	tInsert(tree, 19);
	tInsert(tree, 5);
	tInsert(tree, 9);
	tInsert(tree, 16);
	tInsert(tree, 21);


	Tree* tree2 = tInsert(NULL, 10);
	tInsert(tree2, 8);
	tInsert(tree2, 5);
	tInsert(tree2, 9);
	
	

	printTree(tree);
	printf("Дерево %sсбалансировано.\n", isBalanced(tree)?"":"не");
	printTree(tree2);
	printf("Дерево %sсбалансировано.\n", isBalanced(tree2)?"":"не");

	// freeTree(tree); //Непонятно как очищать память.
	// freeTree(tree2);
	// printTree(tree); // выдает странные значения.
	// printTree(tree2);

	// Task 2

	float balanced = 0;
	
	int size = 50;
	Tree * arrTree[size];
	printf("\nBalanced = %.2f, size = %d\n", balanced, size);
	
		for (int i = 0; i < size; ++i)
		{
			arrTree[i] = tInsert(NULL, 33);
			fillRandomTree(arrTree[i], 10000, 50);
			if(isBalanced(arrTree[i]))
			{
				balanced++;
			}
		}
	printf("Процент сбалансированных деревьев: %.2f%\n", (balanced/size)*100);
	printf("Balanced = %.2f, size = %d\n", balanced, size);

	// Task 3

	Tree* tree3 = tInsert(NULL, 10);
	tInsert(tree3, 8);
	tInsert(tree3, 19);
	tInsert(tree3, 5);
	tInsert(tree3, 9);
	tInsert(tree3, 16);
	tInsert(tree3, 21);

	printTree(tree3);
	Tree * result = searchTree(tree3, 19);
	printf("\nРезультат поиска %p\n", result); 
	result = searchTree(tree3, 7);
	printf("\nРезультат поиска %p\n", result); 
	return 0;
}