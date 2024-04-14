#pragma once
#include "Stdafx.h"
#include "BVHNode.h"
#include <stack>
#include <algorithm>

template <typename T>
struct Bin {
    Box box;
    std::vector<BVHNode<T>*> nodes;
    Bin() = default;
    double cost() const {
        return box.halfArea();
    }
    void add(BVHNode<T>* node) {
        this->box.unionBox(node->getBox());
        nodes.push_back(node);
    }
    void add(const Bin& bin)
    {
        this->box.unionBox(bin.box);
    }
};

template <typename T>
struct BVHArg
{
    T data;
    int index;
};

template <typename T>
class DLLExport BVH
{
public:
    BVH() {
        m_root = new BVHNode<T>();
        m_root->setType(NodeType::Root);
    }
    void Init(const std::vector<Point3d> points) {
        m_root->reserve(points.size());
        for (int i = 0; i < points.size(); i++)
        {
            auto node = new BVHNode<Point3d>(points[i], Box(points[i], points[i]));
            m_root->addChild(node);
        }
        trysplitnode(m_root);
    }

    void trysplitnode(BVHNode<T>* node) {
        std::stack<BVHNode<T>*> stack;
        stack.push(node);
        while (!stack.empty())
        {
            auto node = stack.top();
            stack.pop();

            if (node->childrenSize() <= MaxLeafCount) continue;
            auto axis = get_largest_axis(node->getBox());
            splitnode(node, axis);
            stack.push(node->getChild(0));
            stack.push(node->getChild(1));
        }
    }
    int get_largest_axis(Box& box) {
        auto diagonal = box.getDiagonal();

        int largest = -1;
        double maxValue = -std::numeric_limits<double>::max();
        for (size_t i = 0; i < 3; i++)
        {
            if (diagonal.getCoor(i) > maxValue) {
                maxValue = diagonal.getCoor(i);
                largest = i;
            }
        }
        return largest;
    }

    void splitnode(BVHNode<T>* node, int largestAxis){
        auto diagonal = node->getBox().getDiagonal();
        
        auto scale = (double)BinCount / diagonal;
        auto low = node->getBox().getLow();
        auto offset = Vector3d(low.getX() * scale.getX() * -1,
            low.getY() * scale.getY() * -1,
            low.getZ() * scale.getZ() * -1);

        std::vector<Bin<T>> bins(8);
        for (int i = 0; i < node->childrenSize(); i++) {
            auto child = node->getChild(i);
            Point3d center = child->getBox().getBoxCenter();
            auto pos = Vector3d(center.getX() * scale.getX(),
                center.getX() * scale.getX(),
                center.getX() * scale.getX()) + offset;

            int index = (int)round(std::min(std::max(pos.getCoor(largestAxis), 0.), 7.));
            bins[index].add(child);
        }
        double cost;
        auto splitPos = findBestSplitPosition(bins, cost);
        auto newNode1 = new BVHNode<T>();
        auto newNode2 = new BVHNode<T>();
        if (node->getType() == NodeType::Root) {
            newNode1->setType(NodeType::Internal);
            newNode2->setType(NodeType::Internal);
        }
        else {
            newNode1->setType(node->getType());
            newNode2->setType(node->getType());
        }

        //拆和没拆一样
        if (abs(cost - node->getBox().halfArea()) < 0.1) {
            int mid = (int)(node->childrenSize() / 2);
            auto children = node->moveChildren();
            std::partial_sort(
                children.begin(),
                children.begin() + mid,
                children.end(),
                [&](BVHNode<T>* a, BVHNode<T>* b) {
                    auto c1 = a->getBox().getBoxCenter();
                    auto c2 = a->getBox().getBoxCenter();
                    return c1.getCoor(largestAxis) < c2.getCoor(largestAxis);
                }
            );
            newNode1->reserve(mid);
            for (int i = 0; i < mid; i++)
            {
                newNode1->addChild(children[i]);
            }
            for (int i = mid; i < children.size(); i++)
            {
                newNode2->addChild(children[i]);
            }
        }
        else {
            for (size_t i = 0; i < splitPos; i++)
            {
                newNode1->reserve(newNode1->childrenSize() + bins[i].nodes.size());
                for (auto& node : bins[i].nodes)
                {
                    newNode1->addChild(node);
                }
            }
            for (size_t i = splitPos; i < BinCount; i++)
            {
                newNode2->reserve(newNode2->childrenSize() + bins[i].nodes.size());
                for (auto& node : bins[i].nodes)
                {
                    newNode2->addChild(node);
                }
            }
        }


        //大的节点排前面
        if (newNode1->getBox().halfArea() < newNode2->getBox().halfArea()) {
            std::swap(newNode1, newNode2);
        }
        node->clearChildren();
        node->addChild(newNode1);
        node->addChild(newNode2);

    }

    int findBestSplitPosition(const std::vector<Bin<T>>& bins, double& minCost) {
        Bin<T> right;
        std::vector<double> rightcosts(BinCount);
        for (size_t i = BinCount - 1; i > 0; i--)
        {
            right.add(bins[i]);
            rightcosts[i] = right.cost();
        }

        Bin<T> left;
        double mincost = std::numeric_limits<double>::max();
        int bestPos = -1;
        for (size_t i = 0; i < BinCount - 1; i++)
        {
            left.add(bins[i]);
            auto leftcost = left.cost();
            auto cost = leftcost + rightcosts[i + 1];
            if (cost < mincost) {
                bestPos = i + 1;
                mincost = cost;
            }
        }
        minCost = mincost;
        return bestPos;
    }

    // template<typename T>
    // void IntersectBody(CGMPart* part, const CATBox& box, T cellback) {
    //     std::stack<BVHNode*> stack;
    //     stack.push(m_root);

    //     std::vector<CATBox> searchItem;
    //     searchItem.push_back(box);

    //     while (!stack.empty())
    //     {
    //         auto node = stack.top();
    //         if (node->type == NodeType::Body) {
    //             auto tag = node->body->GetPersistentTag();
    //             auto a = 1;
    //         }
    //         stack.pop();
    //         bool intersect = false;
    //         for (int i = 0; i < searchItem.size(); i++)
    //         {
    //             if (searchItem[i].IsIntersecting(node->box)) {
    //                 intersect = true;
    //                 m_arg.Index = i;
    //                 cellback(node, i, m_arg);
    //                 if (m_arg.SerarchBody.Size() > 0) {
    //                     searchItem.erase(searchItem.begin() + i);
    //                     for (int j = 1; j <= m_arg.SerarchBody.Size(); j++)
    //                     {
    //                         auto newBox = GetTightBoundingBox(*part, *(CATTopology*)m_arg.SerarchBody[j]);
    //                         searchItem.insert(searchItem.begin() + (i + j - 1), newBox);
    //                     }
    //                     m_arg.SerarchBody.RemoveAll();
    //                     break;
    //                 }
    //             }
    //         }
    //         if (intersect && node->type != NodeType::Body) {
    //             for (auto& child : node->children) {
    //                 stack.push(child);
    //             }
    //         }
    //     }
    // }

    ~BVH() {
        delete m_root;
    }
private:
    BVHNode<T>* m_root;
    int BinCount = 8;
    int MaxLeafCount = 2;
    BVHArg<T> m_arg;
};