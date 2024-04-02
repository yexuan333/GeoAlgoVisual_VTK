#include "BVH.h"
#include "BVHNode.h"
#include "Container.h"

void main() {
	std::vector<MathPoint> ps;
	ps.push_back(MathPoint(1, 2, 3));
	ps.push_back(MathPoint(24, 3, 3));
	ps.push_back(MathPoint(93, 21, 26));
	ps.push_back(MathPoint(28, 23, 86));
	ps.push_back(MathPoint(86, 42, 10));
	ps.push_back(MathPoint(53, 22, 72));
	ps.push_back(MathPoint(124, 52, 92));
	ps.push_back(MathPoint(65, 26, 49));
	ps.push_back(MathPoint(25, 27, 61));
	BVH<MathPoint> bvh;
	bvh.Init(ps);
}