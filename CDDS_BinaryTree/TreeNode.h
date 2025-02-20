#pragma once

template<typename T>
class TreeNode
{
public:
	TreeNode() ;
	TreeNode(T value);
	~TreeNode() {};

	/// <summary>
	/// Returns whether or not this node has a left child
	/// </summary>
	bool hasLeft();
	/// <summary>
	/// Returns whether or not this node has a right child
	/// </summary>
	bool hasRight();

	/// <summary>
	/// Returns the data this node contains 
	/// </summary>
	T getData();
	/// <summary>
	/// Gets the child to the left of this node
	/// </summary>
	TreeNode<T>* getLeft();

	/// <summary>
	/// Gets the child to the right of this node
	/// </summary>
	TreeNode<T>* getRight();

	/// <summary>
	/// Sets the value of the data this node is storing to be the given value0
	/// </summary>
	/// <param name="value">The value to change the data to</param>
	void setData(T value);

	/// <summary>
	/// Sets the left child of this node to be the given node
	/// </summary>
	/// <param name="node">The node to set as this nodes new child</param>
	void setLeft(TreeNode<T>* node);

	/// <summary>
	/// Sets the left child of this node to be the given node
	/// </summary>
	/// <param name="node">The node to set as this nodes new child</param>
	void setRight(TreeNode<T>* node);

	void draw(int x, int y, bool selected = false);

private:
	T m_value;

	TreeNode<T>* m_left;
	TreeNode<T>* m_right;
};



template<typename T>
inline void TreeNode<T>::draw(int x, int y, bool selected)
{
	//Creates an array to store the string representation of the value
	static char buffer[10];

	//Converts the value to a string and stores it in the array
	sprintf(buffer, "%d", m_value);

	//Draws the circle to represent the nod
	DrawCircle(x, y, 30, YELLOW);

	//If the node is the current selected node change its color.
	if (selected)
		DrawCircle(x, y, 28, GREEN);
	else
		DrawCircle(x, y, 28, BLACK);

	//Draw teh value of the node insite its circle.
	DrawText(buffer, x - 12, y - 12, 12, WHITE);
}

template<typename T>
inline TreeNode<T>::TreeNode()
{
	m_left = nullptr;
	m_right = nullptr;
}

template<typename T>
inline TreeNode<T>::TreeNode(T value)
{
	m_value = value;
	m_left = nullptr;
	m_right = nullptr;
}

template<typename T>
inline bool TreeNode<T>::hasLeft()
{
	if (m_left)
		return true;

	else
		return false;
}

template<typename T>
inline bool TreeNode<T>::hasRight()
{
	if (m_right)
		return true;

	else
		return NULL;
}

template<typename T>
inline T TreeNode<T>::getData()
{
	if (m_value != NULL)
		return m_value;

	else
		return NULL;

}

template<typename T>
inline TreeNode<T>* TreeNode<T>::getLeft()
{
	if (hasLeft())
		return m_left;
	else
		return NULL;

}

template<typename T>
inline TreeNode<T>* TreeNode<T>::getRight()
{
	if (hasRight())
		return m_right;
	else
		return NULL;

}

template<typename T>
inline void TreeNode<T>::setData(T value)
{
	m_value = value;
}

template<typename T>
inline void TreeNode<T>::setLeft(TreeNode<T>* node)
{
	m_left = node;
}

template<typename T>
inline void TreeNode<T>::setRight(TreeNode<T>* node)
{
	m_right = node;
}