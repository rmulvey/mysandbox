/*----------------------------------------------------------------------------
 * File:  CSOListener.c
 *
 * UML Component Port Messages
 * Component/Module Name:  CSOListener
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "CSOClientListener_sys_types.h"
#include "CSOListener.h"
#include "CSOListener_classes.h"

/*
 * Interface:  connection
 * Required Port:  Port1
 * To Provider Message:  connect
 */
void
CSOListener_Port1_connect()
{
}

/*
 * Interface:  connection
 * Required Port:  Port1
 * To Provider Message:  disconnect
 */
void
CSOListener_Port1_disconnect()
{
}
/*
 * UML Domain Functions (Synchronous Services)
 */

/* xtUML class info (collections, sizes, etc.) */
Escher_Extent_t * const CSOListener_class_info[ CSOListener_MAX_CLASS_NUMBERS ] = {
  &pG_CSOListener_CSOConnection_extent
};

/*
 * Array of pointers to the class event dispatcher method.
 * Index is the (model compiler enumerated) number of the state model.
 */
const EventTaker_t CSOListener_EventDispatcher[ CSOListener_STATE_MODELS ] = {
  CSOListener_class_dispatchers
};

void CSOListener_execute_initialization()
{
}
