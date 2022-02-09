#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#pragma once
template<typename T>
class TreeNode;

template<typename T>
class BinaryTree
{
public:

	BinaryTree() { m_root = nullptr; }
	~BinaryTree() {};

	/// <summary>
	/// Returns whether or not there are any nodes in the list
	/// </summary>
	bool isEmpty() const;
	/// <summary>
	/// Creates a new node that stores the given value and places it into the tree
	/// </summary>
	/// <param name="value">The new value to add to the tree</param>
	void insert(T value);
	/// <summary>
	/// Finds the node with the given value and removes it from the tree
	/// </summary>
	/// <param name="value">The value of the node to search for in the tree</param>
	void remove(T value);
	/// <summary>
	/// Finds and returns a node with the given value in the tree
	/// </summary>
	/// <param name="value">The value of the node to search for</param>
	TreeNode<T>* find(T value);

	void draw(TreeNode<T>* selected = nullptr);

private:
	/// <summary>
	/// Finds the node that matches the value in the list
	/// </summary>
	/// <param name="searchValue">The value of the node to search for</param>
	/// <param name="nodeFound">A pointer that will store the address of the node that was found</param>
	/// <param name="nodeParent">A pointer that will store the address of the parent of the node that was found</param>
	/// <returns>Whether or not a node matching the value could be found</returns>
	bool findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent);

	void draw(TreeNode<T>*, int x, int y, int horizontalSpacing, TreeNode<T>* selected = nullptr);

	TreeNode<T>* m_root = nullptr;
};
#endif

template<typename T>
inline bool BinaryTree<T>::isEmpty() const
{
	if (m_root->getLeft() == nullptr && m_root->getRight() == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline void BinaryTree<T>::insert(T value)
{
	TreeNode<T>* newRoot = new TreeNode<T>(value);
	TreeNode<T>* currentNode = m_root;

	if (m_root == nullptr)
		m_root = newRoot;

	if (newRoot->getData() < currentNode->getData())
	{
		if (currentNode->hasLeft())
		{
			currentNode = currentNode->getLeft();
		}
		else
		{
			currentNode->setLeft(newRoot);
		}
		return;
	}

	if (newRoot->getData() > currentNode->getData())
	{
		if (currentNode->hasRight())
		{
			currentNode = currentNode->getRight();
		}
		else
		{
			currentNode->setRight(newRoot);
		}
		return;
	}
}


template<typename T>
inline void BinaryTree<T>::remove(T value)
{
	if (m_root->hasLeft() != true)
	{
		for (T i = m_root->getLeft()->getData(); i != value; i++)
		{
			if (i == value)
			{
				
				i = value;
				
			}
		}
	}
	
	if (m_root->hasRight() != true)
	{
		for (T i = m_root->getRight()->getData(); i != value; i++)
		{
			
			if (i == value)
			{
				i = value;
				
			}
		}
	}

	if (m_root->hasLeft() && m_root->hasLeft() != true)
	{
		for (T i = m_root->getRight()->getData(); i != value; i++)
		{
			for (T c = m_root->getLeft()->getData(); i != value; c++)
				if (i == value)
				{
					i = value;
				}
		}
	}
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	for (T i = m_root->getData(); i != value;)
		if (i == value)
			return  (TreeNode<T>*) value;
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

template<typename T>
inline bool BinaryTree<T>::findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)
{
	while (searchValue != nodeFound)
	{
		if (searchValue > nodeFound) {
			nodeFound->getLeft();
			nodeParent = nodeFound;
			nodeFound = nodeParent->getLeft();
		}
		if (searchValue < nodeFound) {
			nodeFound->getRight();
			nodeParent = nodeFound;
			nodeFound = nodeParent->getRight();
		}
		else if (searchValue == nodeFound)
		{
			nodeParent->getLeft() = nodeFound;
			searchValue == nodeFound;
		}
	}
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected)
{
	horizontalSpacing /= 2;

	if (currentNode)
	{
		if (currentNode->hasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (currentNode->hasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		currentNode->draw(x, y, (selected == currentNode));
	}
}
