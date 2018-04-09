#ifndef __SCULL1_H
#define __SCULL1_H


//Number of SCULL devices
#ifndef SCULL_COUNT
#define SCULL_COUNT 4
#endif

//Name of the SCULL DRIVER
#ifndef SCULL_NAME
#define SCULL_NAME "scull"
#endif

//First MINOR NUMBER
#ifndef SCULL_MINOR_START
#define SCULL_MINOR_START 0

//SCULL MAJOR NUMBER(Set to 0 for dynamic allocation)
#ifndef SCULL_MAJOR
#define SCULL_MAJOR 0
