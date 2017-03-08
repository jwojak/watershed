/*!
 *  \file watershed_matlab.cpp
 * \brief a cpp interface to use the vincent_soille_watershed class (in libwatershed.so)
 * \author jwojak
 */

#include "mex.h"
#include "cppimage.h"
#include "vincent_soille_watershed.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  size_t  nb_row=0, nb_col=0;
  double *input_image;
  double *output_image;
  double *connectivity;
  vincent_soille_watershed vsw;
  
  if(nrhs<1)
    {
      mexPrintf(" watershed_matlab mex not enough input arg");
      return;
    }
  
  mexPrintf("number of input args  %d \n", nrhs);

  nb_row = mxGetN(prhs[0]);
  nb_col = mxGetM(prhs[0]);
  mexPrintf("input image size  [%d, %d] \n", nb_row, nb_col);
  
  input_image = mxGetPr(prhs[0]);

  if(nrhs>=2)
    {
      connectivity = mxGetPr(prhs[1]);
    }
  else 
    {
      connectivity =(double *)mxMalloc(sizeof(double))  ;
      connectivity[0] = 4.0;
    }

  cppimage input_watershed_image(nb_row, nb_col, input_image);
  //input_watershed_image.display_image_tab();
  

  vsw.process_watershed_algo(input_watershed_image, (int)connectivity[0]);
  //mexPrintf("ON FAIT LA SAUVEGARDE %d \n" ,nb_row*nb_col);
  output_image = (double *)mxMalloc( (nb_row*nb_col)*sizeof(double));
  vsw.get_labelled_array(output_image);

  plhs[0] = mxCreateNumericMatrix(0, 0, mxDOUBLE_CLASS, mxREAL);
  mxSetPr(plhs[0], output_image);
  mxSetN(plhs[0], nb_row);
  mxSetM(plhs[0], nb_col);
  /* nb_col = mxGetN(prhs[1]);
  
  std::cout<<"input image size = [" << nb_row << ", " << nb_col <<"]" << std::endl;*/
  if(nrhs < 2)
    {
      mxFree(connectivity);
    }

  return;
}
