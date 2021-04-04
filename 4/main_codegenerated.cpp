#include <iostream>
#include <opencv2/opencv.hpp>
#include "map_image.h"

int main(int argc, char** argv) {
    // start timing
    const clock_t begin_time = std::clock();

    // check input
    if (argc != 3) {
        std::cout << "usage: program <Image_Path> <Save_Path>" << std::endl;
        return -1;
    }

    // open input picture
    cv::Mat input_image = cv::imread(argv[1]);
    if (input_image.empty()) {
        std::cout << "No image data" << std::endl;
        return -1;
    }

    // make transformation
    for (int i = 0; i < input_image.rows; ++i) {
        for (int j = 0; j < input_image.cols; ++j) {
            cv::Vec3b& color = input_image.at<cv::Vec3b>(i, j);
            color[0] = map_image[0][color[0]];
            color[1] = map_image[1][color[1]];
            color[2] = map_image[2][color[2]];
        }
    }

    // save transformation
    bool isSuccess = cv::imwrite(argv[2], input_image);
    if (!isSuccess) {
        std::cout << "Failed to save the image" << std::endl;
        return -1;
    }

    // print time spent
    std::cout << float(std::clock () - begin_time) /  CLOCKS_PER_SEC << std::endl;
    return 0;
}
