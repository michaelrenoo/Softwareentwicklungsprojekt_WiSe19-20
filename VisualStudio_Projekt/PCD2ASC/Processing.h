#pragma once
#include <pcl/io/ply_io.h>
#include <string>
#include <vector>
#include <utility> 

using namespace std;


class Processing
{
public:
	pcl::PointCloud<pcl::PointXYZ>::Ptr transformationMatrix(pcl::PointCloud<pcl::PointXYZ>::Ptr);
	pcl::PointCloud<pcl::PointXYZ>::Ptr plyReader(string&);
	void Processing::plyWriter(string, pcl::PointCloud<pcl::PointXYZ>::Ptr);
	pcl::PointCloud<pcl::PointXYZ>::Ptr removeBackground(pcl::PointCloud<pcl::PointXYZ>::Ptr);
	pair<float, float> Processing::removalParameters(pcl::PointCloud<pcl::PointXYZ>::Ptr);
};