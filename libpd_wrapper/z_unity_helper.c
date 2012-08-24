#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "s_stuff.h"
#include "z_libpd.h"

static const int switchOnOffLength = 11;
static char switchOnOffName[switchOnOffLength]; //"/****onoff\0"
static const char *switchOnOffFormat = "/%donoff"; 

int libpd_process_patch(int ticks, float *inBuffer, float *outBuffer, int dz) {
  //Get switch name
  snprintf(switchOnOffName, switchOnOffLength, switchOnOffFormat, dz);
  //Turn on patch
  libpd_float(switchOnOffName, 1f);
  //Process patch
  libpd_process_float(ticks,inBuffer,outBuffer);
  //Turf off patch
  libpd_float(switchOnOffName, 0f);
  //Reset string
  memset(switchOnOffName, '\0', switchOnOffLength*sizeof(char))
  return 0;
}

int libpd_process_patches(int ticks, float *inBuffer, float *outBuffer, int *dzs, int length) {
  for(int i=0;i<length;i++){
  	//Get switch name
	  snprintf(switchOnOffName, switchOnOffLength, switchOnOffFormat, dzs[i]);
	  //Turn on patch
	  libpd_float(switchOnOffName, 1f);
	  memset(switchOnOffName, '\0', switchOnOffLength*sizeof(char))
  }
  //Process patches
  libpd_process_float(ticks,inBuffer,outBuffer);
  for(int i=0;i<length;i++){
    //Get switch name
	  snprintf(switchOnOffName, switchOnOffLength, switchOnOffFormat, dzs[i]);
	  //Turn on patch
	  libpd_float(switchOnOffName, 0f);
	  memset(switchOnOffName, '\0', switchOnOffLength*sizeof(char))
  }
  return 0;
}