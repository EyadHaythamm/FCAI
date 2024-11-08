/*Description:This is a photoshop program that helps the user adjust the image
Authors:
Eyad Haytham Ashry(20230077)---> Grayscaling, Merging two images, Edge detection, Darker and brighter image, Infrared.
George Malak (20231042)---> Invert image , Rotate image , Frame for image , Blur image , Natural sunlight image 
Mazen Amr Mohamed(20230307)----> While and black filter, Cropping filter , Flip H & V , Resize , Purple image look 
Section: S21-22
Diagram:https://drive.google.com/file/d/14sIhVrwr_q9lr7lxZsMEXFvNiNARZmc9/view?usp=sharing
*/

#include "Image_Class.h"
#include <iostream>
#include<string>
#include <regex>
#include <cmath>
using namespace std;
void flip(string name){
    int choose ; 
    cout << "You like to: \n" << "[1] Flip image horizontal \n" << "[2] Flip image vertically \n";
    cout << "Enter your choice (the no. of kind flip):"; 
    while (!(cin >> choose)) {
        cout << "Pls enter an integer number : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (choose < 0 || choose > 3) {
        cout << "Pls enter your valid flipping choice: ";
        while (!(cin >> choose)) {
            cout << "Pls enter an integer number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    // function to flip images horizontal
    if(choose == 1){
            Image imgfl(name);
            for (int i =0; i < imgfl.width / 2; ++i){
                for (int j = 0; j < imgfl.height; ++j){
                    for( int k =0; k < 3;++k){
                    // changing pixels horizontal
                    int neww = imgfl.getPixel(i,j,k);
                    imgfl.setPixel(i,j,k,imgfl.getPixel(imgfl.width - i - 1, j, k));
                    imgfl.setPixel(imgfl.width - i - 1, j, k, neww);
                    }
                }
            }
        imgfl.saveImage(name);// save message
        cout<<"Done\n"; // done message

    }//function for flipping images vertically
    else if(choose == 2){
        Image imgfl(name);
        for (int i =0; i < imgfl.width ; ++i){
            for (int j = 0; j < imgfl.height/2; ++j){
                for( int k =0; k < 3;++k){
                // changing pixels vertical
                int neww = imgfl.getPixel(i,j,k);
                imgfl.setPixel(i,j,k,imgfl.getPixel( i,imgfl.height - j - 1, k));
                imgfl.setPixel(i ,imgfl.height - j - 1, k, neww);
                }
            }
        }  
        imgfl.saveImage(name);//save message
        cout<<"Done\n"; // done message
    }  

}

void  invert (string name){
    Image image(name);
    for(int i=0;i<image.width; i++){
        for(int j=0;j<image.height;j++){
            for (int k=0;k<3;k++) { 
                image (i , j , k) =255 - image( i , j , k); //process for image
            }
        }
    }
    image.saveImage(name); //save
    cout<<"Done\n"; // done message
}

void rotate (string name) {
   Image image(name);
    int youch, youdeg; //virable to choose the diraction and the degree
    cout << "Choose Method to rotate image:\n"
        << "1- With clockwise\n"
        << "2- Counter clockwise\n";
    cout << "Enter your method: ";
    while (!(cin >> youch)) { //to check if you choice not any type except integer
        cout << "Pls enter an integer number : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (youch != 1 && youch != 2) {//to check if you choice is 1 or 2
        cout << "Pls enter your valid method choice: ";
        while (!(cin >> youch)) {
            cout << "Please enter an integer number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    
        cout << "Choose the degree which image will be rotated by:\n"
            << "1- 90\n"
            << "2- 180\n"
            << "3- 270\n";
        cout << "Enter your choice: ";
        while (!(cin >> youdeg)) { //to check if your choice not any type except integer
        cout << "Pls enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        while (youdeg != 1 && youdeg != 2 && youdeg != 3) { //to check if you choice is 1 or 2 or 3 to choose the correct deg
            cout << "Pls enter a valid degree choice: ";
            while (!(cin >> youdeg)) {
                cout << "Pls enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

    if (youch == 1 && (youdeg == 1 || youdeg == 2 || youdeg == 3)) { //with clockwise
        Image image2((youdeg % 2 == 0) ? image.width : image.height, (youdeg % 2 == 0) ? image.height : image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (youdeg == 1)
                        image2(j, i, k) = image(i, image.height - 1 - j, k); // 90 deg
                    else if (youdeg == 2)
                        image2(i, j, k) = image(image.width - 1 - i, image.height - 1 - j, k); //180 deg
                    else if (youdeg == 3)
                        image2(image.height - 1 - j, i, k) = image(i, j, k); // 270 deg
                }
            }
        }
        image2.saveImage(name); // save
        cout<<"Done"; // done message
    } else if (youch == 2 && (youdeg == 1 || youdeg == 2 || youdeg == 3)) { //counter clockwise
        Image image2((youdeg % 2 == 0) ? image.width : image.height, (youdeg % 2 == 0) ? image.height : image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (youdeg == 1)
                        image2(j, i, k) = image(image.width - 1 - i, j, k); // 90 deg
                    else if (youdeg == 2)
                        image2(i, j, k) = image(image.width - 1 - i, image.height - 1 - j, k); //180 deg
                    else if (youdeg == 3)
                        image2(image.height - 1 - j, i, k) = image(i, j, k); // 270 deg
                }
            }
        }
        image2.saveImage(name); //save
        cout<<"Done"; // done message
    }    
}

void frame (string name){
    int yourcol , yourfram , red , blue , green ; // vairables to choose colour and kind of frame and some for frame colours
    cout << "If you want : \n" << "1- Simple frame \n 2- Fancy frame \n" ;
    cout << "Enter your choice :"; 
     while (!(cin >> yourfram)) { //check if your choice is integer only
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
     }

    while (yourfram != 1 && yourfram != 2 ){ //check if choice is in range
        cout << "Pls enter correct number of your choice : ";
        while (!(cin >> yourfram)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Choose the color of your frame :\n" << "[1]White \n[2]Black \n[3]Red \n[4]Green \n[5]Blue \n[6]Gray \n[7]Cyan \n[8]Magenta\n";
    cout << "Enter your chioce :"; 
    while (!(cin >> yourcol)) { //check if your colour number is integer only
        cout << "Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (yourcol < 0 || yourcol > 9) { //check if it in range
        cout << "Invalid choice. Please enter a number from 1 to 8: ";
        while (!(cin >> yourcol)) {
        cout << "Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    if (yourcol == 1){ //white
        red = 255 ; blue = 255 ; green = 255 ;
    }
    else if (yourcol == 2){ //black
        red = 0 ; blue = 0 ; green = 0 ;
    }
    else if (yourcol == 3){ //red
        red = 255 ; blue = 0 ; green = 0 ;
    }
    else if (yourcol == 4){ //green
        red = 0 ; blue = 0 ; green = 255 ;
    }
    else if (yourcol == 5){ // blue
        red = 0 ; blue = 255 ; green = 0 ;
    }
    else if (yourcol == 6){ // gray
        red = 150 ; blue = 150 ; green = 150 ;
    }
    else if (yourcol == 7){ //cyan
        red = 0 ; blue = 255 ; green = 255 ;
    }
    else if (yourcol == 8){ //magenta
        red = 255 ; blue = 0 ; green = 255 ;
    }
    if (yourfram == 1) {//simple frame
        Image image(name);
        int x = (image.height  + image.width )* 0.009111 ;//percentage of size of frame depend on size of image
        Image image2 (image.width + x,image.height +  x) ; // new image with same size + size of frame
        for (int i = x; i < image2.width - x ; ++i) {
            for (int j = x; j < image2.height - x ; ++j) {
                for (int k = 0 ; k < 3 ; ++k){
                    image2(i, j, k) = image(i - x , j - x , k); // put image in the new image
                }
            }
        }
        for (int i = 0; i < image2.width; ++i) {
            for (int j = 0; j < image2.height  ; ++j){ //that is for put frame around the image
                    if (i < x || i > image2.width - x   || j < x || j >  image2.height - x ){
                    image2(i, j, 0) = red;
                    image2(i, j, 1) = green;
                    image2(i, j, 2) = blue;
                }
            } 
        }
        image2.saveImage(name); //save
        cout<<"Done\n"; // done message
    }
    else if (yourfram == 2) { //fancy frame
         Image image(name);
        int x = (image.height  + image.width )* 0.009111 ;
        int y = x * 0.5 ; // virables depend on size of frame to determine the size of fancy depend on size of image
        int z = x * 0.75 ;
        int c = x * 0.25 ;
        Image image2 (image.width + x,image.height +  x) ;
        for (int i = x; i < image2.width - x ; ++i) {
            for (int j = x; j < image2.height - x ; ++j) {
                for (int k = 0 ; k < 3 ; ++k){
                    image2(i, j, k) = image(i - x , j - x , k); //put image in its palace
                }
                if ((i > x && i < x + c) || (j > x  && j < x+c)||(i > image2.width-x-c && i < image2.width-x) || (j > image2.height-x-c && j < image2.height-x)){
                    image2(i, j, 0) = 255; //put fancy one
                    image2(i, j, 1) = 255;
                    image2(i, j, 2) = 255;
                }
                else if ((i > x+ y && i < x+z) || (j > x+ y && j < x+z)||(i > image2.width-x-z && i < image2.width-x-y) || (j > image2.height-x-z && j < image2.height-x-y)){
                    image2(i, j, 0) = 255; //put fancy 2 on the orginial frame
                    image2(i, j, 1) = 255;
                    image2(i, j, 2) = 255;
                }
                
            }
        }
                for (int i = 0; i < image2.width; ++i) {
                    for (int j = 0; j < image2.height  ; ++j){
                        if (i < x || i > image2.width - x   || j < x || j >  image2.height - x ){
                        image2(i, j, 0) = red;   // put simple frame
                        image2(i, j, 1) = green;
                        image2(i, j, 2) = blue;
                        }
                    } 
                }
        image2.saveImage(name); //save
        cout<<"Done\n"; // done message
    }
}

void blur(string name) {
    Image image(name);
    //note take much time to process
    Image blurima(image.width, image.height); //new image to put in it blurred image
    int radius = 10; // const value of raduis for reduce time run

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int totalRed = 0, totalGreen = 0, totalBlue = 0; // to calculate the average
            int counter = 0; // to divide by it 

            for (int y = -radius; y <= radius; ++y) { //use reduis to get the base pixl
                for (int x = -radius; x <= radius; ++x) {
                    int newX = x + i;
                    int newY = y + j;

                    if (newX >= 0 && newX < image.width && newY >= 0 && newY < image.height) { // sum of pixls must be blured which found around the base pixl
                        totalRed += image(newX, newY, 0);
                        totalGreen += image(newX, newY, 1);
                        totalBlue += image(newX, newY, 2);
                        counter++;
                    }
                }
            }
            // calculate the average
            int avre = totalRed / counter;
            int avgr = totalGreen / counter;
            int avbl = totalBlue / counter;
            //put the average in the correct place
            blurima(i, j, 0) = avre; 
            blurima(i, j, 1) = avgr;
            blurima(i, j, 2) = avbl;
        }
    }

    blurima.saveImage(name); //save
    cout<<"Done\n"; // done message

}

void sunlight (string name){
    Image image(name);
    for(int i=0;i<image.width; i++){
        for(int j=0;j<image.height;j++){
            image(i,j,2) *= 0.7 ; //percentage to make the light sunlight filter
        }
    }
    image.saveImage(name); //save
    cout<<"Done\n"; // done message
}

void purple(string name) {
    Image image(name);
    for(int i=0;i<image.width; i++){
        for(int j=0;j<image.height;j++){
            image (i,j,1) *= 0.76 ;
        }
    }
    image.saveImage(name);// save message
    cout<<"Done\n";
}
// function for resizing images
void rszeimg(string name){
    float W,H; // the dimensions of the new image
    cout<<"enter the dimensions: \n";
    cin>> W >> H;
     while (W < 1 || H < 1) {
        cout<< "Please enter correct dimensions: \n";
        cin >> W >> H ; 
    }
    Image img1(W,H);
    float x;
    float y;
    Image img(name);
    x = img.width/W; 
    y = img.height/H;
    
    for(int i =0; i <W; ++i)
 {
     for(int j=0; j<H; ++j)
  {
   
        for(int k = 0; k < 3; ++k)
    {
        
      img1(i,j,k) = img(round(i*x),round(j*y),k); // resizing the image 
    }
  }
 }
    img1.saveImage(name);// save message
    cout<<"Done\n";// done message
}

void infrared (string name) {
   Image image(name);
    for(int i=0;i<image.width; i++){
        for(int j=0;j<image.height;j++){
            image (i , j , 0 ) =255 ;
            for (int k=1;k<3;k++) {
                image (i , j , k) =255 - image(i,j,k);  // converting image to infrared image
            }
        }
    }
    image.saveImage(name);
    cout<<"Done\n";
}

void whiteblack(string name ) {
    Image image2(name);
    for (int i = 0; i < image2.width; ++i) {
        for (int j = 0; j < image2.height; ++j) {
            unsigned int avg = 0; // declaring the average
            for (int k = 0; k < image2.channels; ++k) {
                avg += image2(i, j, k);
            }
            avg = avg / 3;
            for (int k = 0; k < 3; ++k) {
                image2(i, j, k) = avg; // turning image to grayscale image
            }
            unsigned int hold = 128;
            for (int k = 0; k < image2.channels; ++k) {
                if (avg > hold) {
                    image2(i, j, k) = 255;
                } else {                    // turning image from grayscale to black and white image
                    image2(i, j, k) = 0;
                }
            }
        }
    }
    image2.saveImage(name);// save message
    cout<<"Done\n";// done message
}

void cropimg(string name){
    int x,y; // the index you want to start with 
    cout<<"enter the index: \n";
    cin >> x >> y;
    int W,H; // the dimensions you want 
    cout<<"enter the dimensions: \n";
    cin>> W >> H;
    Image img1(W,H);
    Image img(name);
    if(x<img.width && y<img.height){
    for(int i =0; i <W; ++i)
 {

     for(int j=0; j<H; ++j)
  {
   
        for(int k = 0; k < 3; ++k)
    {
        
      img1(i,j,k) = img(i+x,j+y,k); // cropping the image

    }

  }

 }



}
    img1.saveImage(name);//save message
    
    cout<<"done\n";// done message
   
}

void mergeImgs(string name){
    Image img1(name);
    cout<<"Enter the name of the second image: ";  //second image name to merge
    string second;
    cin>>second;
    int choice;
    Image img2(second);
    while(true){
        cout<<"1- Resize smaller image\n"<<"2- Merge common area \n";
        cin>>choice;
        if(choice==1||choice==2){break;}
    }if(choice==1){  
//incase the first image is larger in scale
        if(img1.width>img2.width){  //function of (Mazen Amr 20230307) with some minor changes
            float W=img1.width;
            float H=img1.height;
            Image resized(W,H);
            float x;
            float y;
            x = img2.width/W;
            y = img2.height/H;
            for(int i =0; i <W; ++i){
                for(int j=0; j<H; ++j){
                    for(int k = 0; k < 3; ++k){
                        resized(i,j,k) = img2(round(i*x),round(j*y),k);
                    }
                }
//merging both images with the second image by taking 50% from each pixel and adding them together
            }for(int i=0;i<resized.width;i++){
                for (int j=0;j<resized.height;j++){
                    for (int k=0 ;k<3;k++){
                        resized(i,j,k)*=0.5;
                        resized(i,j,k)+=0.5 *img1(i,j,k);
                    }
                }
            }resized.saveImage(name);  //save new image
            cout<<"Done!\n";
//incase the second image is larger in scale
        }if(img1.width<img2.width){
            float W=img2.width;
            float H=img2.height;
            Image resized(W,H);
            float x;
            float y;
            x = img1.width/W;
            y = img1.height/H;
            for(int i =0; i <W; ++i){
                for(int j=0; j<H; ++j){
                    for(int k = 0; k < 3; ++k){
                        resized(i,j,k) = img1(round(i*x),round(j*y),k);
                    }
                }
//merging both images with the second image by taking 50% from each pixel and adding them together
            }for(int i=0;i<resized.width;i++){
                for (int j=0;j<resized.height;j++){
                    for (int k=0 ;k<3;k++){
                        resized(i,j,k)*=0.5;
                        resized(i,j,k)+=0.5 *img2(i,j,k);
                    }
                }
            }resized.saveImage(name);
            cout<<"Done!\n";
        }                
    }
    if(choice==2){
//incase the first image is larger in scale
        if(img1.width>img2.width){
//merging both images with the second image by taking 50% from each pixel and adding them together
        for(int i=0;i<img2.width;i++){
            for (int j=0;j<img2.height;j++){
                for (int k=0 ;k<3;k++){
                    img2(i,j,k)*=0.5;
                    img2(i,j,k)+=0.5 *img1(i,j,k);
                }
            }
        }img2.saveImage(name);
        cout<<"Done\n";
//incase both images are equal in scale
    }if(img1.width==img2.width){
        for(int i=0;i<img1.width;i++){
            for(int j=0;j<img1.height;j++){
                for(int k=0;k<3;k++){
                    img1(i,j,k)*=0.5;
                    img1(i,j,k)+=0.5 *img2(i,j,k);
                }
            }
        }img1.saveImage(name);
        cout<<"Done\n";
//incase second image is larger in scale
    }if(img1.width<img2.width){
//merging both images with the second image by taking 50% from each pixel and adding them together
        for(int i=0;i<img1.width;i++){
            for (int j=0;j<img1.height;j++){
                for (int k=0 ;k<3;k++){
                    img1(i,j,k)*=0.5;
                    img1(i,j,k)+=0.5 *img2(i,j,k);
                }
            }
        }img1.saveImage(name);
        cout<<"Done\n";
    }
}
}

void edgeDetection(string name) {
    Image img(name);

    // Convert the image to grayscale
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < img.channels; ++k) {
                avg += img(i, j, k);
            }
            avg = avg / 3;
            for (int k = 0; k < 3; ++k) {
                img(i, j, k) = avg;
            }
        }
    }

    // Robert's Cross kernels
    int rbrtX[2][2] = { { -1, 0 }, { 0, 1 } };  //x kernal
    int rbrtY[2][2] = { { 0, -1 }, { 1, 0 } };  //y kernal

    // Loop through every pixel in the image
    for (int i = 0; i < img.width - 1; ++i) {  
        for (int j = 0; j < img.height - 1; ++j) { 
            int sumx = 0, sumy = 0;
            // Loop through the kernels and multiply the kernel with the neighbore pixels
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    int pxlX = img(i + x, j + y, 0) * rbrtX[x][y];
                    int pxlY = img(i + x, j + y, 0) * rbrtY[x][y];
                    sumx += pxlX;
                    sumy += pxlY;
                }
            }
            // Calculate magnitude using the sum of squares of gradients
            int value = sqrt(sumx * sumx + sumy * sumy);
            // Set every pixel to the magnitude
            for (int k = 0; k < 3; ++k) {
                img(i, j, k) = value;
            }
        }
    }

    // Convert dark pixels to white and bright pixels to black
    for(int i=0;i<img.width;i++){
        for(int j=0;j<img.height;j++){
            for(int k=0;k<3;k++){
                if(img(i,j,k)<50){
                    img(i,j,k)=255;
                }else if(img(i,j,k)>205){
                    img(i,j,k)=0;
                }
            }
        }
    }

    img.saveImage(name);  // Save the new image
    cout << "Done\n";
}

void DarkerBrighter(string name){
    Image img(name);
    string new_image;
    Image newImg(img.width,img.height);
for(int i=0;i<img.width;i++){
    for(int j=0;j<img.height;j++){
        for(int k=0;k<3;k++){
            newImg(i,j,k)=img(i,j,k);
        }
    }
}
    cout<<"Please select a choice: \n"<<"1-Darker\n"<<"2-Brighter\n";
    int choice;
    cin>>choice;
    if(choice==1){
        for(int i=0;i<img.width;i++){
        for (int j=0;j<img.height;j++){
            for (int k=0 ;k<3;k++){
                newImg(i,j,k)=0.5 *img(i,j,k); //decrease brightness by 50%
            }
        }
    }
    }
    if (choice == 2) {
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            for (int k = 0; k < 3; k++) {
                int brighter=img(i,j,k)*1.5; //incease brightness by 50%
                if(brighter>255){ //incase the pixel value is more than 255 make it 255
                    brighter=255;
                }else if(brighter<0){ //incase the pixel value is less than 0 make it 0
                    brighter=0;
                }newImg.setPixel(i,j,k,brighter); //set every pixel to the new value
            }
        }
    }
} newImg.saveImage(name);
cout<<"Done\n";
}

void grayscaling(string name){   // Function to convert a color image to grayscale
    Image img(name);
    Image newImg(img.width,img.height);
// Loop over all pixels in the image
    for(int i=0;i<img.width; i++){
        for(int j=0;j<img.height;j++){
            unsigned int average=0;
            for (int k=0;k<3;k++) {
//get the average pixel value
                average+=img(i,j,k);
            }
            average=average/3;
//set the components of each pixel to the average value
            newImg.setPixel(i,j,0,average);
            newImg.setPixel(i,j,1,average);
            newImg.setPixel(i,j,2,average);
        }
//Save the new image with the new name
    }
    newImg.saveImage(name);
    cout<<"Done\n";
}

void menu(string name) {  //menu to choose filter from
    int choice;
    bool exit=false;
    cout << "Select a Filter: \n"
         << "1- GrayScaling\n"
         << "2- Merging Images\n"
         << "3- Invert Image\n"
         << "4- Crop Image\n"
         << "5- White & Black Image\n"
         << "6- Purple Image\n"
         << "7- Natural Sunlight Image\n"
         << "8- Infrared Image\n"
         << "9- Rotate Image\n"
         << "10- Blur Image\n"
         << "11- Frame for Image\n"
         << "12- Resize Image\n"
         << "13- Edge detection\n"
         << "14- Darker or Brighter \n"
         << "15- Flip image \n";
         
    cout << "Choose your filter : ";
    while (!(cin >> choice)) {  //to check if input ia valid or not
        cout << "Pls enter an integer number : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (choice < 0 || choice > 16) {
        cout << "Pls enter your valid filter choice: ";
        while (!(cin >> choice)) {
            cout << "Pls enter an integer number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    switch (choice) {
        case 1:
            grayscaling (name) ;
            break;
        case 2: {
            mergeImgs(name);
            break;
        }
        case 3:
            invert (name) ;
            break;
        case 4:
            cropimg (name) ;
            break;
        case 5:
            whiteblack (name);
            break;
        case 6:
            purple (name);
            break;
        case 7:
            sunlight (name);
            break;
        case 8:
            infrared (name);
            break;
        case 9:
            rotate (name) ;  
            break;
        case 10:
            blur (name );
            break;
        case 11:
            frame (name );
            break;
        case 12:
            rszeimg (name);
            break;
        case 13:
            edgeDetection (name);
            break;
        case 14:
            DarkerBrighter(name);
            break;
        case 15:
            flip(name);
            break; 
        }

}
int choice;

int imgloading(string name){  //menu to make user choose between loading an image or using the old one
    Image image(name);
    cout<<"1- Continue with the same image \n"<<"2- Load a new Image \n"<<"3- Save the Image and exit\n";
    cin>>choice;
    if(choice==1){  
        menu(name);
    }if(choice==2){
        string tempname,newname;
        cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";  //to save the old image with filters
        cin>>newname;
        image.saveImage(newname);
        cout << "Enter the name of the image with its extension ex.(imgname.ext): ";
        cin>>tempname;
        Image temp(tempname);  
        temp.saveImage(name);
        menu(name);
    }if(choice==3){
        Image img(name);
        string newname;
        cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
        cin>>newname;
        cout<<"Thanks for using our program.";
        img.saveImage(newname);
    }return choice;
}

int main(){
    string name;
    cout<<"-------- Welcome to photoshop --------\n";
    cout << "Enter the name of the image with its extension ex.(imgname.ext): ";
    cin>>name;
    Image temp(name);  //to return the old values to the input image
    while(true){
        imgloading(name);
        if(choice==3){
            temp.saveImage(name);
            return 0;
        }
    }
}
