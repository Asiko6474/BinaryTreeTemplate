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
	//If the root is Null
	if (m_root == nullptr)
		return true;

	//if the root has no left
	if (m_root->hasLeft() = false)
		return true;

	//if the root has no right
	if (m_root->hasRight() = false)
		return true;

	return false;
}

template<typename T>
inline void BinaryTree<T>::insert(T value)
{
	TreeNode<T>* newRoot = new TreeNode<T>(value);
	//if the root is null
	if (m_root == nullptr)
	{
		//assign the root a value.
		m_root = newRoot;
	}
	
	bool isSorting = true;
	TreeNode<T>* currentNode = m_root;


	while (isSorting)
	{
		//if the new root is less than the current node
		if (newRoot->getData() < currentNode->getData())
		{
			//if the current node has a left
			if (currentNode->hasLeft())
			{
				//the current node will be left
				currentNode = currentNode->getLeft();
			}
			//if the current node does not have a left
			else
			{
				//the new root will be the new left. 
				currentNode->setLeft(newRoot);
				isSorting = false;
			}
		
		}

		//if the new root is less than the current node
		if (newRoot->getData() > currentNode->getData())
		{
			//if the current node has a right
			if (currentNode->hasRight())
			{
				//the current node will be right
				currentNode = currentNode->getRight();
			}
			//if there is no right
			else
			{
				//the new root will be the new right.
				currentNode->setRight(newRoot);
				isSorting = false;
			}
			
		}
		//if the new root is the same value as the current node
		if (newRoot->getData() == currentNode->getData())
			//stop sorting/do nothing
			isSorting = false;
	}
}


template<typename T>
inline void BinaryTree<T>::remove(T value)
{
	TreeNode<T>* currentNode = nullptr;
	TreeNode<T>* nodeRemove = nullptr;
	TreeNode<T>* parentNode = nullptr;

	if (!findNode(value, nodeRemove, parentNode))
		return;
	
	if (nodeRemove->hasRight())
	{
		
		currentNode = nodeRemove->getRight();
		
		if (currentNode->hasLeft())
		{
			
			parentNode = currentNode;

			bool searching = true;
			
			while (searching)
			{
				
				if (m_root != NULL)
				{
					
					if (parentNode->getLeft()->hasLeft())
					{
						
						parentNode = parentNode->getLeft();
					}
					
					else
					{
						
						currentNode = parentNode->getLeft();
						
						searching = false;
					}

				}
			}
			
			nodeRemove->setData(currentNode->getData());
			
			parentNode->setLeft(currentNode->getRight());
			
			delete currentNode;

		}
		else {
			
			nodeRemove->setData(currentNode->getData());

			
			if (currentNode->hasRight()) {
				
				nodeRemove->setRight(currentNode->getRight());
			}
			
			else nodeRemove->setRight(nullptr);
			
			delete currentNode;
		}

	}
	else
	{
		
		if (parentNode)
		{
			
			if (nodeRemove->hasLeft())
			{
				
				currentNode = nodeRemove->getLeft();

				
				if (parentNode->getLeft() == nodeRemove)
					parentNode->setLeft(currentNode);

				
				else if (parentNode->getRight() == nodeRemove)
					parentNode->setRight(currentNode);
				
				delete nodeRemove;
				return;
			}
			else
			{
				if (parentNode->getLeft() == nodeRemove)
					parentNode->setLeft(nullptr);
				else if (parentNode->getRight() == nodeRemove)
					parentNode->setRight(nullptr);

				else nodeRemove;
			}
		}
		
		else
		{
			
			if (nodeRemove->hasLeft())
			{
				
				currentNode = nodeRemove->getLeft();
				
				m_root = currentNode;
				
				delete nodeRemove;
				return;
			}

			else
			{
				
				delete nodeRemove;
				
				m_root = nullptr;
			}
		}
		
		delete currentNode;
	}
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	bool searching = true;
	TreeNode<T>* currentNode = m_root;


	while (searching)
	{
		
		if (value > currentNode->getData())
		{
			
			if (currentNode->hasRight())
				currentNode = currentNode->getRight();
			else
				break;
		}
		else if (value < currentNode->getData())
		{
			
			if (currentNode->hasLeft())
				currentNode = currentNode->getLeft();
			else
				break;
		}
		else if (value == currentNode->getData())
			return currentNode;
	}
	
	return NULL;
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

template<typename T>
inline bool BinaryTree<T>::findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)
{
	bool search = true;
	TreeNode<T>* currentNode = m_root;
	TreeNode<T>* currentParent = m_root;
	while (search)
	{
		
		if (searchValue > currentNode->getData())
		{
			
			if (currentNode->hasRight())
			{
				
				currentParent = currentNode;
				currentNode = currentParent->getRight();
			}
			else
			{
				break;
			}

		}
		else if (searchValue < currentNode->getData())
		{
			
			if (currentNode->hasLeft())
			{
				currentParent = currentNode;
				currentNode = currentParent->getLeft();
			}
			else
			{
				break;
			}
		}

		else if (searchValue == currentNode->getData())
		{
			nodeFound = currentNode;

			if (currentParent->getData() == nodeFound->getData())
			{
				
				nodeParent == nullptr;
			}
			else
			{
				
				nodeParent = currentParent;
			}
			return true;
		}
	}

	return false;
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
