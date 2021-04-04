#include <iostream>
#include <opencv2/opencv.hpp>
#include <array>

int main(int argc, char** argv) {
    // start timing
    const clock_t begin_time = std::clock();

    // check input
    if (argc != 4) {
        std::cout << "usage: program <Map_Image_Path> <Image_Path> <Save_Path>" << std::endl;
        return -1;
    }

    // create mapping
    cv::Mat map_image_raw = cv::imread(argv[1]);
    if (map_image_raw.empty()) {
        std::cout << "No image data" << std::endl;
        return -1;
    }

    if (map_image_raw.rows != 3 && map_image_raw.cols != 256) {
        std::cout << "Wrong Map Image, it should by 3 by 256 pixels" << std::endl;
        return -1;
    }
    std::array<std::array<int, 256>, 3> map_image = std::array<std::array<int, 256>, 3>();
    for (int i = 0; i < map_image_raw.rows; ++i) {
        for (int j = 0; j < map_image_raw.cols; ++j) {
            cv::Vec3b& color = map_image_raw.at<cv::Vec3b>(i, j);
            map_image[2-i][j] = color[2-i];
        }
    }

    // open input picture
    cv::Mat input_image = cv::imread(argv[2]);
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
    bool isSuccess = cv::imwrite(argv[3], input_image);
    if (!isSuccess) {
        std::cout << "Failed to save the image" << std::endl;
        return -1;
    }

    // print time spent
    std::cout << float(std::clock () - begin_time) /  CLOCKS_PER_SEC << std::endl;
    return 0;
}
