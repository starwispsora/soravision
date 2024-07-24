### soravision
***
### 1(Jul 24) 
  -openCV환경갖추기 : 
    vscode와github연결
    (나는로컬말고코드스페이스 -> c_cpp_properties.jason & settings.jason만들어openCV헤더와연결) 
    /gitigore에특정단어를입력하면그파일은무시하겠다(install/ -local또는클라우드작업공간에서파일을push,pull할때또는개인정보,API등)
  -간단한그림보이기(나는헤드레스로저장)테스트개념 :
    1)컴파일할떄를위한CMakelist.txt.만들어패키지와타켓쓴다
    컴파일명령어가너무어지는것을방지하기위해나누는명령어 : cmake.. -> make -> ./targetfilename
    2)이미지파일준비하고아래코드에삽입
    //cv::imshow("image", img); 
    //cv::waitKey(0); 
    cv::imwrite("output.jpg", img); 
    std::cout << "Image saved to output.jpg" << std::endl;
    3)따로폴더(install)를만들어들어가컴파일(cmake.. -> make)한후타켓실행(./targetname)
   -openCV setting :
    - made vscode to enable github commit locally(but chose githubcodespace) 
    - made c_cpp_properties.jason and settings.jason files in a folder ; openCV header setting 
    - .gitigore makes certain files to be ignore(install/ - for protecting sensitive info)
  -image printing test(but chose headless mode = save image) :
    1)add CMakelist.txt folder ; lists including aimed target and package needed for compiling.
    use compiliar commands seperately to prevent overly longer command. 
    cmake.. -> make -> ./targetfilename
    2)preparing image file and its path. -> write code includes them
    //cv::imshow("image", img); 
    //cv::waitKey(0); 
    cv::imwrite("output.jpg", img); 
    std::cout << "Image saved to output.jpg" << std::endl;
    3)add a new folder('install' here) and compile, run(cmake.. -> make -> ./targetname)
 

  
***



