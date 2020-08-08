
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat image = imread("james.jpg");

    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    //Blur the image with 3x3 Gaussian kernel
    Mat image_blurred_with_3x3_kernel;
    GaussianBlur(image, image_blurred_with_3x3_kernel, Size(3, 3), 0);

    //Blur the image with 5x5 Gaussian kernel
    Mat image_blurred_with_5x5_kernel;
    GaussianBlur(image, image_blurred_with_5x5_kernel, Size(5, 5), 0);

    namedWindow("James");
    namedWindow("James Blurred with 3 x 3 Gaussian Kernel");
    namedWindow("James Blurred with 5 x 5 Gaussian Kernel");

    // Show our images inside the created windows.
    imshow("James", image);
    imshow("James Blurred with 3 x 3 Gaussian Kernel", image_blurred_with_3x3_kernel);
    imshow("James Blurred with 5 x 5 Gaussian Kernel", image_blurred_with_5x5_kernel);

    waitKey(0); // Wait for any keystroke in the window

    destroyAllWindows(); //destroy all opened windows

    return 0;
}