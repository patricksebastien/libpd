#include "z_unity_helper.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define SWITCHONOFFLENGTH 10
static char switchOnOffName[SWITCHONOFFLENGTH] = ""; //"****onoff\0"
static const char *switchOnOffFormat = "%donoff"; 

int libpd_process_patch(int ticks, float *inBuffer, float *outBuffer, int dz) {
  //Get switch name
  snprintf(switchOnOffName, SWITCHONOFFLENGTH, switchOnOffFormat, dz);
  //Turn on patch
  libpd_float(switchOnOffName, 1);
  //Process patch
  libpd_process_float(ticks,inBuffer,outBuffer);
  //Turf off patch
  libpd_float(switchOnOffName, 0);
  return 0;
}

int libpd_process_patches(int ticks, float *inBuffer, float *outBuffer, int *dzs, int length) {
  int i;
  for(i=0;i<length;i++){
  	//Get switch name
	  snprintf(switchOnOffName, SWITCHONOFFLENGTH, switchOnOffFormat, dzs[i]);
	  //Turn on patch
	  libpd_float(switchOnOffName, 1);
  }
  //Process patches
  libpd_process_float(ticks,inBuffer,outBuffer);
  for(i=0;i<length;i++){
    //Get switch name
	  snprintf(switchOnOffName, SWITCHONOFFLENGTH, switchOnOffFormat, dzs[i]);
	  //Turn on patch
	  libpd_float(switchOnOffName, 0);
  }
  return 0;
}