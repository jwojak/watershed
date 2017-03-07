#ifndef ___CPPIMAGE___
#define ___CPPIMAGE___

#include <vector>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <map>

typedef std::pair< size_t, size_t > pixel_type;

class cppimage
{
 public:
  // constructors
  cppimage();
  cppimage(size_t nbrow, size_t nbcol, int init_val);
  // special constructor for matlab mex interface
  cppimage(size_t nbrow, size_t nbcol,  double *init_array);

  // destructor;
  ~cppimage();

  size_t get_nbrow() const;
  size_t get_nbcol() const;
  size_t get_nbelt() const;
  void set_nbrow(size_t nbrow);
  void set_nbcol(size_t nbcol);

  int get_kl_value(size_t idx_row, size_t idx_col) const;
  int get_kl_value(pixel_type pixel) const;

  void set_kl_value(size_t idx_row, size_t idx_col, int value);
  void set_kl_value(pixel_type pixel, int value);

  int get_im_min() const;
  int get_im_max() const;

  void init_empty_image();
  void display_image_tab() const;
  const std::vector<int> & get_image_array() const;
  
  

 private:
  size_t nb_row;
  size_t nb_col;
  size_t nb_elt;
  std::vector< int > image_array; // assume that the image is quantified before

  void set_nbelt();
 

};

#endif
