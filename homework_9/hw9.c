/*******************************************
 * NAME: Sreelakshmi Kutty
 *
 * COURSE: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DUE DATE: 1 May 2020
 *
 * FILE: homework9
 *
 * DESCRIPTION: contains convert funtion
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "hw9.h"
#include <jni.h>

/**********************************
 * Function: convert
 *
 * Description: converts in to cm
 *
 * Parameters: double (ins)
 *
 * Return: double (cm)
 **********************************/
 
JNIEXPORT jdouble JNICALL Java_hw9_convert(JNIEnv *env, jobject obj, jdouble inches)
{
    return (inches * 2.54);
}



