#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{
  Bitmap image;
  string filename;
  if(argc!=2)
  {
    cout<<"Please specify one image file!\n";
  }
  else
  {
    filename = argv[1];
    image.open(filename);
    if(image.isImage())
    {
        vector <vector <Pixel> > imagePixels = image.toPixelMatrix();
        for(int i=0;i<imagePixels.size();i++)
        {
            for(int j=0;j<imagePixels[1].size();j++)
            {
                Pixel color = imagePixels[i][j];
                color.green = 0;
                color.blue = 0;
                imagePixels[i][j] = color;
            }
        }
        image.fromPixelMatrix( imagePixels );
        image.save("redness.bmp");
        cout<<filename<<" is "<<imagePixels.size()<<" pixels high and "<<imagePixels[1].size()<<" pixels wide"<<endl;

    }
    else
    {
        cout<<"Image file must be a bitmap with 24-bit color depth.\n";
    }
  }
  return 0;
}
