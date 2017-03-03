#include "cppimage.h"

cppimage::cppimage(): nb_row(0), nb_col(0)
{
}

cppimage::cppimage(size_t nbrow, size_t nbcol, int init_val): nb_row(nbrow), nb_col(nbcol)
{
  this->set_nbelt();
  this->image_array.resize(this->get_nbelt(),init_val);
}


cppimage::~cppimage()
{
}

void cppimage::set_nbelt()
{ 
  this->nb_elt = this->nb_row * this->nb_col; 
}

void cppimage::set_nbrow(size_t nbrow)
{
  this->nb_row =  nbrow;
  this->set_nbelt();
}

void cppimage::set_nbcol(size_t nbcol)
{
  this->nb_col = nbcol;
  this->set_nbelt();
}


void cppimage::init_empty_image() 
{
  this->image_array.resize(this->nb_elt,0);
}

size_t cppimage::get_nbrow() const
{
  return this->nb_row;
}

size_t cppimage::get_nbcol() const
{
  return this->nb_col;
}

size_t cppimage::get_nbelt() const
{
  return this->nb_elt;
}

int cppimage::get_kl_value(size_t idx_row, size_t idx_col) const
{
  return this->image_array[idx_row*this->nb_col + idx_col];
}


int cppimage::get_kl_value(pixel_type pixel) const
{
  return this->get_kl_value(pixel.first, pixel.second);
}

void cppimage::set_kl_value(size_t idx_row, size_t idx_col, int value)
{
  this->image_array[idx_row*this->nb_col + idx_col] = value;
}

void cppimage::set_kl_value(pixel_type pixel, int value)
{
  this->set_kl_value(pixel.first, pixel.second, value);
}

void cppimage::display_image_tab() const
{
  for(size_t kk=0; kk < this->nb_row; ++kk)
    {
      for(size_t ll=0; ll < this->nb_col; ++ll)
	{
	  std::cout<<this->get_kl_value(kk,ll)<< " " ;
	}
      std::cout<<std::endl;
    }
}

const std::vector<int> & cppimage::get_image_array() const
{
  return this->image_array;
}

 
