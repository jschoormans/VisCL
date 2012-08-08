/*ckwg +5
 * Copyright 2012 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#include <viscl/core/manager.h>


int main(int argc, char *argv[])
{
  viscl::manager::inst()->report_opencl_specs();

  return 0;
}
