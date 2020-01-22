#include "ReferenceModel.h"
#include "Processing.h"
#include <iostream>							// for std::cout
#include <pcl/io/pcd_io.h>					// header that contains the definitions for PCD I/O operations
#include <pcl/filters/extract_indices.h>	// header to remove points with indices
#include <vector>
#include <utility> 
using namespace std;


int main ()
{
	Processing process;

	process.positioning();

	string sourceCloudFile = "test1_filter15.ply";

	while(true)
	{
		cout << "Press enter to scan an object" << endl;
		cin.get();
		pcl::PointCloud<pcl::PointXYZ>::Ptr scannedObject = process.startScanning("test1_filter15.ply");
		cout << "Done..." << endl;


		scannedObject = process.transformationMatrix(scannedObject);
		scannedObject = process.uptRemoveBackground(scannedObject);
		pcl::io::savePLYFileBinary("scannedObjectCut.ply", *scannedObject);
		//icp here with scannedObject
	}
	
	cin.get();
}

