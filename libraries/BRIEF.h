#ifndef BRIEF_H_
#define BRIEF_H_

#include "cl_task.h"
#include "cl_image.h"
#include "cl_buffer.h"

#include <vil/vil_image_view.h>

template<int radius>
class brief : public cl_task
{
public:
  
  typedef boost::shared_ptr<brief<radius> > type;
  
  cl_task_t clone();

  template<class T>
  void compute_descriptors(const vil_image_view<T> &img, const vcl_vector<cl_int2> &kpts, vcl_vector<cl_int4> &descriptors, float sigma);
  template<class T>
  void compute_descriptors(const vil_image_view<T> &img, const vcl_vector<cl_int2> &kpts, vcl_vector<cl_int4> &descriptors);
  void compute_descriptors(const cl_image &img_s, const cl_buffer &kpts, size_t numkpts, cl_buffer &descriptors);

private:

  friend class cl_task_registry;
  brief();

  vcl_string generate_meta_source(const vcl_string &source);

  
  cl_kernel_t brief_k, brief_dist_k;
  cl_queue_t queue;
};



#endif