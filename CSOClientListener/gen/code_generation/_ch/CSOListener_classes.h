/*----------------------------------------------------------------------------
 * File:  CSOListener_classes.h
 *
 * This file defines the object type identification numbers for all classes
 * in the component:  CSOListener
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef CSOLISTENER_CLASSES_H
#define CSOLISTENER_CLASSES_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Initialization services for component:  CSOListener
 */
extern Escher_Extent_t * const CSOListener_class_info[];
extern const EventTaker_t CSOListener_EventDispatcher[];
void CSOListener_execute_initialization( void );

#define CSOListener_STATE_MODELS 1
/* Define constants to map to class numbers.  */
#define CSOListener_CSOConnection_CLASS_NUMBER 0
#define CSOListener_MAX_CLASS_NUMBERS 1

/* Provide a map of classes to task numbers.  */
#define CSOListener_TASK_NUMBERS  0

#define CSOListener_class_dispatchers\
  CSOListener_CSOConnection_Dispatch

/* Provide definitions of the shapes of the class structures.  */

typedef struct CSOListener_CSOConnection CSOListener_CSOConnection;

/* union of class declarations so we may derive largest class size */
#define CSOListener_CLASS_U \
  char CSOListener_dummy;\


#include "CSOListener.h"
#include "CSOListener_CSOConnection_class.h"
#ifdef	__cplusplus
}
#endif
#endif  /* CSOLISTENER_CLASSES_H */
