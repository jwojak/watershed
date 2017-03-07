#ifndef ___VINCENT_SOILLE_WATERSHED___
#define ___VINCENT_SOILLE_WATERSHED___

#include "cppimage.h"
#include <algorithm>
#include <queue> 

typedef std::multimap< int, pixel_type  > graph_type;

class vincent_soille_watershed
{
 public:
  vincent_soille_watershed();
  ~vincent_soille_watershed();

  void process_watershed_algo(const cppimage &input_im);
  // for matlab output
  void get_labelled_array(double *lab_out_for_matlab);

 private:
  cppimage lab_w;
  graph_type image_graph;
  std::queue< pixel_type > fifo;
  void populate_graph_from_array( const cppimage &input_image, graph_type &output_graph );
  void display_graph(const graph_type &i_graph) const;
  void populate_array_from_graph();
  std::vector< pixel_type > get_neighbors_list(const cppimage &input_image, pixel_type input_pixel, int neighborhood_size );
  
};
#endif
