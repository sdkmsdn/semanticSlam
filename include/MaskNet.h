/**
* This file is part of DynaSLAM.
* Copyright (C) 2018 Berta Bescos <bbescos at unizar dot es> (University of Zaragoza)
* For more information see <https://github.com/bertabescos/DynaSLAM>.
*
*/

#ifndef __MASKNET_H
#define __MASKNET_H

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#include <python2.7/Python.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <cstdio>
#include <boost/thread.hpp>
#include "include/Conversion.h"

namespace DynaSLAM
{

class SegmentDynObject{
private:
	NDArrayConverter *cvt; 	/*!< Converter to NumPy Array from cv::Mat */
	PyObject *py_module; 	/*!< Module of python where the Mask algorithm is implemented */
	PyObject *py_class; 	/*!< Class to be instanced */
	PyObject *net; 			/*!< Instance of the class */
	std::string py_path; 	/*!< Path to be included to the environment variable PYTHONPATH */
	std::string module_name; /*!< Detailed description after the member */
	std::string class_name; /*!< Detailed description after the member */
    std::string get_dyn_seg; 	/*!< Detailed description after the member */
	std::string get_seg_res; 

	void ImportSettings();
public:

	SegmentDynObject();
    ~SegmentDynObject();
    cv::Mat GetSegmentation(cv::Mat &image, std::string dir="no_save", std::string rgb_name="no_file");
	void GetSegmentation(cv::Mat &image, cv::Mat &maskRes, std::vector<cv::Rect> &ROIRes, std::vector<int> &ClassIdRes, std::vector<double> &ScoreRes, 
						std::string dir="no_save", std::string rgb_name="no_file");

	cv::Mat GetMaskResult(std::string dir="no_save", std::string rgb_name="no_file");
	std::vector<cv::Rect> GetROIResult();
	std::vector<int> GetClassResult();
	std::vector<double> GetScoreesult();
	void SaveResult(const cv::Mat &maskRes, const std::vector<cv::Rect> &ROIRes, const std::vector<int> &ClassIdRes, const std::vector<double> &ScoreRes, 
					std::string dir="no_save", std::string rgb_name="no_file");
	void ReadResult(std::vector<cv::Rect> &ROIRes, std::vector<int> &ClassIdRes, std::vector<double> &ScoreRes, 
					std::string dir="no_save", std::string rgb_name="no_file");
	void ReadResultOneFile(std::vector<cv::Rect> &ROIRes, std::vector<int> &ClassIdRes, std::vector<double> &ScoreRes, 
					std::string dir="no_save", std::string rgb_name="no_file");
};


}

#endif
