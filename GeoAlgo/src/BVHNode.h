#pragma once

#include "Stdafx.h"
#include "Box.h"

enum class NodeType {
	None,
	Root,
	Internal,
	Leaf,
};

template <typename T>
class BVHNode
{
public:
	BVHNode() = default;
	BVHNode(T data, const Box& box) : m_data(data), m_box(box){}
	SETTERANDGETTER(NodeType, Type, m_type)
	GETTER(Box, Box, m_box)
	void addChild(BVHNode<T>* node) {
		m_box.unionBox(node->m_box);
		m_children.push_back(node);
	}
	void reserve(int size) {
		m_children.reserve(size);
	}
	BVHNode<T>* getChild(int index) {
		return m_children[index];
	}
	int childrenSize() {
		return m_children.size();
	}
	void clearChildren() {
		m_children.clear();
	}
	std::vector<BVHNode<T>*>&& moveChildren() {
		return std::move(m_children);
	}
	~BVHNode() {}
private:
	T m_data;
	Box m_box;
	std::vector<BVHNode<T>*> m_children;
	NodeType m_type;
};