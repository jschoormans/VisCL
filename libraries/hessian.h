#ifndef HESSIAN_H_
#define HESSIAN_H_

#include "cl_task.h"
#include "cl_image.h"
#include "cl_buffer.h"

#include <vil/vil_image_view.h>

class hessian : public cl_task
{
public:

  cl_task_t clone();

  template <class T>
  void detect(const vil_image_view<T> &img, int max_kpts, float thresh, float sigma, vcl_vector<cl_int2> &kpts) const;
  void smooth_and_detect(const cl_image &img, cl_image &kptmap, cl_buffer &kpts, cl_buffer &numkpts,
                         int max_kpts, float thresh, float sigma) const;
  void detect(const cl_image &img, cl_image &kptmap, cl_buffer &kpts, cl_buffer &numkpts,
             int max_kpts, float thresh, float scale) const;

  int num_kpts(const cl_buffer &numkpts_b);

private:

  //This makes it so only the task registry can compile the .cl code
  friend class cl_task_registry;
  hessian();

  cl_kernel_t det_hessian, detect_extrema, init_kpt_map;
  cl_queue_t queue;
};

typedef boost::shared_ptr<hessian> hessian_t;

#endif