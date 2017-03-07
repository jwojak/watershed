#include "cppimage.h"
#include "vincent_soille_watershed.h"

int main(void)
{
  cppimage mon_image;
  vincent_soille_watershed vsw;

  size_t nbrow = 4;
  size_t nbcol = 4;
  int cpt = 100;
  
  mon_image.set_nbrow(nbrow);
  mon_image.set_nbcol(nbcol);
  mon_image.init_empty_image();
  mon_image.display_image_tab();
  std::cout<<"--------"<<std::endl;


  /*for(size_t kk=0; kk<nbrow ; ++kk)
    {
      for(size_t ll=0; ll<nbcol;++ll)
	{
	  mon_image.set_kl_value(kk,ll,cpt);
	}
      cpt--;
      }*/
  mon_image.set_kl_value(0,0,1);
  mon_image.set_kl_value(0,1,2);
  mon_image.set_kl_value(0,2,3);
  mon_image.set_kl_value(0,3,1);

  mon_image.set_kl_value(1,0,1);
  mon_image.set_kl_value(1,1,2);
  mon_image.set_kl_value(1,2,4);
  mon_image.set_kl_value(1,3,2);

  mon_image.set_kl_value(2,0,1);
  mon_image.set_kl_value(2,1,3);
  mon_image.set_kl_value(2,2,5);
  mon_image.set_kl_value(2,3,3);

  mon_image.set_kl_value(3,0,2);
  mon_image.set_kl_value(3,1,6);
  mon_image.set_kl_value(3,2,1);
  mon_image.set_kl_value(3,3,2);

  mon_image.display_image_tab();
  //  mon_image.process_watershed_algo();
  vsw.process_watershed_algo(mon_image);

  return 0;
}
