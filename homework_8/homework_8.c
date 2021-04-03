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

	Tree* tree = tInsert(tree, 10);
	tInsert(tree, 8);
	tInsert(tree, 19);
	tInsert(tree, 5);
	tInsert(tree, 9);
	tInsert(tree, 16);
	tInsert(tree, 21);

// не могу понять почему не работает если заполнять оба дерева сразу.

	// Tree* tree2 = tInsert(tree2, 10);
	// tInsert(tree2, 8);
	// tInsert(tree2, 19);
	// tInsert(tree2, 5);
	// tInsert(tree2, 9);
	// tInsert(tree2, 16);
	// tInsert(tree2, 21);
	

	
	// freeTree(tree); //Непонятно как очищать память.

	printTree(tree);
	printf("Дерево %sсбалансировано.\n", isBalanced(tree)?"":"не");
	// printTree(tree2);
	// printf("Дерево %sсбалансировано.\n", isBalanced(tree2)?"":"не");

	// Task 2

	float balanced = 0;
	
	int size = 50;
	Tree * arrTree[size];// = (Tree**) malloc(sizeof(Tree*));
	printf("Balanced = %.2f, size = %d\n", balanced, size);
	
		for (int i = 0; i < size; ++i)
		{
			arrTree[i] = (Tree*) malloc(sizeof(Tree));

			arrTree[i]->data = 20; // Не совсем понял как сделать массив деревьев. Буду рад комментарию.

			fillRandomTree(arrTree[i], 10000, 50);

			if(isBalanced(arrTree[i]))
			{
				balanced++;

			}

		}
		printf("Процент сбалансированных деревьев: %.2f%\n", (balanced/size)*100);
		printf("Balanced = %.2f, size = %d\n", balanced, size);

		// Task 3

		printTree(tree);
		Tree * result = searchTree(tree, 19);
		printf("\n%d\n", result?result->data:result);
	return 0;
}