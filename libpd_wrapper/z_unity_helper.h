#ifndef __Z_UNITY_HELPER_H__
#define __Z_UNITY_HELPER_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "z_libpd.h"

EXTERN int libpd_process_patch(int ticks, float *inBuffer, float *outBuffer, int dz);
EXTERN int libpd_process_patches(int ticks, float *inBuffer, float *outBuffer, int *dzs, int length);

#ifdef __cplusplus
}
#endif

#endif
