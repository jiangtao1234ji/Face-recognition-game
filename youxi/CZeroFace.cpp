/*#include"CZerolib.h"
#include <dlib/opencv.h>  
#include <opencv2/opencv.hpp>  
#include <dlib/image_processing/frontal_face_detector.h>  
#include <dlib/image_processing/render_face_detections.h>  
#include <dlib/image_processing.h>  
#include <dlib/gui_widgets.h>  

using namespace dlib;
using namespace std;
using namespace cv::ml;

int FaceThread(void *a) {
	cv::VideoCapture cap(0);
	frontal_face_detector detector = get_frontal_face_detector();
	shape_predictor pose_model;
	deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;
	cv::Ptr<SVM> svm = StatModel::load<SVM>("CWQ1001_DATA.xml");
	
	while(Zero_GameQuit==false){
		cv::Mat temp;
		cap >> temp;
		cv_image<bgr_pixel> cimg(temp);
		std::vector<rectangle> faces = detector(cimg);
		std::vector<full_object_detection> shapes;
		for (unsigned long i = 0; i < faces.size(); ++i)
			shapes.push_back(pose_model(cimg, faces[i]));
		if (!shapes.empty()) {
			for (int i = 0; i < shapes.size(); ++i) {
				if (0 == i) {
					for (int j = 0; j < 68; ++j) {
						circle(temp, cvPoint(shapes[i].part(j).x(), shapes[i].part(j).y()),
							2, cv::Scalar(255, 0, 0), -1);
					}
				}
				else {
					for (int j = 0; j < 68; ++j) {
						circle(temp, cvPoint(shapes[i].part(j).x(), shapes[i].part(j).y()),
							2, cv::Scalar(0, 255, 0), -1);
					}
				}


				if (0 == i) {
					float testData[1][136];
					float Coe = -(faces[0].top() - faces[0].bottom()) / 300.0;
					for (int i = 0; i < 68; i++) {
						testData[0][i * 2] = (shapes[0].part(i).x() - faces[0].left()) / Coe;
						testData[0][i * 2 + 1] = (shapes[0].part(i).y() - faces[0].top()) / Coe;
					}

					cv::Mat query(1, 136, CV_32FC1, testData);

					if (svm->predict(query) == 11) {
						cv::putText(temp, "Happy", cv::Point(0, 60), 3, 2, cvScalar(0, 0, 255));
						FaceStatus1 = 0;
					}

					if (svm->predict(query) == 12) {
						cv::putText(temp, "Common", cv::Point(0, 60), 3, 2, cvScalar(0, 0, 255));
						FaceStatus1 = 1;
					}
					if (svm->predict(query) == 13) {
						cv::putText(temp, "Sad", cv::Point(0, 60), 3, 2, cvScalar(0, 0, 255));
						FaceStatus1 = 2;
					}
				}
				else {
					float testData[1][136];
					float Coe = -(faces[1].top() - faces[1].bottom()) / 300.0;
					for (int i = 0; i < 68; i++) {
						testData[0][i * 2] = (shapes[1].part(i).x() - faces[1].left()) / Coe;
						testData[0][i * 2 + 1] = (shapes[1].part(i).y() - faces[1].top()) / Coe;
					}
					cv::Mat query(1, 136, CV_32FC1, testData);

					if (svm->predict(query) == 11) {
						cv::putText(temp, "Happy", cv::Point(320, 60), 3, 2, cvScalar(0, 0, 255));
						FaceStatus2 = 0;
					}

					if (svm->predict(query) == 12) {
						cv::putText(temp, "Common", cv::Point(320, 60), 3, 2, cvScalar(0, 0, 255));
						FaceStatus2 = 1;
					}
					if (svm->predict(query) == 13) {
						cv::putText(temp, "Sad", cv::Point(320, 60), 3, 2, cvScalar(0, 0, 255));
						FaceStatus2 = 2;
					}
				}
			}
		}
		imshow("表情识别      ESC退出", temp);


		std::cout << "FaceStatus1:" << FaceStatus1 << std::endl;
		std::cout << "FaceStatus2:" << FaceStatus2 << std::endl;

		cv::waitKey(20);
	}
	return 0;
}*/