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
	//intialize all nodes to be null
	TreeNode<T>* currentNode = nullptr;
	TreeNode<T>* parentNode = nullptr;
	TreeNode<T>* nodeToRemove = nullptr;

	//attempt to find the node, if not found, then return
	if (!findNode(value, nodeToRemove, parentNode))
		return;

	//if the node to remove has a right
	if (nodeToRemove->hasRight())
	{
		//the current node will become the right	
		currentNode = nodeToRemove->getRight();

		//if the current node has a left
		if (currentNode->hasLeft())
		{
			//the parent node becomes the current node
			parentNode = currentNode;


			bool searching = true;

			//when searching
			while (searching)
			{
				//if the loop is not null
				if (m_root != NULL)
				{
					//checks to see if the node has a left
					if (parentNode->getLeft()->hasLeft())
					{
						//if so the parent becomes the left
						parentNode = parentNode->getLeft();
					}

					else
					{
						//the current node becomes the left
						currentNode = parentNode->getLeft();
						//and returns false
						searching = false;
					}

				}
			}

			//the dates that will be removed will become the current node
			nodeToRemove->setData(currentNode->getData());

			//the parent will be the left of the current's right
			parentNode->setLeft(currentNode->getRight());

			//delete the current node
			delete currentNode;

		}
		else
		{
			//set the remove data to the current node
			nodeToRemove->setData(currentNode->getData());

			//if the current node has a right
			if (currentNode->hasRight())
			{
				//set the remove's right to be the current right
				nodeToRemove->setRight(currentNode->getRight());
			}
			// or else the node being removed will have the right be a nullptr
			else nodeToRemove->setRight(nullptr);

			//delete the current node
			delete currentNode;
		}

	}
	//however if the node has a left
	else
	{
		//if the node has a parent
		if (parentNode)
		{
			//and the node has a left
			if (nodeToRemove->hasLeft())
			{
				//the current node will become the left
				currentNode = nodeToRemove->getLeft();

				//if the node to remove is the parent's left
				if (parentNode->getLeft() == nodeToRemove)
					//the left will be changed to the current left
					parentNode->setLeft(currentNode);

				//if the node to remove is the parent's right
				else if (parentNode->getRight() == nodeToRemove)
					//the right will be changed to the current right
					parentNode->setRight(currentNode);

				//delete the node to remove
				delete nodeToRemove;
				//then return
				return;
			}
			//if the remove does not have a left
			else
			{
				// if the node to remove is the left
				if (parentNode->getLeft() == nodeToRemove)

					//the node will be set to a nullptr
					parentNode->setLeft(nullptr);
				else if (parentNode->getRight() == nodeToRemove;
					//same with right
					parentNode->setRight(nullptr);

					//remove the node
				else nodeToRemove;
			}
		}
		// if the node does not have a parent
		else
		{
			//and if the node has a left
			if (nodeToRemove->hasLeft())
			{
				//make the current node the node to remove's left
				currentNode = nodeToRemove->getLeft();
				//set the root to the current node
				m_root = currentNode;

				//then delete the node to remove
				delete nodeToRemove;
				return;
			}
			//if there is no left
			else
			{
				//simply delete the node to remove
				delete nodeToRemove;
				//and set the root to a nullptr
				m_root = nullptr;
			}
		}
		//delete the current node
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
		//if the value is less than the current's nodee's data
		if (value > currentNode->getData())
		{
			//and if the current node has a right 
			if (currentNode->hasRight())
				//the current node becomes the riht
				currentNode = currentNode->getRight();
			else
				break;
		}
		//if the value is more than the current node's data
		else if (value < currentNode->getData())
		{
			//if the current node has a left
			if (currentNode->hasLeft())
				//then the current node becomes the left
				currentNode = currentNode->getLeft();
			else
				break;
		}
		//if the value is the same as the current node's data
		else if (value == currentNode->getData())
			//then don't change anything
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
		//search the nodes data
		if (searchValue > currentNode->getData())
		{
			//if there is a right 
			if (currentNode->hasRight())
			{
				//then the current parent becomes the current node
				currentParent = currentNode;
				//and makes the node into the parent's right
				currentNode = currentParent->getRight();
			}
			else
			{
				break;
			}

		}
		//else search again
		else if (searchValue < currentNode->getData())
		{
			//if there is a left
			if (currentNode->hasLeft())
			{
				//and do the same thing as the right but on the left
				currentParent = currentNode;
				currentNode = currentParent->getLeft();
			}
			else
			{
				break;
			}
		}

		//if the value is the current node
		else if (searchValue == currentNode->getData())
		{
			//make the found node the current node
			nodeFound = currentNode;

			//if the current parents data is the node found's data
			if (currentParent->getData() == nodeFound->getData())
			{
				//the parent with be a nullprt
				nodeParent == nullptr;
			}

			else
			{
				//the node's parent will be the current parent.
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
