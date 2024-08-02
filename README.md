

***
##### 1(22Jul2024) opencv- first / ch02 / ch03

- openCV setting : <br>
    -  made vscode to enable github commit locally(but chose githubcodespace) <br>
    -  made c_cpp_properties.jason and settings.jason files in a folder ; openCV header setting <br>

***

- .gitigore : certain files to be ignore(install/ - for protecting sensitive info) <br>

***

- image printing test(but chose headless mode = save image) : <br>
     1)add CMakelist.txt folder ; lists including aimed target and package needed for compiling. <br>
    use compiliar commands seperately to prevent overly longer command. 
    cmake.. -> make -> ./targetfilename <br>
     2)preparing image file and its path. -> write code includes them <br>
   - //cv::imshow("image", img); <br>
   - //cv::waitKey(0); <br>
   - cv::imwrite("output.jpg", img); <br>
   - std::cout << "Image saved to output.jpg" << std::endl; <br>

   
    3)add a new folder('install' here) and compile, run(cmake.. -> make -> ./targetname) 
<br>

***
##### 2(34Jul2024) opencv- ch03 / ch04

- CMake : pack of orders/rules user would write. work as a translator among team members who may use different tools

***

- matrix : Mat img2(rows, cols, type); <br>
    //Mat img2(400, 600, CV_8UC1); <br>

***
##### 3(24Jul2024) oprncv- ch04

- text : putText(image, text, origin, fontFace, fontScale, color, thickness, lineType, bottomLeftOrigin); <br>
    //putText(img, "font", Point(20, 150), FONT_HERSHEY_PLAIN, 1, red); <br>

***

- line : line(image, start, end, color, thickness, lineType, shift); <br>
    //line(img, pt1, pt2, Scalar(255, 0, 0), 3, LINE_AA); <br><br>
- rectangle : rectangle(image, pt1, pt2, color, thickness, lineType, shift); <br> 
          //rectangle(img, Rect(50, 50, 100, 70), red, 2); <br><br>
- circle : circle(image, center, radius, color, thickness, lineType, shift); <br>           //circle(img, Point(300, 120), 30, green, -1, LINE_AA); <br><br>
- ellipse : ellipse(image, center, axes, angle, startAngle, endAngle, color, thickness, lineType, shift); <br> //ellipse(img, Point(120, 200), Size(60, 30), 20, 0, 300, red, FILLED, LINE_AA); <br>

***

- video : int fourcc = VideoWriter::fourcc(char c1, char c2, char c3, char c4); <br>
    //int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');

***

##### 5(25Jul2024) oprncv- ch05, ch06, ch07
- brightness: <br>
// Example: Increase brightness by adding a constant value to each pixel
Mat brightenedImage;
img.convertTo(brightenedImage, -1, 1, 50); // alpha=1 (no scaling), beta=50 (brightness increase)

<br>

- histogram : <br>
// Compute histogram for a grayscale image
Mat hist;
int histSize = 256; // Number of bins
float range[] = {0, 256}; // Range of pixel values
const float* histRange = {range};
calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, &histRange);
// Display histogram (code to plot histogram not included)

<br>

- bitwise :<br>
// Example: Perform bitwise AND between two images
Mat img1, img2, result;
bitwise_and(img1, img2, result);

<br>

***

- bilateral filter :<br>
Mat filteredImage;
bilateralFilter(img, filteredImage, 9, 75, 75);

<br>

- blur : <br>
Mat blurredImage;
GaussianBlur(img, blurredImage, Size(15, 15), 0);

 <br>

- filter 2D: <br>
Mat kernel = (Mat_<float>(3,3) << -1, -1, -1, -1, 8, -1, -1, -1, -1); // Example: Edge detection kernel
Mat filteredImage;
filter2D(img, filteredImage, CV_8U, kernel);

<br>

- Gaussian filter: <br>
Mat gaussianBlurredImage;
GaussianBlur(img, gaussianBlurredImage, Size(5, 5), 0);

<br>

- sharpening : <br>
Mat sharpeningKernel = (Mat_<float>(3,3) << 0, -1, 0, -1, 5,-1, 0, -1, 0); // Example sharpening kernel
Mat sharpenedImage;
filter2D(img, sharpenedImage, CV_8U, sharpeningKernel);
<br>

***



