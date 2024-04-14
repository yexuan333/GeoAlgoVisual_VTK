#include "BVH.h"
#include "BVHNode.h"
#include "Container.h"

void main() {
	std::vector<Point3d> ps;
	ps.push_back(Point3d(1, 2, 3));
	ps.push_back(Point3d(24, 3, 3));
	ps.push_back(Point3d(93, 21, 26));
	ps.push_back(Point3d(28, 23, 86));
	ps.push_back(Point3d(86, 42, 10));
	ps.push_back(Point3d(53, 22, 72));
	ps.push_back(Point3d(124, 52, 92));
	ps.push_back(Point3d(65, 26, 49));
	ps.push_back(Point3d(25, 27, 61));
	BVH<Point3d> bvh;
	bvh.Init(ps);
}