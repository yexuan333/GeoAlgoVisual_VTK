#include "Container.h"
#include <string>

void Container::AddPoint3d(const Point3d& point)
{
	m_points.push_back(point);
}

void Container::Wirte(std::string&& filename)
{
	std::ofstream file(filename);
	file << m_points.size() << '\n';
	for (auto& point : m_points) {
		point.serialise(file);
	}
	file.close();
}

void Container::Read(std::string&& filename)
{
	m_points.clear();
	std::ifstream file(filename);
	int pointsize = 0;
	file >> pointsize;
	for (int i = 0; i < pointsize; i++)
	{
		Point3d p;
		p.deserialise(file);
		m_points.push_back(p);
	}
	file.close();
}

